package com.github.fabianmurariu.unsafe

import org.scalacheck.Arbitrary
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

import scala.reflect.ClassTag

trait ElemWiseSpec {

  self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers =>

  behavior of "GrB_eWise*_Matrix"

  eWiseMult[Byte]
  eWiseMult[Short]
  eWiseMult[Int]
  eWiseMult[Long]
  eWiseMult[Float]
  eWiseMult[Double]

  def eWiseMult[T: SparseMatrixHandler: MonoidHandler:BinaryOpHandler](implicit A:Arbitrary[MatrixTuplesMul[T]], N: Numeric[T], CT: ClassTag[T]): Unit = {
    it should s"apply plus(A, B) for the intersection of all items on type ${CT.toString()}" in forAll { mt: MatrixTuplesMul[T] =>

      val a = SparseMatrixHandler[T].buildMatrix(mt.left)
      val b = SparseMatrixHandler[T].buildMatrix(mt.right)

      val c1 = SparseMatrixHandler[T].createMatrix(mt.left.dim.rows, mt.left.dim.cols)
      val c2 = SparseMatrixHandler[T].createMatrix(mt.left.dim.rows, mt.left.dim.cols)

      val m = MonoidHandler[T].plus
      val op = BinaryOpHandler[T].plus

      val d = GRBCORE.createDescriptor()
      GRBCORE.setDescriptorValue(d, GRBCORE.GrB_INP1, GRBCORE.GrB_TRAN)

      val ret1 = GRBOPSMAT.elemWiseMulIntersectMonoid(c1, null, null, m, a, b, d)
      val ret2 = GRBOPSMAT.elemWiseMulIntersectBinOp(c2, null, null, op, a, b, d)

      ret1 shouldBe GRBCORE.GrB_SUCCESS
      ret2 shouldBe GRBCORE.GrB_SUCCESS
    }

    it should s"apply plus(A, B) for the union of all items on type ${CT.toString()}" in forAll { mt: MatrixTuplesMul[T] =>

      val a = SparseMatrixHandler[T].buildMatrix(mt.left)
      val b = SparseMatrixHandler[T].buildMatrix(mt.right)

      val c1 = SparseMatrixHandler[T].createMatrix(mt.left.dim.rows, mt.left.dim.cols)
      val c2 = SparseMatrixHandler[T].createMatrix(mt.left.dim.rows, mt.left.dim.cols)

      val m = MonoidHandler[T].plus
      val op = BinaryOpHandler[T].plus

      val d = GRBCORE.createDescriptor()
      GRBCORE.setDescriptorValue(d, GRBCORE.GrB_INP1, GRBCORE.GrB_TRAN)

      val ret1 = GRBOPSMAT.elemWiseAddUnionMonoid(c1, null, null, m, a, b, d)
      val ret2 = GRBOPSMAT.elemWiseAddUnionBinOp(c2, null, null, op, a, b, d)

      ret1 shouldBe GRBCORE.GrB_SUCCESS
      ret2 shouldBe GRBCORE.GrB_SUCCESS
    }
  }
}
