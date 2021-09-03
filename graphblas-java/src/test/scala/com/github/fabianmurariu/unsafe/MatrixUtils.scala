package com.github.fabianmurariu.unsafe

import org.scalacheck.{Arbitrary, Gen}
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

import scala.reflect.ClassTag

trait MatrixUtils {
  self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers =>

  protected def testSettersAndGettersMatrix[T](implicit A: Arbitrary[MatrixTuples[T]], CT: ClassTag[T], SH: SparseMatrixHandler[T]): Unit = {
    it should s"create a matrix of positive dimensions and build from tuples ${CT.toString()}" in forAll { mt: MatrixTuples[T] =>
      val mat = SH.createMatrix(mt.dim.rows, mt.dim.cols)
      val is = mt.vals.map(_._1).toArray
      val js = mt.vals.map(_._2).toArray
      val vs = mt.vals.map(_._3).toArray
      val out = SH.setTuples(mat, is, js, vs)
      out shouldBe 0L
      mt.vals.foreach {
        case (i, j, v) =>
          SH.get(mat)(i, j).headOption shouldBe Some(v)
      }
      GRBCORE.freeMatrix(mat)
    }

    it should s"create a matrix of positive dimensions and set/get ${CT.toString()} values" in forAll { mt: MatrixTuples[T] =>
      val mat = SH.createMatrix(mt.dim.rows, mt.dim.cols)
      mt.vals.foreach { case (i, j, v) =>
        SH.set(mat)(i, j, v)
      }
      GRBCORE.nvalsMatrix(mat) shouldBe mt.vals.size
      mt.vals.foreach { case (i, j, v) =>
        SH.get(mat)(i, j).headOption shouldBe Some(v)
      }
      val a = SH.extractTuples(mat)
      a.length shouldBe mt.vals.size
      GRBCORE.freeMatrix(mat)
    }
  }

}

case class MatrixDimensions(rows: Long, cols: Long)

case class MatrixTuples[T](dim: MatrixDimensions, vals: Vector[(Long, Long, T)])

case class MatrixTuplesSquare[T](dim: Long, vals: Vector[(Long, Long, T)])

// tuples for multiplication
case class MatrixTuplesMul[T](left: MatrixTuples[T], right: MatrixTuples[T])

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

object MatrixTuplesSquare {

    implicit def arb[T: Gen.Choose](implicit N: Numeric[T]): Arbitrary[MatrixTuplesSquare[T]] = {
        def genVal(size: Long): Gen[(Long, Long, T)] = for {
            i <- Gen.choose(0, size - 1)
            j <- Gen.choose(0, size - 1)
            t <- Gen.oneOf[T](Gen.posNum, Gen.negNum)
        } yield (i, j, t)

        val gen = for {
            dim <- Gen.posNum[Long]
            vals <- Gen.nonEmptyContainerOf[Vector, (Long, Long, T)](genVal(dim)).map(_.distinctBy(t => t._1 -> t._2))
        } yield MatrixTuplesSquare[T](dim, vals)

        Arbitrary(gen)
    }
}

object MatrixTuplesMul {
  implicit def arbMul[T: Gen.Choose](implicit A: Arbitrary[MatrixDimensions], N: Numeric[T]): Arbitrary[MatrixTuplesMul[T]] = {
    def genVal(rows: Long, cols: Long): Gen[(Long, Long, T)] = for {
      i <- Gen.choose(0, rows - 1)
      j <- Gen.choose(0, cols - 1)
      t <- Gen.oneOf[T](Gen.posNum, Gen.negNum)
    } yield (i, j, t)

    val gen = for {
      dim <- A.arbitrary
      vals <- Gen.nonEmptyContainerOf[Vector, (Long, Long, T)](genVal(dim.rows, dim.cols)).map(_.distinctBy(t => t._1 -> t._2))
      valsFlipped <- Gen.nonEmptyContainerOf[Vector, (Long, Long, T)](genVal(dim.cols, dim.rows)).map(_.distinctBy(t => t._1 -> t._2))
    } yield MatrixTuplesMul(MatrixTuples[T](dim, vals), MatrixTuples(MatrixDimensions(dim.cols, dim.rows), valsFlipped))

    Arbitrary(gen)
  }
}
