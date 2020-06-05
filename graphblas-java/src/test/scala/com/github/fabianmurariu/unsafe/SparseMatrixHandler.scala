package com.github.fabianmurariu.unsafe

import java.nio.Buffer

trait SparseMatrixHandler[T] {
  def buildMatrix(tuples: MatrixTuples[T]): Buffer = {
    val MatrixTuples(MatrixDimensions(rows, cols), vals) = tuples
    val mat = createMatrix(rows, cols)
    vals.foreach {
      case (i, j, v) =>
        set(mat)(i, j, v)
    }
    mat
  }

  def createMatrix(rows: Long, cols: Long): Buffer

  def get(mat: Buffer)(i: Long, j: Long): Array[T]

  def set(mat: Buffer)(i: Long, j: Long, t: T): Unit

  def extractTuples(mat: Buffer): Array[T]

  def setTuples(mat: Buffer, is: Array[Long], js: Array[Long], vs: Array[T]): Long
}

object SparseMatrixHandler {
  @inline
  def apply[T](implicit sparseMatrixBuilder: SparseMatrixHandler[T]): SparseMatrixHandler[T] = sparseMatrixBuilder

  implicit val booleanMatrixHandler: SparseMatrixHandler[Boolean] = new SparseMatrixHandler[Boolean] {
    def createMatrix(rows: Long, cols: Long): Buffer = GRBCORE.createMatrix(GRAPHBLAS.booleanType(), rows, cols)

    def get(mat: Buffer)(i: Long, j: Long): Array[Boolean] = GRAPHBLAS.getMatrixElementBoolean(mat, i, j)

    def set(mat: Buffer)(i: Long, j: Long, t: Boolean): Unit = GRAPHBLAS.setMatrixElementBoolean(mat, i, j, t)

    override def extractTuples(mat: Buffer): Array[Boolean] = {
      val nvals = GRBCORE.nvalsMatrix(mat)
      val vs = new Array[Boolean](nvals.toInt)
      val is = new Array[Long](nvals.toInt)
      val js = new Array[Long](nvals.toInt)
      GRAPHBLAS.extractTuplesBoolean(mat, vs, is, js)
      vs
    }

    override def setTuples(mat: Buffer, is: Array[Long], js: Array[Long], vs: Array[Boolean]): Long = {
      val nvals = is.length
      assert(is.length == js.length && js.length == vs.length)
      GRAPHBLAS.buildMatrixFromTuplesBoolean(mat, is, js, vs, nvals, GRAPHBLAS.firstBinaryOpBoolean())
    }
  }

  implicit val byteMatrixHandler: SparseMatrixHandler[Byte] = new SparseMatrixHandler[Byte] {
    def createMatrix(rows: Long, cols: Long): Buffer = GRBCORE.createMatrix(GRAPHBLAS.byteType(), rows, cols)

    def get(mat: Buffer)(i: Long, j: Long): Array[Byte] = GRAPHBLAS.getMatrixElementByte(mat, i, j)

    def set(mat: Buffer)(i: Long, j: Long, t: Byte): Unit = GRAPHBLAS.setMatrixElementByte(mat, i, j, t)

    override def extractTuples(mat: Buffer): Array[Byte] = {
      val nvals = GRBCORE.nvalsMatrix(mat)
      val vs = new Array[Byte](nvals.toInt)
      val is = new Array[Long](nvals.toInt)
      val js = new Array[Long](nvals.toInt)
      GRAPHBLAS.extractTuplesByte(mat, vs, is, js)
      vs
    }

    override def setTuples(mat: Buffer, is: Array[Long], js: Array[Long], vs: Array[Byte]): Long = {
      val nvals = is.length
      assert(is.length == js.length, vs.length)
      GRAPHBLAS.buildMatrixFromTuplesByte(mat, is, js, vs, nvals, GRAPHBLAS.firstBinaryOpByte())
    }
  }

  implicit val shortMatrixHandler: SparseMatrixHandler[Short] = new SparseMatrixHandler[Short] {
    def createMatrix(rows: Long, cols: Long): Buffer = GRBCORE.createMatrix(GRAPHBLAS.shortType(), rows, cols)

    def get(mat: Buffer)(i: Long, j: Long): Array[Short] = GRAPHBLAS.getMatrixElementShort(mat, i, j)

    def set(mat: Buffer)(i: Long, j: Long, t: Short): Unit = GRAPHBLAS.setMatrixElementShort(mat, i, j, t)

    override def extractTuples(mat: Buffer): Array[Short] = {
      val nvals = GRBCORE.nvalsMatrix(mat)
      val vs = new Array[Short](nvals.toInt)
      val is = new Array[Long](nvals.toInt)
      val js = new Array[Long](nvals.toInt)
      GRAPHBLAS.extractTuplesShort(mat, vs, is, js)
      vs
    }

    override def setTuples(mat: Buffer, is: Array[Long], js: Array[Long], vs: Array[Short]): Long = {
      val nvals = is.length
      assert(is.length == js.length, vs.length)
      GRAPHBLAS.buildMatrixFromTuplesShort(mat, is, js, vs, nvals, GRAPHBLAS.firstBinaryOpShort())
    }
  }

