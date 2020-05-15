package com.github.fabianmurariu.unsafe;

import java.nio.ByteBuffer;

// this file is generated with GRAPHBLAS.java.ftl

public final class GRAPHBLAS {
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


    public static native void setVectorElementBoolean(ByteBuffer vec, long i, boolean value);
    public static native boolean[] getVectorElementBoolean(ByteBuffer vec, long i);

    public static native void setVectorElementByte(ByteBuffer vec, long i, byte value);
    public static native byte[] getVectorElementByte(ByteBuffer vec, long i);

    public static native void setVectorElementShort(ByteBuffer vec, long i, short value);
    public static native short[] getVectorElementShort(ByteBuffer vec, long i);

    public static native void setVectorElementInt(ByteBuffer vec, long i, int value);
    public static native int[] getVectorElementInt(ByteBuffer vec, long i);

    public static native void setVectorElementLong(ByteBuffer vec, long i, long value);
    public static native long[] getVectorElementLong(ByteBuffer vec, long i);

    public static native void setVectorElementFloat(ByteBuffer vec, long i, float value);
    public static native float[] getVectorElementFloat(ByteBuffer vec, long i);

    public static native void setVectorElementDouble(ByteBuffer vec, long i, double value);
    public static native double[] getVectorElementDouble(ByteBuffer vec, long i);


    public static native ByteBuffer oneUnaryOpBoolean();
    public static native ByteBuffer identityUnaryOpBoolean();
    public static native ByteBuffer addInvUnaryOpBoolean();
    public static native ByteBuffer absUnaryOpBoolean();
    public static native ByteBuffer mulInvUnaryOpBoolean();
    public static native ByteBuffer logicalNotUnaryOpBoolean();
    public static native ByteBuffer oneUnaryOpByte();
    public static native ByteBuffer identityUnaryOpByte();
    public static native ByteBuffer addInvUnaryOpByte();
    public static native ByteBuffer absUnaryOpByte();
    public static native ByteBuffer mulInvUnaryOpByte();
    public static native ByteBuffer logicalNotUnaryOpByte();
    public static native ByteBuffer oneUnaryOpShort();
    public static native ByteBuffer identityUnaryOpShort();
    public static native ByteBuffer addInvUnaryOpShort();
    public static native ByteBuffer absUnaryOpShort();
    public static native ByteBuffer mulInvUnaryOpShort();
    public static native ByteBuffer logicalNotUnaryOpShort();
    public static native ByteBuffer oneUnaryOpInt();
    public static native ByteBuffer identityUnaryOpInt();
    public static native ByteBuffer addInvUnaryOpInt();
    public static native ByteBuffer absUnaryOpInt();
    public static native ByteBuffer mulInvUnaryOpInt();
    public static native ByteBuffer logicalNotUnaryOpInt();
    public static native ByteBuffer oneUnaryOpLong();
    public static native ByteBuffer identityUnaryOpLong();
    public static native ByteBuffer addInvUnaryOpLong();
    public static native ByteBuffer absUnaryOpLong();
    public static native ByteBuffer mulInvUnaryOpLong();
    public static native ByteBuffer logicalNotUnaryOpLong();
    public static native ByteBuffer oneUnaryOpFloat();
    public static native ByteBuffer identityUnaryOpFloat();
    public static native ByteBuffer addInvUnaryOpFloat();
    public static native ByteBuffer absUnaryOpFloat();
    public static native ByteBuffer mulInvUnaryOpFloat();
    public static native ByteBuffer logicalNotUnaryOpFloat();
    public static native ByteBuffer oneUnaryOpDouble();
    public static native ByteBuffer identityUnaryOpDouble();
    public static native ByteBuffer addInvUnaryOpDouble();
    public static native ByteBuffer absUnaryOpDouble();
    public static native ByteBuffer mulInvUnaryOpDouble();
    public static native ByteBuffer logicalNotUnaryOpDouble();

