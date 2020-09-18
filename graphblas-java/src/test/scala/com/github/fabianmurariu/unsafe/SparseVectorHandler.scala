package com.github.fabianmurariu.unsafe

import java.nio.Buffer

trait SparseVectorHandler[T] {
  def buildVector(tuples: VectorVals[T]): Buffer = {
    val VectorVals(size, vals) = tuples
    val vec = createVector(size)
    vals.foreach {
      case (i, v) =>
        set(vec)(i, v)
    }
    vec
  }

  def createVector(size: Long): Buffer

  def get(vec: Buffer)(i: Long): Array[T]

  def set(vec: Buffer)(i: Long, v: T): Unit

  def assign(vec: Buffer)(v: T): Unit
  
  def size(vec: Buffer) : Long = 
    GRBCORE.size(vec)

  def remove(vec: Buffer)(i: Long): Unit =
    GRBCORE.removeElementVector(vec, i)

  def clear(vec: Buffer): Unit =
    GRBCORE.clearVec(vec)

}

object SparseVectorHandler {
  def apply[T](implicit S: SparseVectorHandler[T]): SparseVectorHandler[T] = S

  implicit val booleanVectorHandler: SparseVectorHandler[Boolean] = new SparseVectorHandler[Boolean] {
    def createVector(size: Long): Buffer = GRBCORE.createVector(GRAPHBLAS.booleanType(), size)

    def get(vec: Buffer)(i: Long): Array[Boolean] = GRAPHBLAS.getVectorElementBoolean(vec, i)

    def set(vec: Buffer)(i: Long, t: Boolean): Unit = GRAPHBLAS.setVectorElementBoolean(vec, i, t)

    def assign(vec: Buffer)(v: Boolean): Unit = 
      GRAPHBLAS.assignVectorBoolean(vec, null, null, v, GRBCORE.GrB_ALL, size(vec), null)
  }

  implicit val byteVectorHandler: SparseVectorHandler[Byte] = new SparseVectorHandler[Byte] {
    def createVector(size: Long): Buffer = GRBCORE.createVector(GRAPHBLAS.byteType(), size)

    def get(vec: Buffer)(i: Long): Array[Byte] = GRAPHBLAS.getVectorElementByte(vec, i)

    def set(vec: Buffer)(i: Long, t: Byte): Unit = GRAPHBLAS.setVectorElementByte(vec, i, t)

    def assign(vec: Buffer)(v: Byte): Unit =
      GRAPHBLAS.assignVectorByte(vec, null, null, v, GRBCORE.GrB_ALL, size(vec), null)
  }

  implicit val shortVectorHandler: SparseVectorHandler[Short] = new SparseVectorHandler[Short] {
    def createVector(size: Long): Buffer = GRBCORE.createVector(GRAPHBLAS.shortType(), size)

    def get(vec: Buffer)(i: Long): Array[Short] = GRAPHBLAS.getVectorElementShort(vec, i)

    def set(vec: Buffer)(i: Long, t: Short): Unit = GRAPHBLAS.setVectorElementShort(vec, i, t)

    def assign(vec: Buffer)(v: Short): Unit =
      GRAPHBLAS.assignVectorShort(vec, null, null, v, GRBCORE.GrB_ALL, size(vec), null)
  }

  implicit val intVectorHandler: SparseVectorHandler[Int] = new SparseVectorHandler[Int] {
    def createVector(size: Long): Buffer = GRBCORE.createVector(GRAPHBLAS.intType(), size)

    def get(vec: Buffer)(i: Long): Array[Int] = GRAPHBLAS.getVectorElementInt(vec, i)

    def set(vec: Buffer)(i: Long, t: Int): Unit = GRAPHBLAS.setVectorElementInt(vec, i, t)

    def assign(vec: Buffer)(v: Int): Unit =
      GRAPHBLAS.assignVectorInt(vec, null, null, v, GRBCORE.GrB_ALL, size(vec), null)
  }

  implicit val longVectorHandler: SparseVectorHandler[Long] = new SparseVectorHandler[Long] {
    def createVector(size: Long): Buffer = GRBCORE.createVector(GRAPHBLAS.longType(), size)

    def get(vec: Buffer)(i: Long): Array[Long] = GRAPHBLAS.getVectorElementLong(vec, i)

    def set(vec: Buffer)(i: Long, t: Long): Unit = GRAPHBLAS.setVectorElementLong(vec, i, t)

    def assign(vec: Buffer)(v: Long): Unit =
      GRAPHBLAS.assignVectorLong(vec, null, null, v, GRBCORE.GrB_ALL, size(vec), null)
  }

  implicit val floatVectorHandler: SparseVectorHandler[Float] = new SparseVectorHandler[Float] {
    def createVector(size: Long): Buffer = GRBCORE.createVector(GRAPHBLAS.floatType(), size)

    def get(vec: Buffer)(i: Long): Array[Float] = GRAPHBLAS.getVectorElementFloat(vec, i)

    def set(vec: Buffer)(i: Long, t: Float): Unit = GRAPHBLAS.setVectorElementFloat(vec, i, t)

    def assign(vec: Buffer)(v: Float): Unit =
      GRAPHBLAS.assignVectorFloat(vec, null, null, v, GRBCORE.GrB_ALL, size(vec), null)
  }

  implicit val doubleVectorHandler: SparseVectorHandler[Double] = new SparseVectorHandler[Double] {
    def createVector(size: Long): Buffer = GRBCORE.createVector(GRAPHBLAS.doubleType(), size)

    def get(vec: Buffer)(i: Long): Array[Double] = GRAPHBLAS.getVectorElementDouble(vec, i)

    def set(vec: Buffer)(i: Long, t: Double): Unit = GRAPHBLAS.setVectorElementDouble(vec, i, t)

    def assign(vec: Buffer)(v: Double): Unit =
      GRAPHBLAS.assignVectorDouble(vec, null, null, v, GRBCORE.GrB_ALL, size(vec), null)
  }
}
