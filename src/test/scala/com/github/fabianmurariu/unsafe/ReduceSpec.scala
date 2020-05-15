package com.github.fabianmurariu.unsafe

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

trait ReduceSpec {

  self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers =>

  behavior of "GrB_Matrix_reduce"

  it should "get the smallest value in a matrix for min" in forAll { mt: MatrixTuples[Int] =>
    val mat = SparseMatrixHandler[Int].buildMatrix(mt)
    val expected: Int = mt.vals.minBy(_._3)._3
    val actual = GRBALG.matrixReduceAllInt(0, null, GRBMONOID.minMonoidInt(), mat, null)
    actual shouldBe expected
  }
}
