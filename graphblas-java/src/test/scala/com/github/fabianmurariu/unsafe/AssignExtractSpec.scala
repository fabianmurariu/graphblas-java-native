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

  behavior of "GrB_Matrix_extract"

  testGrBMatrixExtract[Boolean]
  testGrBMatrixExtract[Byte]
  testGrBMatrixExtract[Short]
  testGrBMatrixExtract[Int]
  testGrBMatrixExtract[Long]
  testGrBMatrixExtract[Float]
  testGrBMatrixExtract[Double]

  private def testGrBMatrixExtract[T: SparseMatrixHandler](implicit A: Arbitrary[MatrixTuples[T]], CT: ClassTag[T]): Unit = {
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

    it should s"call GrB_extract all for GrB_Matrix of type ${CT.toString()}" in forAll { mt: MatrixTuples[T] =>
      val mat = SparseMatrixHandler[T].buildMatrix(mt)

      val into = SparseMatrixHandler[T].createMatrix(mt.dim.rows, mt.dim.cols)

      val res = GRBOPSMAT.extract(into, null, null, mat, GRBCORE.GrB_ALL, mt.dim.rows, GRBCORE.GrB_ALL, mt.dim.cols, null)
      assert(res == 0)

      SparseMatrixHandler[T].extractTuples(into) should contain theSameElementsAs SparseMatrixHandler[T].extractTuples(mat)
    }
  }

  behavior of "GrB_Vector_extract"

  testGrBVectorExtract[Boolean]
  testGrBVectorExtract[Byte]
  testGrBVectorExtract[Short]
  testGrBVectorExtract[Int]
  testGrBVectorExtract[Long]
  testGrBVectorExtract[Float]
  testGrBVectorExtract[Double]

  private def testGrBVectorExtract[T: SparseVectorHandler](implicit A: Arbitrary[VectorVals[T]], CT: ClassTag[T]): Unit = {
    it should s"call GrB_extract for GrB_Vector of type ${CT.toString()}" in forAll { mt: VectorVals[T] =>
      val vec = SparseVectorHandler[T].buildVector(mt)

      // pick half of the indices and extract them into another mat
      val (_, right) = mt.vals.splitAt(mt.vals.size / 2)
      val dRight = right.distinctBy(t => t._1 -> t._2)
      val ni: Vector[Long] = dRight.map(_._1)

      val into = SparseVectorHandler[T].createVector(ni.size)

      val res = GRBOPSVEC.extract(into, null, null, vec, ni.toArray, ni.size, null)
      assert(res == 0)

      val expected: immutable.IndexedSeq[T] = (for {
        i <- ni.indices
      } yield SparseVectorHandler[T].get(vec)(ni(i))).flatten

      SparseVectorHandler[T].extractTuples(into) should contain theSameElementsAs expected
    }
  }

//  behavior of "GrB_assign"
//
//  testGrBMatrixAssign[Boolean]
//  testGrBMatrixAssign[Byte]
//  testGrBMatrixAssign[Short]
//  testGrBMatrixAssign[Int]
//  testGrBMatrixAssign[Long]
//  testGrBMatrixAssign[Float]
//  testGrBMatrixAssign[Double]

  private def testGrBMatrixAssign[T: SparseMatrixHandler](implicit A: Arbitrary[MatrixTuples[T]], CT: ClassTag[T]): Unit = {
    it should s"call GrB_assign for GrB_Matrix of type ${CT.toString()}" in forAll { mt: MatrixTuples[T] =>
      val mat = SparseMatrixHandler[T].buildMatrix(mt)

      GRBCORE.nvalsMatrix(mat)
      // pick half of the indices and extract them into another mat
      val (_, right) = mt.vals.splitAt(mt.vals.size / 2)
      val dRight = right.distinctBy(t => t._1 -> t._2)
      val ni: Vector[Long] = dRight.map(_._1)
      val nj: Vector[Long] = dRight.map(_._2)

      val into = SparseMatrixHandler[T].createMatrix(ni.size, nj.size)

      val res = GRBOPSMAT.assign(into, null, null, mat, ni.toArray, ni.size, nj.toArray, nj.size, null)
      assert(res == 0)

      val expected: immutable.IndexedSeq[T] = (for {
        i <- ni.indices
        j <- nj.indices
      } yield SparseMatrixHandler[T].get(mat)(ni(i), nj(j))).flatten

      SparseMatrixHandler[T].extractTuples(into) should contain theSameElementsAs expected
    }
  }
}
