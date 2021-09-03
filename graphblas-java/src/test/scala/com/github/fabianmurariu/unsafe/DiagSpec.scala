package com.github.fabianmurariu.unsafe

import org.scalacheck.Arbitrary
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

import scala.reflect.ClassTag

trait DiagSpec {
    self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers =>

    behavior of "GxB_Matrix_diag"

    assignVectorDiagMatrix[Byte]
    assignVectorDiagMatrix[Short]
    assignVectorDiagMatrix[Int]
    assignVectorDiagMatrix[Long]
    assignVectorDiagMatrix[Float]
    assignVectorDiagMatrix[Double]

    def assignVectorDiagMatrix[T: SparseMatrixHandler:SparseVectorHandler:Plus](implicit A: Arbitrary[MatrixTuplesSquare[T]], CT: ClassTag[T]): Unit = {
        it should s"create a matrix of type ${CT.toString()}, sum the items with reduce then assign them on diagonal" in forAll { mt: MatrixTuplesSquare[T] =>
            val handler = SparseMatrixHandler[T]

            val mat = handler.createMatrix(mt.dim, mt.dim)
            val mat2 = handler.createMatrix(mt.dim, mt.dim)
            val vec = SparseVectorHandler[T].createVector(mt.dim)

            GRBOPSMAT.matrixReduceBinOp(vec, null, null, Plus[T].binaryOp, mat, null)

            GRBOPSMAT.diag(mat2, vec, 0, null)

            GRBCORE.vectorWait(vec)
            GRBCORE.matrixWait(mat2)

            val vecItems: Array[T] = SparseVectorHandler[T].extractTuples(vec)

            for (i <- vecItems.indices) {
                handler.get(mat2)(i, i).headOption shouldBe Some(vecItems(i))
            }


            GRBCORE.freeMatrix(mat)
            GRBCORE.freeMatrix(mat2)
            GRBCORE.freeMatrix(mat)
        }
    }
}
