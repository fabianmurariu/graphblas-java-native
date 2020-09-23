package com.github.fabianmurariu.unsafe

import java.nio.Buffer

import org.scalacheck.Arbitrary
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

import scala.reflect.ClassTag

trait SelectSpec {
  self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers =>

  behavior of "GrB_Matrix_select"

  testMatrixSelect[Boolean]

  private def testMatrixSelect[T: SparseMatrixHandler](implicit A:Arbitrary[MatrixTuples[T]], CT: ClassTag[T]): Unit = {
    it should s"call GrB_select for GrB_Matrix of type ${CT.toString()}" in forAll { mt: MatrixTuples[T] =>
      val mat = SparseMatrixHandler[T].buildMatrix(mt)
      val out = SparseMatrixHandler[T].createMatrix(mt.dim.rows, mt.dim.cols)

      val selectOp = GRAPHBLAS.selectOpDIAG()
      GRBOPSMAT.select(out, null, null, selectOp, mat, null, null) shouldBe GRBCORE.GrB_SUCCESS

      // check could be improved
      val actual = SparseMatrixHandler[T].extractAllTuples(out)
      val expected = mt.vals.filter(p => (p._1 == p._2))
      actual should contain theSameElementsAs expected
    }
  }
}
