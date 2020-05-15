package com.github.fabianmurariu.unsafe

import java.nio.ByteBuffer

trait SparseMatrixHandler[T] {
  def buildMatrix(tuples: MatrixTuples[T]): ByteBuffer = {
    val MatrixTuples(MatrixDimensions(rows, cols), vals) = tuples
    val mat = createMatrix(rows, cols)
    vals.foreach{
      case (i, j, v) =>
        set(mat)(i, j, v)
    }
    mat
  }
  def createMatrix(rows:Long, cols:Long): ByteBuffer
  def get(mat:ByteBuffer)(i:Long, j:Long):Array[T]
  def set(mat:ByteBuffer)(i:Long, j:Long, t:T):Unit
}

object SparseMatrixHandler {
  @inline
  def apply[T](implicit sparseMatrixBuilder: SparseMatrixHandler[T]): SparseMatrixHandler[T] = sparseMatrixBuilder

  implicit val booleanMatrixHandler:SparseMatrixHandler[Boolean] = new SparseMatrixHandler[Boolean] {
    def createMatrix(rows: Long, cols:Long): ByteBuffer = GRBCORE.createMatrix(GRAPHBLAS.booleanType(), rows, cols)
    def get(mat: ByteBuffer)(i: Long, j: Long): Array[Boolean] = GRAPHBLAS.getMatrixElementBoolean(mat, i, j)
    def set(mat: ByteBuffer)(i: Long, j: Long, t: Boolean): Unit = GRAPHBLAS.setMatrixElementBoolean(mat, i, j, t)
  }

  implicit val byteMatrixHandler:SparseMatrixHandler[Byte] = new SparseMatrixHandler[Byte] {
    def createMatrix(rows: Long, cols:Long): ByteBuffer = GRBCORE.createMatrix(GRAPHBLAS.byteType(), rows, cols)
    def get(mat: ByteBuffer)(i: Long, j: Long): Array[Byte] = GRAPHBLAS.getMatrixElementByte(mat, i, j)
    def set(mat: ByteBuffer)(i: Long, j: Long, t: Byte): Unit = GRAPHBLAS.setMatrixElementByte(mat, i, j, t)
  }

  implicit val shortMatrixHandler:SparseMatrixHandler[Short] = new SparseMatrixHandler[Short] {
    def createMatrix(rows: Long, cols:Long): ByteBuffer = GRBCORE.createMatrix(GRAPHBLAS.shortType(), rows, cols)
    def get(mat: ByteBuffer)(i: Long, j: Long): Array[Short] = GRAPHBLAS.getMatrixElementShort(mat, i, j)
    def set(mat: ByteBuffer)(i: Long, j: Long, t: Short): Unit = GRAPHBLAS.setMatrixElementShort(mat, i, j, t)
  }

  implicit val intMatrixHandler:SparseMatrixHandler[Int] = new SparseMatrixHandler[Int] {
    def createMatrix(rows: Long, cols:Long): ByteBuffer = GRBCORE.createMatrix(GRAPHBLAS.intType(), rows, cols)
    def get(mat: ByteBuffer)(i: Long, j: Long): Array[Int] = GRAPHBLAS.getMatrixElementInt(mat, i, j)
    def set(mat: ByteBuffer)(i: Long, j: Long, t: Int): Unit = GRAPHBLAS.setMatrixElementInt(mat, i, j, t)
  }

  implicit val longMatrixHandler:SparseMatrixHandler[Long] = new SparseMatrixHandler[Long] {
    def createMatrix(rows: Long, cols:Long): ByteBuffer = GRBCORE.createMatrix(GRAPHBLAS.longType(), rows, cols)
    def get(mat: ByteBuffer)(i: Long, j: Long): Array[Long] = GRAPHBLAS.getMatrixElementLong(mat, i, j)
    def set(mat: ByteBuffer)(i: Long, j: Long, t: Long): Unit = GRAPHBLAS.setMatrixElementLong(mat, i, j, t)
  }

  implicit val floatMatrixHandler:SparseMatrixHandler[Float] = new SparseMatrixHandler[Float] {
    def createMatrix(rows: Long, cols:Long): ByteBuffer = GRBCORE.createMatrix(GRAPHBLAS.floatType(), rows, cols)
    def get(mat: ByteBuffer)(i: Long, j: Long): Array[Float] = GRAPHBLAS.getMatrixElementFloat(mat, i, j)
    def set(mat: ByteBuffer)(i: Long, j: Long, t: Float): Unit = GRAPHBLAS.setMatrixElementFloat(mat, i, j, t)
  }

  implicit val doubleMatrixHandler:SparseMatrixHandler[Double] = new SparseMatrixHandler[Double] {
    def createMatrix(rows: Long, cols:Long): ByteBuffer = GRBCORE.createMatrix(GRAPHBLAS.doubleType(), rows, cols)
    def get(mat: ByteBuffer)(i: Long, j: Long): Array[Double] = GRAPHBLAS.getMatrixElementDouble(mat, i, j)
    def set(mat: ByteBuffer)(i: Long, j: Long, t: Double): Unit = GRAPHBLAS.setMatrixElementDouble(mat, i, j, t)
  }
}