    public static native ByteBuffer firstBinaryOpBoolean();
    public static native ByteBuffer secondBinaryOpBoolean();
    public static native ByteBuffer anyBinaryOpBoolean();
    public static native ByteBuffer pairBinaryOpBoolean();
    public static native ByteBuffer minBinaryOpBoolean();
    public static native ByteBuffer maxBinaryOpBoolean();
    public static native ByteBuffer plusBinaryOpBoolean();
    public static native ByteBuffer minusBinaryOpBoolean();
    public static native ByteBuffer rminusBinaryOpBoolean();
    public static native ByteBuffer timesBinaryOpBoolean();
    public static native ByteBuffer divBinaryOpBoolean();
    public static native ByteBuffer rdivBinaryOpBoolean();
    public static native ByteBuffer iseqBinaryOpBoolean();
    public static native ByteBuffer isneBinaryOpBoolean();
    public static native ByteBuffer isgtBinaryOpBoolean();
    public static native ByteBuffer isltBinaryOpBoolean();
    public static native ByteBuffer isgeBinaryOpBoolean();
    public static native ByteBuffer isleBinaryOpBoolean();
    public static native ByteBuffer lorBinaryOpBoolean();
    public static native ByteBuffer landBinaryOpBoolean();
    public static native ByteBuffer lxorBinaryOpBoolean();
    public static native ByteBuffer firstBinaryOpByte();
    public static native ByteBuffer secondBinaryOpByte();
    public static native ByteBuffer anyBinaryOpByte();
    public static native ByteBuffer pairBinaryOpByte();
    public static native ByteBuffer minBinaryOpByte();
    public static native ByteBuffer maxBinaryOpByte();
    public static native ByteBuffer plusBinaryOpByte();
    public static native ByteBuffer minusBinaryOpByte();
    public static native ByteBuffer rminusBinaryOpByte();
    public static native ByteBuffer timesBinaryOpByte();
    public static native ByteBuffer divBinaryOpByte();
    public static native ByteBuffer rdivBinaryOpByte();
    public static native ByteBuffer iseqBinaryOpByte();
    public static native ByteBuffer isneBinaryOpByte();
    public static native ByteBuffer isgtBinaryOpByte();
    public static native ByteBuffer isltBinaryOpByte();
    public static native ByteBuffer isgeBinaryOpByte();
    public static native ByteBuffer isleBinaryOpByte();
    public static native ByteBuffer lorBinaryOpByte();
    public static native ByteBuffer landBinaryOpByte();
    public static native ByteBuffer lxorBinaryOpByte();
    public static native ByteBuffer firstBinaryOpShort();
    public static native ByteBuffer secondBinaryOpShort();
    public static native ByteBuffer anyBinaryOpShort();
    public static native ByteBuffer pairBinaryOpShort();
    public static native ByteBuffer minBinaryOpShort();
    public static native ByteBuffer maxBinaryOpShort();
    public static native ByteBuffer plusBinaryOpShort();
    public static native ByteBuffer minusBinaryOpShort();
    public static native ByteBuffer rminusBinaryOpShort();
    public static native ByteBuffer timesBinaryOpShort();
    public static native ByteBuffer divBinaryOpShort();
    public static native ByteBuffer rdivBinaryOpShort();
    public static native ByteBuffer iseqBinaryOpShort();
    public static native ByteBuffer isneBinaryOpShort();
    public static native ByteBuffer isgtBinaryOpShort();
    public static native ByteBuffer isltBinaryOpShort();
    public static native ByteBuffer isgeBinaryOpShort();
    public static native ByteBuffer isleBinaryOpShort();
    public static native ByteBuffer lorBinaryOpShort();
    public static native ByteBuffer landBinaryOpShort();
    public static native ByteBuffer lxorBinaryOpShort();
    public static native ByteBuffer firstBinaryOpInt();
    public static native ByteBuffer secondBinaryOpInt();
    public static native ByteBuffer anyBinaryOpInt();
    public static native ByteBuffer pairBinaryOpInt();
    public static native ByteBuffer minBinaryOpInt();
    public static native ByteBuffer maxBinaryOpInt();
    public static native ByteBuffer plusBinaryOpInt();
    public static native ByteBuffer minusBinaryOpInt();
    public static native ByteBuffer rminusBinaryOpInt();
    public static native ByteBuffer timesBinaryOpInt();
    public static native ByteBuffer divBinaryOpInt();
    public static native ByteBuffer rdivBinaryOpInt();
    public static native ByteBuffer iseqBinaryOpInt();
    public static native ByteBuffer isneBinaryOpInt();
    public static native ByteBuffer isgtBinaryOpInt();
    public static native ByteBuffer isltBinaryOpInt();
    public static native ByteBuffer isgeBinaryOpInt();
    public static native ByteBuffer isleBinaryOpInt();
    public static native ByteBuffer lorBinaryOpInt();
    public static native ByteBuffer landBinaryOpInt();
    public static native ByteBuffer lxorBinaryOpInt();
    public static native ByteBuffer firstBinaryOpLong();
    public static native ByteBuffer secondBinaryOpLong();
    public static native ByteBuffer anyBinaryOpLong();
    public static native ByteBuffer pairBinaryOpLong();
    public static native ByteBuffer minBinaryOpLong();
    public static native ByteBuffer maxBinaryOpLong();
    public static native ByteBuffer plusBinaryOpLong();
    public static native ByteBuffer minusBinaryOpLong();
    public static native ByteBuffer rminusBinaryOpLong();
    public static native ByteBuffer timesBinaryOpLong();
    public static native ByteBuffer divBinaryOpLong();
    public static native ByteBuffer rdivBinaryOpLong();
    public static native ByteBuffer iseqBinaryOpLong();
    public static native ByteBuffer isneBinaryOpLong();
    public static native ByteBuffer isgtBinaryOpLong();
    public static native ByteBuffer isltBinaryOpLong();
    public static native ByteBuffer isgeBinaryOpLong();
    public static native ByteBuffer isleBinaryOpLong();
    public static native ByteBuffer lorBinaryOpLong();
    public static native ByteBuffer landBinaryOpLong();
    public static native ByteBuffer lxorBinaryOpLong();
    public static native ByteBuffer firstBinaryOpFloat();
    public static native ByteBuffer secondBinaryOpFloat();
    public static native ByteBuffer anyBinaryOpFloat();
    public static native ByteBuffer pairBinaryOpFloat();
    public static native ByteBuffer minBinaryOpFloat();
    public static native ByteBuffer maxBinaryOpFloat();
    public static native ByteBuffer plusBinaryOpFloat();
    public static native ByteBuffer minusBinaryOpFloat();
    public static native ByteBuffer rminusBinaryOpFloat();
    public static native ByteBuffer timesBinaryOpFloat();
    public static native ByteBuffer divBinaryOpFloat();
    public static native ByteBuffer rdivBinaryOpFloat();
    public static native ByteBuffer iseqBinaryOpFloat();
    public static native ByteBuffer isneBinaryOpFloat();
    public static native ByteBuffer isgtBinaryOpFloat();
    public static native ByteBuffer isltBinaryOpFloat();
    public static native ByteBuffer isgeBinaryOpFloat();
    public static native ByteBuffer isleBinaryOpFloat();
    public static native ByteBuffer lorBinaryOpFloat();
    public static native ByteBuffer landBinaryOpFloat();
    public static native ByteBuffer lxorBinaryOpFloat();
    public static native ByteBuffer firstBinaryOpDouble();
    public static native ByteBuffer secondBinaryOpDouble();
    public static native ByteBuffer anyBinaryOpDouble();
    public static native ByteBuffer pairBinaryOpDouble();
    public static native ByteBuffer minBinaryOpDouble();
    public static native ByteBuffer maxBinaryOpDouble();
    public static native ByteBuffer plusBinaryOpDouble();
    public static native ByteBuffer minusBinaryOpDouble();
    public static native ByteBuffer rminusBinaryOpDouble();
    public static native ByteBuffer timesBinaryOpDouble();
    public static native ByteBuffer divBinaryOpDouble();
    public static native ByteBuffer rdivBinaryOpDouble();
    public static native ByteBuffer iseqBinaryOpDouble();
    public static native ByteBuffer isneBinaryOpDouble();
    public static native ByteBuffer isgtBinaryOpDouble();
    public static native ByteBuffer isltBinaryOpDouble();
    public static native ByteBuffer isgeBinaryOpDouble();
    public static native ByteBuffer isleBinaryOpDouble();
    public static native ByteBuffer lorBinaryOpDouble();
    public static native ByteBuffer landBinaryOpDouble();
    public static native ByteBuffer lxorBinaryOpDouble();

