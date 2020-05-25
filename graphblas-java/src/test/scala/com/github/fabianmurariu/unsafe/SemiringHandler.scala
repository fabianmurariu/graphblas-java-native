package com.github.fabianmurariu.unsafe

import java.nio.Buffer

trait SemiringHandler

trait BinaryOpHandler[A] {
  def times: Buffer
  def plus: Buffer
}

object BinaryOpHandler {
  @inline
  def apply[A](implicit B: BinaryOpHandler[A]): BinaryOpHandler[A] = B

  implicit val binOpsBoolean:BinaryOpHandler[Boolean] = new BinaryOpHandler[Boolean] {
    def times:Buffer = { GRAPHBLAS.timesBinaryOpBoolean() }
    def plus: Buffer = GRAPHBLAS.plusBinaryOpBoolean()
  }

  implicit val binOpsByte:BinaryOpHandler[Byte] = new BinaryOpHandler[Byte] {
    def times:Buffer = { GRAPHBLAS.timesBinaryOpByte() }
    def plus: Buffer = GRAPHBLAS.plusBinaryOpByte()
  }
  implicit val binOpsShort:BinaryOpHandler[Short] = new BinaryOpHandler[Short] {
    def times:Buffer = { GRAPHBLAS.timesBinaryOpShort() }
    def plus: Buffer = GRAPHBLAS.plusBinaryOpShort()
  }
  implicit val binOpsInt:BinaryOpHandler[Int] = new BinaryOpHandler[Int] {
    def times:Buffer = { GRAPHBLAS.timesBinaryOpInt() }
    def plus: Buffer = GRAPHBLAS.plusBinaryOpInt()
  }
  implicit val binOpsLong:BinaryOpHandler[Long] = new BinaryOpHandler[Long] {
    def times:Buffer = { GRAPHBLAS.timesBinaryOpLong() }
    def plus: Buffer = GRAPHBLAS.plusBinaryOpLong()
  }

  implicit val binOpsFloat:BinaryOpHandler[Float] = new BinaryOpHandler[Float] {
    def times:Buffer = { GRAPHBLAS.timesBinaryOpFloat() }
    def plus: Buffer = GRAPHBLAS.plusBinaryOpFloat()
  }

  implicit val binOpsDouble:BinaryOpHandler[Double] = new BinaryOpHandler[Double] {
    def times:Buffer = { GRAPHBLAS.timesBinaryOpDouble() }
    def plus: Buffer = GRAPHBLAS.plusBinaryOpDouble()
  }
}

trait MonoidHandler[A] {
  def plus: Buffer
}

object MonoidHandler{
  @inline
  def apply[A](implicit M:MonoidHandler[A]): MonoidHandler[A] = M

  implicit val monoidHandlerByte:MonoidHandler[Byte] = new MonoidHandler[Byte] {
    override def plus: Buffer = GRBMONOID.plusMonoidByte()
  }
  implicit val monoidHandlerShort:MonoidHandler[Short] = new MonoidHandler[Short] {
    override def plus: Buffer = GRBMONOID.plusMonoidShort()
  }
  implicit val monoidHandlerInt:MonoidHandler[Int] = new MonoidHandler[Int] {
    override def plus: Buffer = GRBMONOID.plusMonoidInt()
  }
  implicit val monoidHandlerLong:MonoidHandler[Long] = new MonoidHandler[Long] {
    override def plus: Buffer = GRBMONOID.plusMonoidLong()
  }
  implicit val monoidHandlerFloat:MonoidHandler[Float] = new MonoidHandler[Float] {
    override def plus: Buffer = GRBMONOID.plusMonoidFloat()
  }
  implicit val monoidHandlerDouble:MonoidHandler[Double] = new MonoidHandler[Double] {
    override def plus: Buffer = GRBMONOID.plusMonoidDouble()
  }
}
