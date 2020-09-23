package com.github.fabianmurariu.unsafe

import java.nio.Buffer

import org.scalacheck.{Arbitrary, Gen}
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

import scala.reflect.ClassTag

trait VectorUtils {
  self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers =>

  protected def testSettersAndGettersVector[T](tpe: => Buffer)
                                              (set: (Buffer, Long, T) => Unit)(get: (Buffer, Long) => Option[T])
                                              (implicit A: Arbitrary[VectorVals[T]], CT: ClassTag[T]): Unit = {

    it should s"create a vector of positive dimensions and set/get ${CT.toString()} values" in forAll { vvs: VectorVals[T] =>
      val vec = makeVec(vvs.size, tpe)
      vvs.vals.foreach { case (i, v) =>
        set(vec, i, v)
      }
      GRBCORE.nvalsVector(vec) shouldBe vvs.vals.size
      vvs.vals.foreach { case (i, v) =>
        get(vec, i) shouldBe Some(v)
      }
      GRBCORE.freeVector(vec)
    }
  }

  protected def makeVec(size: Long, tpe: Buffer): Buffer = {
    val mat = GRBCORE.createVector(tpe, size)
    GRBCORE.nvalsVector(mat) shouldBe 0
    GRBCORE.size(mat) shouldBe size
    mat
  }
}

case class VectorVals[T](size: Long, vals: Vector[(Long, T)])

// tuples for multiplication
case class VectorValsMul[T](left: VectorVals[T], right: VectorVals[T])


object VectorVals {

  implicit def fakeChooseBoolean: Gen.Choose[Boolean] = (min: Boolean, max: Boolean) => {
    if (min == max) {
      Gen.const(min)
    } else {
      Gen.oneOf(Array(true, false))
    }
  }

  implicit def arbBool: Arbitrary[VectorVals[Boolean]] = {
    def genVal(size: Long): Gen[(Long, Boolean)] = for {
      i <- Gen.choose(0, size - 1)
      t <- Gen.oneOf(Array(true, false))
    } yield (i, t)

    val gen = for {
      size <- Gen.choose(1, 100)
      vals <- Gen.nonEmptyContainerOf[Vector, (Long, Boolean)](genVal(size)).map(_.distinctBy(_._1))
    } yield VectorVals(size, vals)

    Arbitrary(gen)
  }

  implicit def arb[T: Gen.Choose](implicit N: Numeric[T]): Arbitrary[VectorVals[T]] = {
    def genVal(size: Long): Gen[(Long, T)] = for {
      i <- Gen.choose(0, size - 1)
      t <- Gen.oneOf[T](Gen.posNum, Gen.negNum)
    } yield (i, t)

    val gen = for {
      size <- Gen.posNum[Long]
      vals <- Gen.nonEmptyContainerOf[Vector, (Long, T)](genVal(size)).map(_.distinctBy(_._1))
    } yield VectorVals(size, vals)

    Arbitrary(gen)
  }
}

object VectorValsMul {
  implicit def arbMul[T: Gen.Choose](implicit A: Arbitrary[VectorDimensions], N: Numeric[T]): Arbitrary[VectorValsMul[T]] = {
    def genVal(size: Long): Gen[(Long, T)] = for {
      i <- Gen.choose(0, size - 1)
      t <- Gen.oneOf[T](Gen.posNum, Gen.negNum)
    } yield (i, t)

    val gen = for {
      size <- Gen.choose(1, 100)
      vals <- Gen.nonEmptyContainerOf[Vector, (Long, T)](genVal(size)).map(_.distinctBy(_._1))
      otherVals <- Gen.nonEmptyContainerOf[Vector, (Long, T)](genVal(size)).map(_.distinctBy(_._1))
    } yield VectorValsMul(VectorVals[T](size, vals), VectorVals(size, otherVals))

    Arbitrary(gen)
  }
}

case class VectorDimensions(size: Int)
object VectorDimensions{
  implicit val arb:Arbitrary[VectorDimensions] = Arbitrary(Gen.posNum[Int].map(VectorDimensions(_)))
}
