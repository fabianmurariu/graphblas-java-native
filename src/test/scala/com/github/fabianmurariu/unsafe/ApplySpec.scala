package com.github.fabianmurariu.unsafe

import java.nio.ByteBuffer

import org.scalacheck.Arbitrary
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

import scala.reflect.ClassTag

trait ApplySpec {
  self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers =>

  behavior of "GrB_Matrix_apply"

  testUnaryOperationMatrixApply[Boolean]("identity")(GRAPHBLAS.identityUnaryOpBoolean())(identity)
  testUnaryOperationMatrixApply[Byte]("identity")(GRAPHBLAS.identityUnaryOpByte())(identity)
  testUnaryOperationMatrixApply[Short]("identity")(GRAPHBLAS.identityUnaryOpShort())(identity)
  testUnaryOperationMatrixApply[Int]("identity")(GRAPHBLAS.identityUnaryOpInt())(identity)
  testUnaryOperationMatrixApply[Long]("identity")(GRAPHBLAS.identityUnaryOpLong())(identity)
  testUnaryOperationMatrixApply[Float]("identity")(GRAPHBLAS.identityUnaryOpFloat())(identity)
  testUnaryOperationMatrixApply[Double]("identity")(GRAPHBLAS.identityUnaryOpDouble())(identity)

  testUnaryOperationMatrixApply[Boolean]("one")(GRAPHBLAS.oneUnaryOpBoolean())(_ => true)
  testUnaryOperationMatrixApply[Byte]("one")(GRAPHBLAS.oneUnaryOpByte())(_ => 1)
  testUnaryOperationMatrixApply[Short]("one")(GRAPHBLAS.oneUnaryOpShort())(_ => 1)
  testUnaryOperationMatrixApply[Int]("one")(GRAPHBLAS.oneUnaryOpInt())(_ => 1)
  testUnaryOperationMatrixApply[Long]("one")(GRAPHBLAS.oneUnaryOpLong())(_ => 1)
  testUnaryOperationMatrixApply[Float]("one")(GRAPHBLAS.oneUnaryOpFloat())(_ => 1)
  testUnaryOperationMatrixApply[Double]("one")(GRAPHBLAS.oneUnaryOpDouble())(_ => 1)

  testUnaryOperationMatrixApply[Boolean]("logicalNot")(GRAPHBLAS.logicalNotUnaryOpBoolean())(x => !x)
  testUnaryOperationMatrixApply[Byte]("logicalNot")(GRAPHBLAS.logicalNotUnaryOpByte())(expectLogicalNot)
  testUnaryOperationMatrixApply[Short]("logicalNot")(GRAPHBLAS.logicalNotUnaryOpShort())(expectLogicalNot)
  testUnaryOperationMatrixApply[Int]("logicalNot")(GRAPHBLAS.logicalNotUnaryOpInt())(expectLogicalNot)
  testUnaryOperationMatrixApply[Long]("logicalNot")(GRAPHBLAS.logicalNotUnaryOpLong())(expectLogicalNot)
  testUnaryOperationMatrixApply[Float]("logicalNot")(GRAPHBLAS.logicalNotUnaryOpFloat())(expectLogicalNot)
  testUnaryOperationMatrixApply[Double]("logicalNot")(GRAPHBLAS.logicalNotUnaryOpDouble())(expectLogicalNot)

  testUnaryOperationMatrixApply[Boolean]("abs")(GRAPHBLAS.absUnaryOpBoolean())(identity)
  testUnaryOperationMatrixApply[Byte]("abs")(GRAPHBLAS.absUnaryOpByte())(x =>Math.abs(x.toInt).toByte)
  testUnaryOperationMatrixApply[Short]("abs")(GRAPHBLAS.absUnaryOpShort())(x => Math.abs(x.toInt).toShort)
  testUnaryOperationMatrixApply[Int]("abs")(GRAPHBLAS.absUnaryOpInt())(Math.abs)
  testUnaryOperationMatrixApply[Long]("abs")(GRAPHBLAS.absUnaryOpLong())(Math.abs)
  testUnaryOperationMatrixApply[Float]("abs")(GRAPHBLAS.absUnaryOpFloat())(Math.abs)
  testUnaryOperationMatrixApply[Double]("abs")(GRAPHBLAS.absUnaryOpDouble())(Math.abs)

