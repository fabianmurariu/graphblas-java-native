package com.github.fabianmurariu.unsafe

import org.scalacheck.Arbitrary
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

import scala.reflect.ClassTag

trait AssignScalarSpec {
  self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers =>

  behavior of "GrB_Vector_assign"

  testVectorAssignScalar[Boolean]
  testVectorAssignScalar[Byte]
  testVectorAssignScalar[Short]
  testVectorAssignScalar[Int]
  testVectorAssignScalar[Long]
  testVectorAssignScalar[Float]
  testVectorAssignScalar[Double]

  def testVectorAssignScalar[T: SparseVectorHandler](implicit A: Arbitrary[VectorVals[T]], CT: ClassTag[T]) = {
    it should s"create a vector of type ${CT.toString()}, assign a scalar value" in forAll { mt: VectorVals[T] =>
      val handler = SparseVectorHandler[T]

      val size = 10
      val vec = handler.createVector(size)

      val v = mt.vals.head._2

      v match {
        case b: Boolean => GRAPHBLAS.assignVectorBoolean(vec, null, null, b, null, size, null)
        case b: Byte => GRAPHBLAS.assignVectorByte(vec, null, null, b, null, size, null)
        case b: Short => GRAPHBLAS.assignVectorShort(vec, null, null, b, null, size, null)
        case b: Int => GRAPHBLAS.assignVectorInt(vec, null, null, b, null, size, null)
        case b: Long => GRAPHBLAS.assignVectorLong(vec, null, null, b, null, size, null)
        case b: Float => GRAPHBLAS.assignVectorFloat(vec, null, null, b, null, size, null)
        case b: Double => GRAPHBLAS.assignVectorDouble(vec, null, null, b, null, size, null)
      }

      GRBCORE.nvalsVector(vec) shouldBe size

      for (i <- 0 to size) {
        handler.get(vec)(i).headOption shouldBe Some(v)
      }

      GRBCORE.freeVector(vec)
    }
  }
}
