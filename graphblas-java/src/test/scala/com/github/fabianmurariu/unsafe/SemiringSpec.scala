package com.github.fabianmurariu.unsafe

import java.io.{FileOutputStream, PrintWriter}
import java.lang.reflect.Modifier

import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

import scala.util.{Success, Try}

trait SemiringSpec {

  self: AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers =>

  behavior of "GrB_Semiring"

  it should "be created from a monoid and a binaryOp" in {
    val semi = GRBCORE.createSemiring(GRBMONOID.maxMonoidInt(), GRAPHBLAS.minBinaryOpInt())
    GRBCORE.freeSemiring(semi)
  }

//  def allMonoids: Array[String] = {
//    classOf[GRBMONOID].getDeclaredMethods
//      .filter(m => Modifier.isStatic(m.getModifiers))
//      .map(_.getName)
//
//  }
//
//  def allBinaryOps: Array[String] = {
//    classOf[GRAPHBLAS].getDeclaredMethods
//      .filter(m => Modifier.isStatic(m.getModifiers))
//      .map(_.getName)
//      .filter(n => n.contains("BinaryOp"))
//  }

//  allMonoids.foreach(println)
//  val boolOp = Set("eq", "ne", "gt", "lt", "ge", "le")

//  allBinaryOps.map {
//    name: String =>
//      Try {
//        val tokens = name.split("BinaryOp")
//        val opName = tokens(0)
//        val tpe = tokens(1)
//        tpe -> opName
//      }
//  }.collect { case Success(value) => value }
//    .groupBy(_._1).foldLeft(new PrintWriter(new FileOutputStream("./BinaryOps.scala.txt"))) {
//    case (writer, (tpe, ops)) =>
//      val opsScala = ops.map { case (_, name) =>
//        val outTpe = if (boolOp(name)) "Boolean" else tpe
//        s""" val $name:GrBBinaryOp[$tpe, $tpe, $outTpe] =
//                 GrBBinaryOp(GRAPHBLAS.${name}BinaryOp$tpe())"""
//      }.mkString("\n")
//      val instanceScala =
//        s"""
//           val ${tpe.toLowerCase} = new BuiltInBinaryOps[$tpe] {
//            $opsScala
//           }
//           """
//      writer.print(instanceScala)
//      writer
//  }.close()
}