  testUnaryOperationMatrixApply[Boolean]("addInv")(GRAPHBLAS.addInvUnaryOpBoolean())(identity)
  testUnaryOperationMatrixApply[Byte]("addInv")(GRAPHBLAS.addInvUnaryOpByte())(x => (-x).toByte)
  testUnaryOperationMatrixApply[Short]("addInv")(GRAPHBLAS.addInvUnaryOpShort())(x => (-x).toShort)
  testUnaryOperationMatrixApply[Int]("addInv")(GRAPHBLAS.addInvUnaryOpInt())(x => -x)
  testUnaryOperationMatrixApply[Long]("addInv")(GRAPHBLAS.addInvUnaryOpLong())(x => -x)
  testUnaryOperationMatrixApply[Float]("addInv")(GRAPHBLAS.addInvUnaryOpFloat())(x => -x)
  testUnaryOperationMatrixApply[Double]("addInv")(GRAPHBLAS.addInvUnaryOpDouble())(x => -x)

  testUnaryOperationMatrixApply[Boolean]("mulInv")(GRAPHBLAS.mulInvUnaryOpBoolean())(x => if (x) x else !x)
  testUnaryOperationMatrixApply[Byte]("mulInv")(GRAPHBLAS.mulInvUnaryOpByte())(x => (1/x).toByte)
  testUnaryOperationMatrixApply[Short]("mulInv")(GRAPHBLAS.mulInvUnaryOpShort())(x => (1/x).toShort)
  testUnaryOperationMatrixApply[Int]("mulInv")(GRAPHBLAS.mulInvUnaryOpInt())(x => 1/x)
  testUnaryOperationMatrixApply[Long]("mulInv")(GRAPHBLAS.mulInvUnaryOpLong())(x => 1/x)
  testUnaryOperationMatrixApply[Float]("mulInv")(GRAPHBLAS.mulInvUnaryOpFloat())(x => 1/x)
  testUnaryOperationMatrixApply[Double]("mulInv")(GRAPHBLAS.mulInvUnaryOpDouble())(x => 1/x)

  behavior of "GrB_Vector_apply"

  testUnaryOperationVectorApply[Boolean]("identity")(GRAPHBLAS.identityUnaryOpBoolean())(identity)
  testUnaryOperationVectorApply[Byte]("identity")(GRAPHBLAS.identityUnaryOpByte())(identity)
  testUnaryOperationVectorApply[Short]("identity")(GRAPHBLAS.identityUnaryOpShort())(identity)
  testUnaryOperationVectorApply[Int]("identity")(GRAPHBLAS.identityUnaryOpInt())(identity)
  testUnaryOperationVectorApply[Long]("identity")(GRAPHBLAS.identityUnaryOpLong())(identity)
  testUnaryOperationVectorApply[Float]("identity")(GRAPHBLAS.identityUnaryOpFloat())(identity)
  testUnaryOperationVectorApply[Double]("identity")(GRAPHBLAS.identityUnaryOpDouble())(identity)

  testUnaryOperationVectorApply[Boolean]("one")(GRAPHBLAS.oneUnaryOpBoolean())(_ => true)
  testUnaryOperationVectorApply[Byte]("one")(GRAPHBLAS.oneUnaryOpByte())(_ => 1)
  testUnaryOperationVectorApply[Short]("one")(GRAPHBLAS.oneUnaryOpShort())(_ => 1)
  testUnaryOperationVectorApply[Int]("one")(GRAPHBLAS.oneUnaryOpInt())(_ => 1)
  testUnaryOperationVectorApply[Long]("one")(GRAPHBLAS.oneUnaryOpLong())(_ => 1)
  testUnaryOperationVectorApply[Float]("one")(GRAPHBLAS.oneUnaryOpFloat())(_ => 1)
  testUnaryOperationVectorApply[Double]("one")(GRAPHBLAS.oneUnaryOpDouble())(_ => 1)

  testUnaryOperationVectorApply[Boolean]("logicalNot")(GRAPHBLAS.logicalNotUnaryOpBoolean())(x => !x)
  testUnaryOperationVectorApply[Byte]("logicalNot")(GRAPHBLAS.logicalNotUnaryOpByte())(expectLogicalNot)
  testUnaryOperationVectorApply[Short]("logicalNot")(GRAPHBLAS.logicalNotUnaryOpShort())(expectLogicalNot)
  testUnaryOperationVectorApply[Int]("logicalNot")(GRAPHBLAS.logicalNotUnaryOpInt())(expectLogicalNot)
  testUnaryOperationVectorApply[Long]("logicalNot")(GRAPHBLAS.logicalNotUnaryOpLong())(expectLogicalNot)
  testUnaryOperationVectorApply[Float]("logicalNot")(GRAPHBLAS.logicalNotUnaryOpFloat())(expectLogicalNot)
  testUnaryOperationVectorApply[Double]("logicalNot")(GRAPHBLAS.logicalNotUnaryOpDouble())(expectLogicalNot)