        public static native ByteBuffer eqBinaryOpBoolean();
        public static native ByteBuffer neBinaryOpBoolean();
        public static native ByteBuffer gtBinaryOpBoolean();
        public static native ByteBuffer ltBinaryOpBoolean();
        public static native ByteBuffer geBinaryOpBoolean();
        public static native ByteBuffer leBinaryOpBoolean();
        public static native ByteBuffer eqBinaryOpByte();
        public static native ByteBuffer neBinaryOpByte();
        public static native ByteBuffer gtBinaryOpByte();
        public static native ByteBuffer ltBinaryOpByte();
        public static native ByteBuffer geBinaryOpByte();
        public static native ByteBuffer leBinaryOpByte();
        public static native ByteBuffer eqBinaryOpShort();
        public static native ByteBuffer neBinaryOpShort();
        public static native ByteBuffer gtBinaryOpShort();
        public static native ByteBuffer ltBinaryOpShort();
        public static native ByteBuffer geBinaryOpShort();
        public static native ByteBuffer leBinaryOpShort();
        public static native ByteBuffer eqBinaryOpInt();
        public static native ByteBuffer neBinaryOpInt();
        public static native ByteBuffer gtBinaryOpInt();
        public static native ByteBuffer ltBinaryOpInt();
        public static native ByteBuffer geBinaryOpInt();
        public static native ByteBuffer leBinaryOpInt();
        public static native ByteBuffer eqBinaryOpLong();
        public static native ByteBuffer neBinaryOpLong();
        public static native ByteBuffer gtBinaryOpLong();
        public static native ByteBuffer ltBinaryOpLong();
        public static native ByteBuffer geBinaryOpLong();
        public static native ByteBuffer leBinaryOpLong();
        public static native ByteBuffer eqBinaryOpFloat();
        public static native ByteBuffer neBinaryOpFloat();
        public static native ByteBuffer gtBinaryOpFloat();
        public static native ByteBuffer ltBinaryOpFloat();
        public static native ByteBuffer geBinaryOpFloat();
        public static native ByteBuffer leBinaryOpFloat();
        public static native ByteBuffer eqBinaryOpDouble();
        public static native ByteBuffer neBinaryOpDouble();
        public static native ByteBuffer gtBinaryOpDouble();
        public static native ByteBuffer ltBinaryOpDouble();
        public static native ByteBuffer geBinaryOpDouble();
        public static native ByteBuffer leBinaryOpDouble();

    public static native ByteBuffer lorBinaryOp();
    public static native ByteBuffer landBinaryOp();
    public static native ByteBuffer lxorBinaryOp();
}