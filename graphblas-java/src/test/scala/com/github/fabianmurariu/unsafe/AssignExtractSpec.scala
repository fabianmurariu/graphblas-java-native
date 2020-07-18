package com.github.fabianmurariu.unsafe

import java.nio.Buffer

import org.scalacheck.Arbitrary
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

import scala.collection.immutable
import scala.reflect.ClassTag

trait AssignExtractSpec {

  self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers =>

  behavior of "GrB_extract"

  testGrBExtract[Boolean]
  testGrBExtract[Byte]
  testGrBExtract[Short]
  testGrBExtract[Int]
  testGrBExtract[Long]
  testGrBExtract[Float]
  testGrBExtract[Double]

  private def testGrBExtract[T: SparseMatrixHandler](implicit A: Arbitrary[MatrixTuples[T]], CT: ClassTag[T]): Unit = {
    it should s"call GrB_extract for GrB_Matrix of type ${CT.toString()}" in forAll { mt: MatrixTuples[T] =>
      val mat = SparseMatrixHandler[T].buildMatrix(mt)

      GRBCORE.nvalsMatrix(mat)
      // pick half of the indices and extract them into another mat
      val (_, right) = mt.vals.splitAt(mt.vals.size / 2)
      val dRight = right.distinctBy(t => t._1 -> t._2)
      val ni: Vector[Long] = dRight.map(_._1)
      val nj: Vector[Long] = dRight.map(_._2)

      val into = SparseMatrixHandler[T].createMatrix(ni.size, nj.size)

      val res = GRBOPSMAT.extract(into, null, null, mat, ni.toArray, ni.size, nj.toArray, nj.size, null)
      assert(res == 0)

      val expected: immutable.IndexedSeq[T] = (for {
        i <- ni.indices
        j <- nj.indices
      } yield SparseMatrixHandler[T].get(mat)(ni(i), nj(j))).flatten

      SparseMatrixHandler[T].extractTuples(into) should contain theSameElementsAs expected
    }
  }

}
