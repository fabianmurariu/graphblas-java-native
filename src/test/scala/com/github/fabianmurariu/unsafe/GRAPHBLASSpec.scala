package com.github.fabianmurariu.unsafe

import org.scalatest.BeforeAndAfterAll
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers
import org.scalatestplus.scalacheck.ScalaCheckDrivenPropertyChecks

class GRAPHBLASSpec extends AnyFlatSpec with ScalaCheckDrivenPropertyChecks with Matchers with BeforeAndAfterAll
  with MatrixUtils
  with VectorUtils
  {

  behavior of "GrB_Matrix"

    testSettersAndGettersMatrix[Boolean](GRAPHBLAS.booleanType())
      {(mat, i, j, value) => GRAPHBLAS.setMatrixElementBoolean(mat, i, j, value) }
      {(mat, i, j) => GRAPHBLAS.getMatrixElementBoolean(mat, i, j).headOption }

    testSettersAndGettersMatrix[Byte](GRAPHBLAS.byteType())
      {(mat, i, j, value) => GRAPHBLAS.setMatrixElementByte(mat, i, j, value) }
      {(mat, i, j) => GRAPHBLAS.getMatrixElementByte(mat, i, j).headOption }

    testSettersAndGettersMatrix[Short](GRAPHBLAS.shortType())
      {(mat, i, j, value) => GRAPHBLAS.setMatrixElementShort(mat, i, j, value) }
      {(mat, i, j) => GRAPHBLAS.getMatrixElementShort(mat, i, j).headOption }

  testSettersAndGettersMatrix[Int](GRAPHBLAS.intType())
    { (mat, i, j, value) => GRAPHBLAS.setMatrixElementInt(mat, i, j, value) }
    { (mat, i, j) => GRAPHBLAS.getMatrixElementInt(mat, i, j).headOption }


    testSettersAndGettersMatrix[Long](GRAPHBLAS.longType())
      {(mat, i, j, value) => GRAPHBLAS.setMatrixElementLong(mat, i, j, value) }
      {(mat, i, j) => GRAPHBLAS.getMatrixElementLong(mat, i, j).headOption }

    testSettersAndGettersMatrix[Float](GRAPHBLAS.floatType())
      {(mat, i, j, value) => GRAPHBLAS.setMatrixElementFloat(mat, i, j, value) }
      {(mat, i, j) => GRAPHBLAS.getMatrixElementFloat(mat, i, j).headOption }

    testSettersAndGettersMatrix[Double](GRAPHBLAS.doubleType())
      {(mat, i, j, value) => GRAPHBLAS.setMatrixElementDouble(mat, i, j, value) }
      {(mat, i, j) => GRAPHBLAS.getMatrixElementDouble(mat, i, j).headOption }

  behavior of "GrB_Vector"

    testSettersAndGettersVector[Boolean](GRAPHBLAS.booleanType())
    {(vec, i, value) => GRAPHBLAS.setVectorElementBoolean(vec, i, value)}
    {(vec, i) => GRAPHBLAS.getVectorElementBoolean(vec, i).headOption}

  override protected def beforeAll(): Unit = {
    GRBCORE.initNonBlocking()
  }

  override protected def afterAll(): Unit = {
    GRBCORE.grbWait()
    GRBCORE.grbFinalize()
  }
}

