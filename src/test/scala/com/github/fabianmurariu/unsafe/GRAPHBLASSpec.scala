package com.github.fabianmurariu.unsafe

import java.nio.ByteBuffer

import org.scalacheck.{Arbitrary, Gen}
import org.scalatest.BeforeAndAfterAll
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

import scala.reflect.ClassTag

class GRAPHBLASSpec extends AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers with BeforeAndAfterAll {

  behavior of "GRAPHBLAS"

    testSettersAndGetters[Boolean](GRAPHBLAS.booleanType())
      {(mat, i, j, value) => GRAPHBLAS.setElementBoolean(mat, i, j, value) }
      {(mat, i, j) => GRAPHBLAS.getElementBoolean(mat, i, j).headOption }

    testSettersAndGetters[Byte](GRAPHBLAS.byteType())
      {(mat, i, j, value) => GRAPHBLAS.setElementByte(mat, i, j, value) }
      {(mat, i, j) => GRAPHBLAS.getElementByte(mat, i, j).headOption }

    testSettersAndGetters[Short](GRAPHBLAS.shortType())
      {(mat, i, j, value) => GRAPHBLAS.setElementShort(mat, i, j, value) }
      {(mat, i, j) => GRAPHBLAS.getElementShort(mat, i, j).headOption }

  testSettersAndGetters[Int](GRAPHBLAS.intType())
    { (mat, i, j, value) => GRAPHBLAS.setElementInt(mat, i, j, value) }
    { (mat, i, j) => GRAPHBLAS.getElementInt(mat, i, j).headOption }


    testSettersAndGetters[Long](GRAPHBLAS.longType())
      {(mat, i, j, value) => GRAPHBLAS.setElementLong(mat, i, j, value) }
      {(mat, i, j) => GRAPHBLAS.getElementLong(mat, i, j).headOption }

    testSettersAndGetters[Float](GRAPHBLAS.floatType())
      {(mat, i, j, value) => GRAPHBLAS.setElementFloat(mat, i, j, value) }
      {(mat, i, j) => GRAPHBLAS.getElementFloat(mat, i, j).headOption }

    testSettersAndGetters[Double](GRAPHBLAS.doubleType())
      {(mat, i, j, value) => GRAPHBLAS.setElementDouble(mat, i, j, value) }
      {(mat, i, j) => GRAPHBLAS.getElementDouble(mat, i, j).headOption }

  private def testSettersAndGetters[T](tpe: => ByteBuffer)
                                      (set: (ByteBuffer, Long, Long, T) => Unit)(get: (ByteBuffer, Long, Long) => Option[T])
                                      (implicit A: Arbitrary[MatrixTuples[T]], CT: ClassTag[T]): Unit = {
    it should s"create a matrix of positive dimensions and set/get ${CT.toString()} values" in forAll { mt: MatrixTuples[T] =>
      val mat = makeMat(mt.dim, tpe)
      mt.vals.foreach { case (i, j, v) =>
        set(mat, i, j, v)
      }
      GRBCORE.nvals(mat) shouldBe mt.vals.size
      mt.vals.foreach { case (i, j, v) =>
        get(mat, i, j) shouldBe Some(v)
      }
      GRBCORE.free(mat)
    }
  }

  private def makeMat(md: MatrixDimensions, tpe: ByteBuffer): ByteBuffer = {
    val mat = GRBCORE.createMatrix(tpe, md.rows, md.cols)
    GRBCORE.nvals(mat) shouldBe 0
    GRBCORE.nrows(mat) shouldBe md.rows
    GRBCORE.ncols(mat) shouldBe md.cols
    mat
  }

  override protected def beforeAll(): Unit = {
    GRBCORE.initNonBlocking()
  }

  override protected def afterAll(): Unit = {
    GRBCORE.grbWait()
    GRBCORE.grbFinalize()
  }
}

case class MatrixDimensions(rows: Long, cols: Long)

case class MatrixTuples[T](dim: MatrixDimensions, vals: Vector[(Long, Long, T)])

object MatrixDimensions {
  lazy val gen: Gen[MatrixDimensions] = for {
    rows <- Gen.posNum[Long]
    cols <- Gen.posNum[Long]
  } yield MatrixDimensions(rows, cols)

  implicit val arb: Arbitrary[MatrixDimensions] = Arbitrary(gen)
}

object MatrixTuples {

  implicit def fakeChooseBoolean: Gen.Choose[Boolean] = (min: Boolean, max: Boolean) => {
    if (min == max) {
      Gen.const(min)
    } else {
      Gen.oneOf(Array(true, false))
    }
  }

  implicit def arbBool(implicit A: Arbitrary[MatrixDimensions]): Arbitrary[MatrixTuples[Boolean]] = {
    def genVal(rows: Long, cols: Long): Gen[(Long, Long, Boolean)] = for {
      i <- Gen.choose(0, rows - 1)
      j <- Gen.choose(0, cols - 1)
      t <- Gen.oneOf(Array(true, false))
    } yield (i, j, t)

    val gen = for {
      dim <- A.arbitrary
      vals <- Gen.nonEmptyContainerOf[Vector, (Long, Long, Boolean)](genVal(dim.rows, dim.cols)).map(_.distinctBy(t => t._1 -> t._2))
    } yield MatrixTuples[Boolean](dim, vals)

    Arbitrary(gen)
  }

  implicit def arb[T: Gen.Choose](implicit A: Arbitrary[MatrixDimensions], N: Numeric[T]): Arbitrary[MatrixTuples[T]] = {
    def genVal(rows: Long, cols: Long): Gen[(Long, Long, T)] = for {
      i <- Gen.choose(0, rows - 1)
      j <- Gen.choose(0, cols - 1)
      t <- Gen.oneOf[T](Gen.posNum, Gen.negNum)
    } yield (i, j, t)

    val gen = for {
      dim <- A.arbitrary
      vals <- Gen.nonEmptyContainerOf[Vector, (Long, Long, T)](genVal(dim.rows, dim.cols)).map(_.distinctBy(t => t._1 -> t._2))
    } yield MatrixTuples[T](dim, vals)

    Arbitrary(gen)
  }
}