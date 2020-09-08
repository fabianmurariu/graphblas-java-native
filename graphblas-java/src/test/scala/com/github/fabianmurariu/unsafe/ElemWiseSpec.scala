package com.github.fabianmurariu.unsafe

import org.scalacheck.Arbitrary
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

import scala.reflect.ClassTag

trait ElemWiseSpec {

  self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers =>

  behavior of "GrB_eWise*_Matrix"

  eWiseMultMatrix[Byte]
  eWiseMultMatrix[Short]
  eWiseMultMatrix[Int]
  eWiseMultMatrix[Long]
  eWiseMultMatrix[Float]
  eWiseMultMatrix[Double]

  def eWiseMultMatrix[T: SparseMatrixHandler : MonoidHandler : BinaryOpHandler](implicit A: Arbitrary[MatrixTuplesMul[T]], N: Numeric[T], CT: ClassTag[T]): Unit = {
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


  behavior of "GrB_eWise*_Vector"

  eWiseMultVector[Byte]
  eWiseMultVector[Short]
  eWiseMultVector[Int]
  eWiseMultVector[Long]
  eWiseMultVector[Float]
  eWiseMultVector[Double]

  def eWiseMultVector[T: SparseVectorHandler : MonoidHandler : BinaryOpHandler](implicit A: Arbitrary[VectorValsMul[T]], N: Numeric[T], CT: ClassTag[T]): Unit = {
    it should s"apply plus(A, B) for the intersection of all items on type ${CT.toString()}" in forAll { mt: VectorValsMul[T] =>

      val a = SparseVectorHandler[T].buildVector(mt.left)
      val b = SparseVectorHandler[T].buildVector(mt.right)

      val expectedSize = mt.left.vals.map(_._1).intersect(mt.right.vals.map(_._1)).size

      val c1 = SparseVectorHandler[T].createVector(mt.left.size)
      val c2 = SparseVectorHandler[T].createVector(mt.left.size)

      val m = MonoidHandler[T].plus
      val op = BinaryOpHandler[T].plus

      GRBOPSVEC.elemWiseMulIntersectMonoid(c1, null, null, m, a, b, null) shouldBe GRBCORE.GrB_SUCCESS
      GRBOPSVEC.elemWiseMulIntersectBinOp(c2, null, null, op, a, b, null) shouldBe GRBCORE.GrB_SUCCESS

      GRBCORE.nvalsVector(c1) shouldBe expectedSize
      GRBCORE.nvalsVector(c2) shouldBe expectedSize
    }

    it should s"apply plus(A, B) for the union of all items on type ${CT.toString()}" in forAll { mt: VectorValsMul[T] =>

      val a = SparseVectorHandler[T].buildVector(mt.left)
      val b = SparseVectorHandler[T].buildVector(mt.right)

      val expectedSize = mt.left.vals.map(_._1).union(mt.right.vals.map(_._1)).toSet.size

      val c1 = SparseVectorHandler[T].createVector(mt.left.size)
      val c2 = SparseVectorHandler[T].createVector(mt.left.size)

      val m = MonoidHandler[T].plus
      val op = BinaryOpHandler[T].plus

      GRBOPSVEC.elemWiseAddUnionMonoid(c1, null, null, m, a, b, null) shouldBe GRBCORE.GrB_SUCCESS
      GRBOPSVEC.elemWiseAddUnionBinOp(c2, null, null, op, a, b, null) shouldBe GRBCORE.GrB_SUCCESS

      GRBCORE.nvalsVector(c1) shouldBe expectedSize
      GRBCORE.nvalsVector(c2) shouldBe expectedSize
    }
  }
}
