package com.github.fabianmurariu.unsafe

import java.nio.Buffer

sealed trait Op

sealed trait Plus[T] extends Op {
    def binaryOp: Buffer
}

object Plus {
    def apply[T](implicit P: Plus[T]): Plus[T] = P

    implicit val bytePlus: Plus[Byte] = new Plus[Byte] {
        override def binaryOp: Buffer = GRAPHBLAS.plusBinaryOpByte()
    }
    implicit val shortPlus: Plus[Short] = new Plus[Short] {
        override def binaryOp: Buffer = GRAPHBLAS.plusBinaryOpShort()
    }
    implicit val intPlus: Plus[Int] = new Plus[Int] {
        override def binaryOp: Buffer = GRAPHBLAS.plusBinaryOpInt()
    }
    implicit val longPlus: Plus[Long] = new Plus[Long] {
        override def binaryOp: Buffer = GRAPHBLAS.plusBinaryOpLong()
    }
    implicit val floatPlus: Plus[Float] = new Plus[Float] {
        override def binaryOp: Buffer = GRAPHBLAS.plusBinaryOpFloat()
    }
    implicit val doublePlus: Plus[Double] = new Plus[Double] {
        override def binaryOp: Buffer = GRAPHBLAS.plusBinaryOpDouble()
    }
}
