package com.github.fabianmurariu.unsafe

import org.scalacheck.Arbitrary
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

import scala.reflect.ClassTag

trait RemoveSpec {
  self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers =>

  behavior of "GrB_Matrix_removeElement"

  testRemoveElementFromMatrix[Boolean]
  testRemoveElementFromMatrix[Byte]
  testRemoveElementFromMatrix[Short]
  testRemoveElementFromMatrix[Int]
  testRemoveElementFromMatrix[Long]
  testRemoveElementFromMatrix[Float]
  testRemoveElementFromMatrix[Double]


  behavior of "GrB_Vector_removeElement"

  testRemoveElementFromVector[Boolean]
  testRemoveElementFromVector[Byte]
  testRemoveElementFromVector[Short]
  testRemoveElementFromVector[Int]
  testRemoveElementFromVector[Long]
  testRemoveElementFromVector[Float]
  testRemoveElementFromVector[Double]

  behavior of "GrB_Vector_clear"

  it should s"create a vector, check elements exist, clear the vector then verify they are gone" in forAll { mt: VectorVals[Int] =>
    val handler = SparseVectorHandler[Int]

    val vec = handler.buildVector(mt)

    GRBCORE.nvalsVector(vec) shouldBe mt.vals.size

    handler.clear(vec)

    GRBCORE.nvalsVector(vec) shouldBe 0
  }

  behavior of "GrB_Matrix_clear"

  it should s"create a matrix, check elements exist, clear the matrix then verify they are gone" in forAll { mt: MatrixTuples[Int] =>
    val handler = SparseMatrixHandler[Int]

    val mat = handler.buildMatrix(mt)

    GRBCORE.nvalsMatrix(mat) shouldBe mt.vals.size

    handler.clear(mat)

    GRBCORE.nvalsMatrix(mat) shouldBe 0
  }


  def testRemoveElementFromMatrix[T: SparseMatrixHandler](implicit A: Arbitrary[MatrixTuples[T]], CT: ClassTag[T]) = {
    it should s"create a matrix of type ${CT.toString()}, check elements exist, remove them then verify they are gone" in forAll { mt: MatrixTuples[T] =>
      val handler = SparseMatrixHandler[T]

      val mat = handler.buildMatrix(mt)

      mt.vals.foreach {
        case (i, j, v) =>
          handler.get(mat)(i, j).headOption shouldBe Some(v)

          handler.remove(mat)(i, j)

          handler.get(mat)(i, j).headOption shouldBe None
      }

    }
  }

  def testRemoveElementFromVector[T: SparseVectorHandler](implicit A: Arbitrary[VectorVals[T]], CT: ClassTag[T]) = {
    it should s"create a vector of type ${CT.toString()}, check elements exist, remove them then verify they are gone" in forAll { mt: VectorVals[T] =>
      val handler = SparseVectorHandler[T]

      val vec = handler.buildVector(mt)

      mt.vals.foreach {
        case (i, v) =>
          handler.get(vec)(i).headOption shouldBe Some(v)

          handler.remove(vec)(i)

          handler.get(vec)(i).headOption shouldBe None
      }

    }
  }
}