  testUnaryOperationVectorApply[Boolean]("abs")(GRAPHBLAS.absUnaryOpBoolean())(identity)
  testUnaryOperationVectorApply[Byte]("abs")(GRAPHBLAS.absUnaryOpByte())(x =>Math.abs(x.toInt).toByte)
  testUnaryOperationVectorApply[Short]("abs")(GRAPHBLAS.absUnaryOpShort())(x => Math.abs(x.toInt).toShort)
  testUnaryOperationVectorApply[Int]("abs")(GRAPHBLAS.absUnaryOpInt())(Math.abs)
  testUnaryOperationVectorApply[Long]("abs")(GRAPHBLAS.absUnaryOpLong())(Math.abs)
  testUnaryOperationVectorApply[Float]("abs")(GRAPHBLAS.absUnaryOpFloat())(Math.abs)
  testUnaryOperationVectorApply[Double]("abs")(GRAPHBLAS.absUnaryOpDouble())(Math.abs)

  testUnaryOperationVectorApply[Boolean]("addInv")(GRAPHBLAS.addInvUnaryOpBoolean())(identity)
  testUnaryOperationVectorApply[Byte]("addInv")(GRAPHBLAS.addInvUnaryOpByte())(x => (-x).toByte)
  testUnaryOperationVectorApply[Short]("addInv")(GRAPHBLAS.addInvUnaryOpShort())(x => (-x).toShort)
  testUnaryOperationVectorApply[Int]("addInv")(GRAPHBLAS.addInvUnaryOpInt())(x => -x)
  testUnaryOperationVectorApply[Long]("addInv")(GRAPHBLAS.addInvUnaryOpLong())(x => -x)
  testUnaryOperationVectorApply[Float]("addInv")(GRAPHBLAS.addInvUnaryOpFloat())(x => -x)
  testUnaryOperationVectorApply[Double]("addInv")(GRAPHBLAS.addInvUnaryOpDouble())(x => -x)

  testUnaryOperationVectorApply[Boolean]("mulInv")(GRAPHBLAS.mulInvUnaryOpBoolean())(x => if (x) x else !x)
  testUnaryOperationVectorApply[Byte]("mulInv")(GRAPHBLAS.mulInvUnaryOpByte())(x => (1/x).toByte)
  testUnaryOperationVectorApply[Short]("mulInv")(GRAPHBLAS.mulInvUnaryOpShort())(x => (1/x).toShort)
  testUnaryOperationVectorApply[Int]("mulInv")(GRAPHBLAS.mulInvUnaryOpInt())(x => 1/x)
  testUnaryOperationVectorApply[Long]("mulInv")(GRAPHBLAS.mulInvUnaryOpLong())(x => 1/x)
  testUnaryOperationVectorApply[Float]("mulInv")(GRAPHBLAS.mulInvUnaryOpFloat())(x => 1/x)
  testUnaryOperationVectorApply[Double]("mulInv")(GRAPHBLAS.mulInvUnaryOpDouble())(x => 1/x)

  private def expectLogicalNot[T](implicit N:Numeric[T]): T => T = { x: T =>
    val asBoolean: Boolean = !N.equiv(x, N.fromInt(0)) // true if x != 0 false otherwise
    val out = !asBoolean
    if (out) N.fromInt(1) else N.fromInt(0)
  }

  private def testUnaryOperationMatrixApply[T: SparseMatrixHandler](name: String)(unaryOp: => ByteBuffer)
                                                             (expected: T => T)
                                                             (implicit A:Arbitrary[MatrixTuples[T]], CT: ClassTag[T]): Unit = {
    it should s"call GrB_apply of $name for GrB_Matrix of type ${CT.toString()}" in forAll { mt: MatrixTuples[T] =>
      val mat = SparseMatrixHandler[T].buildMatrix(mt)
      GRBCORE.matrixApply(mat, null, null, unaryOp, mat, null)

      for ((i, j, v) <- mt.vals) {
        SparseMatrixHandler[T].get(mat)(i, j).headOption shouldBe Some(expected(v))
      }
    }
  }


  private def testUnaryOperationVectorApply[T: SparseVectorHandler](name: String)(unaryOp: => ByteBuffer)
                                                                   (expected: T => T)
                                                                   (implicit A:Arbitrary[VectorVals[T]], CT: ClassTag[T]): Unit = {
    it should s"call GrB_apply of $name for GrB_Vector of type ${CT.toString()}" in forAll { mt: VectorVals[T] =>
      val mat = SparseVectorHandler[T].buildVector(mt)
      GRBCORE.vectorApply(mat, null, null, unaryOp, mat, null)

      for ((i, v) <- mt.vals) {
        SparseVectorHandler[T].get(mat)(i).headOption shouldBe Some(expected(v))
      }
    }
  }
}
