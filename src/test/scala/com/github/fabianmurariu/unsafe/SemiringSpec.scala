package com.github.fabianmurariu.unsafe

import java.lang.reflect.Modifier

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

trait SemiringSpec {

  self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers =>

  behavior of "GrB_Semiring"

  it should "be created from a monoid and a binaryOp" in {
    val semi = GRBCORE.createSemiring(GRBMONOID.maxMonoidInt(), GRAPHBLAS.minBinaryOpInt())
    GRBCORE.freeSemiring(semi)
  }

  def allMonoids: Array[String] = {
    classOf[GRBMONOID].getDeclaredMethods
      .filter(m => Modifier.isStatic(m.getModifiers))
      .map(_.getName)

  }

  def allBinaryOps: Array[String] = {
    classOf[GRAPHBLAS].getDeclaredMethods
      .filter(m => Modifier.isStatic(m.getModifiers))
      .map(_.getName)
      .filter(n => n.contains("BinaryOp"))
  }

  allMonoids.foreach(println)
  allBinaryOps.foreach(println)
}
