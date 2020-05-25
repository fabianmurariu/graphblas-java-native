package com.github.fabianmurariu.unsafe

import org.ejml.data.DMatrixSparseCSC
import org.ejml.sparse.csc.CommonOps_DSCC
import org.scalacheck.Arbitrary
import org.scalatest.BeforeAndAfterAll
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

import scala.reflect.ClassTag

trait MxmSpec { self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers with BeforeAndAfterAll =>

  behavior of "GrB_mxm"
  testMxm[Byte]
  testMxm[Short]
  testMxm[Int]
  testMxm[Long]
  testMxm[Double]
  testMxm[Float]

  def testMxm[T: SparseMatrixHandler : MonoidHandler : BinaryOpHandler](implicit A: Arbitrary[MatrixTuplesMul[T]], CT: ClassTag[T], N: Numeric[T]): Unit = {
    it should s"multiply a matrix with another matrix under the usual *+ semiring on ${CT.toString()}" in forAll { mt: MatrixTuplesMul[T] =>

      val leftX = new DMatrixSparseCSC(mt.left.dim.rows.toInt, mt.left.dim.cols.toInt)
      val rightX = new DMatrixSparseCSC(mt.left.dim.cols.toInt, mt.left.dim.rows.toInt)

      for ((i, j, v) <- mt.left.vals) {
        leftX.set(i.toInt, j.toInt, N.toDouble(v))
      }
      for ((i, j, v) <- mt.right.vals) {
        rightX.set(i.toInt, j.toInt, N.toDouble(v))
      }

      val outX = new DMatrixSparseCSC(mt.left.dim.rows.toInt, mt.right.dim.cols.toInt)
      CommonOps_DSCC.mult(leftX, rightX, outX)

      val left = SparseMatrixHandler[T].buildMatrix(mt.left)
      val right = SparseMatrixHandler[T].buildMatrix(mt.right)

      GRBCORE.nrows(left) shouldBe GRBCORE.ncols(right)
      GRBCORE.ncols(left) shouldBe GRBCORE.nrows(right)

      val out = SparseMatrixHandler[T].createMatrix(mt.left.dim.rows, mt.right.dim.cols)

      val plus = MonoidHandler[T].plus
      val times = BinaryOpHandler[T].times
      val semi = GRBCORE.createSemiring(plus, times)

      val res = GRBOPSMAT.mxm(out, null, null, semi, left, right, null);
      res shouldBe 0
      // ensure all is complete
      GRBCORE.nvalsMatrix(out) shouldBe outX.nz_length

      val tripletIterator = outX.createCoordinateIterator()
      while(tripletIterator.hasNext) {
        val triplet = tripletIterator.next()
        val actual = SparseMatrixHandler[T].get(out)(triplet.row, triplet.col).headOption
        actual should not be None
        val actualD = N.toDouble(actual.get)
        val eps = if (actualD != 0 ) Math.abs(0.1 * actualD) else 0.01
        triplet.value === (actualD +- eps)
      }

      GRBCORE.freeMatrix(left)
      GRBCORE.freeMatrix(out)
      GRBCORE.freeMatrix(right)
      GRBCORE.freeSemiring(semi)
    }
  }
}