  implicit val intMatrixHandler: SparseMatrixHandler[Int] = new SparseMatrixHandler[Int] {
    def createMatrix(rows: Long, cols: Long): Buffer = GRBCORE.createMatrix(GRAPHBLAS.intType(), rows, cols)

    def get(mat: Buffer)(i: Long, j: Long): Array[Int] = GRAPHBLAS.getMatrixElementInt(mat, i, j)

    def set(mat: Buffer)(i: Long, j: Long, t: Int): Unit = GRAPHBLAS.setMatrixElementInt(mat, i, j, t)

    override def extractTuples(mat: Buffer): Array[Int] = {
      val nvals = GRBCORE.nvalsMatrix(mat)
      val vs = new Array[Int](nvals.toInt)
      val is = new Array[Long](nvals.toInt)
      val js = new Array[Long](nvals.toInt)
      GRAPHBLAS.extractTuplesInt(mat, vs, is, js)
      vs
    }

    override def setTuples(mat: Buffer, is: Array[Long], js: Array[Long], vs: Array[Int]): Long = {
      val nvals = is.length
      assert(is.length == js.length, vs.length)
      GRAPHBLAS.buildMatrixFromTuplesInt(mat, is, js, vs, nvals, GRAPHBLAS.firstBinaryOpInt())
    }
  }

  implicit val longMatrixHandler: SparseMatrixHandler[Long] = new SparseMatrixHandler[Long] {
    def createMatrix(rows: Long, cols: Long): Buffer = GRBCORE.createMatrix(GRAPHBLAS.longType(), rows, cols)

    def get(mat: Buffer)(i: Long, j: Long): Array[Long] = GRAPHBLAS.getMatrixElementLong(mat, i, j)

    def set(mat: Buffer)(i: Long, j: Long, t: Long): Unit = GRAPHBLAS.setMatrixElementLong(mat, i, j, t)

    override def extractTuples(mat: Buffer): Array[Long] = {
      val nvals = GRBCORE.nvalsMatrix(mat)
      val vs = new Array[Long](nvals.toInt)
      val is = new Array[Long](nvals.toInt)
      val js = new Array[Long](nvals.toInt)
      GRAPHBLAS.extractTuplesLong(mat, vs, is, js)
      vs
    }

    override def setTuples(mat: Buffer, is: Array[Long], js: Array[Long], vs: Array[Long]): Long = {
      val nvals = is.length
      assert(is.length == js.length, vs.length)
      GRAPHBLAS.buildMatrixFromTuplesLong(mat, is, js, vs, nvals, GRAPHBLAS.firstBinaryOpLong())
    }
  }

  implicit val floatMatrixHandler: SparseMatrixHandler[Float] = new SparseMatrixHandler[Float] {
    def createMatrix(rows: Long, cols: Long): Buffer = GRBCORE.createMatrix(GRAPHBLAS.floatType(), rows, cols)

    def get(mat: Buffer)(i: Long, j: Long): Array[Float] = GRAPHBLAS.getMatrixElementFloat(mat, i, j)

    def set(mat: Buffer)(i: Long, j: Long, t: Float): Unit = GRAPHBLAS.setMatrixElementFloat(mat, i, j, t)

    override def extractTuples(mat: Buffer): Array[Float] = {
      val nvals = GRBCORE.nvalsMatrix(mat)
      val vs = new Array[Float](nvals.toInt)
      val is = new Array[Long](nvals.toInt)
      val js = new Array[Long](nvals.toInt)
      GRAPHBLAS.extractTuplesFloat(mat, vs, is, js)
      vs
    }

    override def setTuples(mat: Buffer, is: Array[Long], js: Array[Long], vs: Array[Float]): Long = {
      val nvals = is.length
      assert(is.length == js.length, vs.length)
      GRAPHBLAS.buildMatrixFromTuplesFloat(mat, is, js, vs, nvals, GRAPHBLAS.firstBinaryOpFloat())
    }
  }

  implicit val doubleMatrixHandler: SparseMatrixHandler[Double] = new SparseMatrixHandler[Double] {
    def createMatrix(rows: Long, cols: Long): Buffer = GRBCORE.createMatrix(GRAPHBLAS.doubleType(), rows, cols)

    def get(mat: Buffer)(i: Long, j: Long): Array[Double] = GRAPHBLAS.getMatrixElementDouble(mat, i, j)

    def set(mat: Buffer)(i: Long, j: Long, t: Double): Unit = GRAPHBLAS.setMatrixElementDouble(mat, i, j, t)

    override def extractTuples(mat: Buffer): Array[Double] = {
      val nvals = GRBCORE.nvalsMatrix(mat)
      val vs = new Array[Double](nvals.toInt)
      val is = new Array[Long](nvals.toInt)
      val js = new Array[Long](nvals.toInt)
      GRAPHBLAS.extractTuplesDouble(mat, vs, is, js)
      vs
    }

    override def setTuples(mat: Buffer, is: Array[Long], js: Array[Long], vs: Array[Double]): Long = {
      val nvals = is.length
      assert(is.length == js.length, vs.length)
      GRAPHBLAS.buildMatrixFromTuplesDouble(mat, is, js, vs, nvals, GRAPHBLAS.firstBinaryOpDouble())
    }
  }
}