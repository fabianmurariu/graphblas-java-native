package com.github.fabianmurariu.unsafe;

import java.nio.ByteBuffer;

// this file is generated with GRAPHBLAS.java.ftl

public class GRAPHBLAS {
    static {
        NarSystem.loadLibrary();
    }
// GrB_Type
    // GrB functions for BOOL as boolean
    public static native ByteBuffer booleanType();
    // GrB functions for INT8 as byte
    public static native ByteBuffer byteType();
    // GrB functions for INT16 as short
    public static native ByteBuffer shortType();
    // GrB functions for INT32 as int
    public static native ByteBuffer intType();
    // GrB functions for INT64 as long
    public static native ByteBuffer longType();
    // GrB functions for FP32 as float
    public static native ByteBuffer floatType();
    // GrB functions for FP64 as double
    public static native ByteBuffer doubleType();

// GrB_UnaryOp
    // GrB functions for BOOL as boolean
    public static native ByteBuffer booleanUnaryOpOne();
    public static native ByteBuffer booleanUnaryOpIdentity();
    public static native ByteBuffer booleanUnaryOpAddInv();
    public static native ByteBuffer booleanUnaryOpAbs();
    public static native ByteBuffer booleanUnaryOpMulInv();
    public static native ByteBuffer booleanUnaryOpLNot();
    // GrB functions for INT8 as byte
    public static native ByteBuffer byteUnaryOpOne();
    public static native ByteBuffer byteUnaryOpIdentity();
    public static native ByteBuffer byteUnaryOpAddInv();
    public static native ByteBuffer byteUnaryOpAbs();
    public static native ByteBuffer byteUnaryOpMulInv();
    public static native ByteBuffer byteUnaryOpLNot();
    // GrB functions for INT16 as short
    public static native ByteBuffer shortUnaryOpOne();
    public static native ByteBuffer shortUnaryOpIdentity();
    public static native ByteBuffer shortUnaryOpAddInv();
    public static native ByteBuffer shortUnaryOpAbs();
    public static native ByteBuffer shortUnaryOpMulInv();
    public static native ByteBuffer shortUnaryOpLNot();
    // GrB functions for INT32 as int
    public static native ByteBuffer intUnaryOpOne();
    public static native ByteBuffer intUnaryOpIdentity();
    public static native ByteBuffer intUnaryOpAddInv();
    public static native ByteBuffer intUnaryOpAbs();
    public static native ByteBuffer intUnaryOpMulInv();
    public static native ByteBuffer intUnaryOpLNot();
    // GrB functions for INT64 as long
    public static native ByteBuffer longUnaryOpOne();
    public static native ByteBuffer longUnaryOpIdentity();
    public static native ByteBuffer longUnaryOpAddInv();
    public static native ByteBuffer longUnaryOpAbs();
    public static native ByteBuffer longUnaryOpMulInv();
    public static native ByteBuffer longUnaryOpLNot();
    // GrB functions for FP32 as float
    public static native ByteBuffer floatUnaryOpOne();
    public static native ByteBuffer floatUnaryOpIdentity();
    public static native ByteBuffer floatUnaryOpAddInv();
    public static native ByteBuffer floatUnaryOpAbs();
    public static native ByteBuffer floatUnaryOpMulInv();
    public static native ByteBuffer floatUnaryOpLNot();
    // GrB functions for FP64 as double
    public static native ByteBuffer doubleUnaryOpOne();
    public static native ByteBuffer doubleUnaryOpIdentity();
    public static native ByteBuffer doubleUnaryOpAddInv();
    public static native ByteBuffer doubleUnaryOpAbs();
    public static native ByteBuffer doubleUnaryOpMulInv();
    public static native ByteBuffer doubleUnaryOpLNot();


    public static native void setMatrixElementBoolean(ByteBuffer mat, long i, long j, boolean value);
    public static native boolean[] getMatrixElementBoolean(ByteBuffer mat, long i, long j);


    public static native void setMatrixElementByte(ByteBuffer mat, long i, long j, byte value);
    public static native byte[] getMatrixElementByte(ByteBuffer mat, long i, long j);


    public static native void setMatrixElementShort(ByteBuffer mat, long i, long j, short value);
    public static native short[] getMatrixElementShort(ByteBuffer mat, long i, long j);


    public static native void setMatrixElementInt(ByteBuffer mat, long i, long j, int value);
    public static native int[] getMatrixElementInt(ByteBuffer mat, long i, long j);


    public static native void setMatrixElementLong(ByteBuffer mat, long i, long j, long value);
    public static native long[] getMatrixElementLong(ByteBuffer mat, long i, long j);


    public static native void setMatrixElementFloat(ByteBuffer mat, long i, long j, float value);
    public static native float[] getMatrixElementFloat(ByteBuffer mat, long i, long j);


    public static native void setMatrixElementDouble(ByteBuffer mat, long i, long j, double value);
    public static native double[] getMatrixElementDouble(ByteBuffer mat, long i, long j);


    public static native void setVectorElementBoolean(ByteBuffer mat, long i, boolean value);
    public static native boolean[] getVectorElementBoolean(ByteBuffer mat, long i);

    public static native void setVectorElementByte(ByteBuffer mat, long i, byte value);
    public static native byte[] getVectorElementByte(ByteBuffer mat, long i);

    public static native void setVectorElementShort(ByteBuffer mat, long i, short value);
    public static native short[] getVectorElementShort(ByteBuffer mat, long i);

    public static native void setVectorElementInt(ByteBuffer mat, long i, int value);
    public static native int[] getVectorElementInt(ByteBuffer mat, long i);

    public static native void setVectorElementLong(ByteBuffer mat, long i, long value);
    public static native long[] getVectorElementLong(ByteBuffer mat, long i);

    public static native void setVectorElementFloat(ByteBuffer mat, long i, float value);
    public static native float[] getVectorElementFloat(ByteBuffer mat, long i);

    public static native void setVectorElementDouble(ByteBuffer mat, long i, double value);
    public static native double[] getVectorElementDouble(ByteBuffer mat, long i);

}