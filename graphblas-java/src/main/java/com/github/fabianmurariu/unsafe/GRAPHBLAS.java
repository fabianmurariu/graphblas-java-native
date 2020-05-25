package com.github.fabianmurariu.unsafe;

import java.nio.Buffer;

// this file is generated with GRAPHBLAS.java.ftl

public final class GRAPHBLAS {
    static {
        NarSystem.loadLibrary();
    }
// GrB_Type
    // GrB functions for BOOL as boolean
    public static native Buffer booleanType();
    // GrB functions for INT8 as byte
    public static native Buffer byteType();
    // GrB functions for INT16 as short
    public static native Buffer shortType();
    // GrB functions for INT32 as int
    public static native Buffer intType();
    // GrB functions for INT64 as long
    public static native Buffer longType();
    // GrB functions for FP32 as float
    public static native Buffer floatType();
    // GrB functions for FP64 as double
    public static native Buffer doubleType();


    public static native void setMatrixElementBoolean(Buffer mat, long i, long j, boolean value);
    public static native boolean[] getMatrixElementBoolean(Buffer mat, long i, long j);


    public static native void setMatrixElementByte(Buffer mat, long i, long j, byte value);
    public static native byte[] getMatrixElementByte(Buffer mat, long i, long j);


    public static native void setMatrixElementShort(Buffer mat, long i, long j, short value);
    public static native short[] getMatrixElementShort(Buffer mat, long i, long j);


    public static native void setMatrixElementInt(Buffer mat, long i, long j, int value);
    public static native int[] getMatrixElementInt(Buffer mat, long i, long j);


    public static native void setMatrixElementLong(Buffer mat, long i, long j, long value);
    public static native long[] getMatrixElementLong(Buffer mat, long i, long j);


    public static native void setMatrixElementFloat(Buffer mat, long i, long j, float value);
    public static native float[] getMatrixElementFloat(Buffer mat, long i, long j);


    public static native void setMatrixElementDouble(Buffer mat, long i, long j, double value);
    public static native double[] getMatrixElementDouble(Buffer mat, long i, long j);


    public static native void setVectorElementBoolean(Buffer vec, long i, boolean value);
    public static native boolean[] getVectorElementBoolean(Buffer vec, long i);

    public static native void setVectorElementByte(Buffer vec, long i, byte value);
    public static native byte[] getVectorElementByte(Buffer vec, long i);

    public static native void setVectorElementShort(Buffer vec, long i, short value);
    public static native short[] getVectorElementShort(Buffer vec, long i);

    public static native void setVectorElementInt(Buffer vec, long i, int value);
    public static native int[] getVectorElementInt(Buffer vec, long i);

    public static native void setVectorElementLong(Buffer vec, long i, long value);
    public static native long[] getVectorElementLong(Buffer vec, long i);

    public static native void setVectorElementFloat(Buffer vec, long i, float value);
    public static native float[] getVectorElementFloat(Buffer vec, long i);

    public static native void setVectorElementDouble(Buffer vec, long i, double value);
    public static native double[] getVectorElementDouble(Buffer vec, long i);


    public static native Buffer oneUnaryOpBoolean();
    public static native Buffer identityUnaryOpBoolean();
    public static native Buffer addInvUnaryOpBoolean();
    public static native Buffer absUnaryOpBoolean();
    public static native Buffer mulInvUnaryOpBoolean();
    public static native Buffer logicalNotUnaryOpBoolean();
    public static native Buffer oneUnaryOpByte();
    public static native Buffer identityUnaryOpByte();
    public static native Buffer addInvUnaryOpByte();
    public static native Buffer absUnaryOpByte();
    public static native Buffer mulInvUnaryOpByte();
    public static native Buffer logicalNotUnaryOpByte();
    public static native Buffer oneUnaryOpShort();
    public static native Buffer identityUnaryOpShort();
    public static native Buffer addInvUnaryOpShort();
    public static native Buffer absUnaryOpShort();
    public static native Buffer mulInvUnaryOpShort();
    public static native Buffer logicalNotUnaryOpShort();
    public static native Buffer oneUnaryOpInt();
    public static native Buffer identityUnaryOpInt();
    public static native Buffer addInvUnaryOpInt();
    public static native Buffer absUnaryOpInt();
    public static native Buffer mulInvUnaryOpInt();
    public static native Buffer logicalNotUnaryOpInt();
    public static native Buffer oneUnaryOpLong();
    public static native Buffer identityUnaryOpLong();
    public static native Buffer addInvUnaryOpLong();
    public static native Buffer absUnaryOpLong();
    public static native Buffer mulInvUnaryOpLong();
    public static native Buffer logicalNotUnaryOpLong();
    public static native Buffer oneUnaryOpFloat();
    public static native Buffer identityUnaryOpFloat();
    public static native Buffer addInvUnaryOpFloat();
    public static native Buffer absUnaryOpFloat();
    public static native Buffer mulInvUnaryOpFloat();
    public static native Buffer logicalNotUnaryOpFloat();
    public static native Buffer oneUnaryOpDouble();
    public static native Buffer identityUnaryOpDouble();
    public static native Buffer addInvUnaryOpDouble();
    public static native Buffer absUnaryOpDouble();
    public static native Buffer mulInvUnaryOpDouble();
    public static native Buffer logicalNotUnaryOpDouble();

    public static native Buffer firstBinaryOpBoolean();
    public static native Buffer secondBinaryOpBoolean();
    public static native Buffer anyBinaryOpBoolean();
    public static native Buffer pairBinaryOpBoolean();
    public static native Buffer minBinaryOpBoolean();
    public static native Buffer maxBinaryOpBoolean();
    public static native Buffer plusBinaryOpBoolean();
    public static native Buffer minusBinaryOpBoolean();
    public static native Buffer rminusBinaryOpBoolean();
    public static native Buffer timesBinaryOpBoolean();
    public static native Buffer divBinaryOpBoolean();
    public static native Buffer rdivBinaryOpBoolean();
    public static native Buffer iseqBinaryOpBoolean();
    public static native Buffer isneBinaryOpBoolean();
    public static native Buffer isgtBinaryOpBoolean();
    public static native Buffer isltBinaryOpBoolean();
    public static native Buffer isgeBinaryOpBoolean();
    public static native Buffer isleBinaryOpBoolean();
    public static native Buffer lorBinaryOpBoolean();
    public static native Buffer landBinaryOpBoolean();
    public static native Buffer lxorBinaryOpBoolean();
    public static native Buffer firstBinaryOpByte();
    public static native Buffer secondBinaryOpByte();
    public static native Buffer anyBinaryOpByte();
    public static native Buffer pairBinaryOpByte();
    public static native Buffer minBinaryOpByte();
    public static native Buffer maxBinaryOpByte();
    public static native Buffer plusBinaryOpByte();
    public static native Buffer minusBinaryOpByte();
    public static native Buffer rminusBinaryOpByte();
    public static native Buffer timesBinaryOpByte();
    public static native Buffer divBinaryOpByte();
    public static native Buffer rdivBinaryOpByte();
    public static native Buffer iseqBinaryOpByte();
    public static native Buffer isneBinaryOpByte();
    public static native Buffer isgtBinaryOpByte();
    public static native Buffer isltBinaryOpByte();
    public static native Buffer isgeBinaryOpByte();
    public static native Buffer isleBinaryOpByte();
    public static native Buffer lorBinaryOpByte();
    public static native Buffer landBinaryOpByte();
    public static native Buffer lxorBinaryOpByte();
    public static native Buffer firstBinaryOpShort();
    public static native Buffer secondBinaryOpShort();
    public static native Buffer anyBinaryOpShort();
    public static native Buffer pairBinaryOpShort();
    public static native Buffer minBinaryOpShort();
    public static native Buffer maxBinaryOpShort();
    public static native Buffer plusBinaryOpShort();
    public static native Buffer minusBinaryOpShort();
    public static native Buffer rminusBinaryOpShort();
    public static native Buffer timesBinaryOpShort();
    public static native Buffer divBinaryOpShort();
    public static native Buffer rdivBinaryOpShort();
    public static native Buffer iseqBinaryOpShort();
    public static native Buffer isneBinaryOpShort();
    public static native Buffer isgtBinaryOpShort();
    public static native Buffer isltBinaryOpShort();
    public static native Buffer isgeBinaryOpShort();
    public static native Buffer isleBinaryOpShort();
    public static native Buffer lorBinaryOpShort();
    public static native Buffer landBinaryOpShort();
    public static native Buffer lxorBinaryOpShort();
    public static native Buffer firstBinaryOpInt();
    public static native Buffer secondBinaryOpInt();
    public static native Buffer anyBinaryOpInt();
    public static native Buffer pairBinaryOpInt();
    public static native Buffer minBinaryOpInt();
    public static native Buffer maxBinaryOpInt();
    public static native Buffer plusBinaryOpInt();
    public static native Buffer minusBinaryOpInt();
    public static native Buffer rminusBinaryOpInt();
    public static native Buffer timesBinaryOpInt();
    public static native Buffer divBinaryOpInt();
    public static native Buffer rdivBinaryOpInt();
    public static native Buffer iseqBinaryOpInt();
    public static native Buffer isneBinaryOpInt();
    public static native Buffer isgtBinaryOpInt();
    public static native Buffer isltBinaryOpInt();
    public static native Buffer isgeBinaryOpInt();
    public static native Buffer isleBinaryOpInt();
    public static native Buffer lorBinaryOpInt();
    public static native Buffer landBinaryOpInt();
    public static native Buffer lxorBinaryOpInt();
    public static native Buffer firstBinaryOpLong();
    public static native Buffer secondBinaryOpLong();
    public static native Buffer anyBinaryOpLong();
    public static native Buffer pairBinaryOpLong();
    public static native Buffer minBinaryOpLong();
    public static native Buffer maxBinaryOpLong();
    public static native Buffer plusBinaryOpLong();
    public static native Buffer minusBinaryOpLong();
    public static native Buffer rminusBinaryOpLong();
    public static native Buffer timesBinaryOpLong();
    public static native Buffer divBinaryOpLong();
    public static native Buffer rdivBinaryOpLong();
    public static native Buffer iseqBinaryOpLong();
    public static native Buffer isneBinaryOpLong();
    public static native Buffer isgtBinaryOpLong();
    public static native Buffer isltBinaryOpLong();
    public static native Buffer isgeBinaryOpLong();
    public static native Buffer isleBinaryOpLong();
    public static native Buffer lorBinaryOpLong();
    public static native Buffer landBinaryOpLong();
    public static native Buffer lxorBinaryOpLong();
    public static native Buffer firstBinaryOpFloat();
    public static native Buffer secondBinaryOpFloat();
    public static native Buffer anyBinaryOpFloat();
    public static native Buffer pairBinaryOpFloat();
    public static native Buffer minBinaryOpFloat();
    public static native Buffer maxBinaryOpFloat();
    public static native Buffer plusBinaryOpFloat();
    public static native Buffer minusBinaryOpFloat();
    public static native Buffer rminusBinaryOpFloat();
    public static native Buffer timesBinaryOpFloat();
    public static native Buffer divBinaryOpFloat();
    public static native Buffer rdivBinaryOpFloat();
    public static native Buffer iseqBinaryOpFloat();
    public static native Buffer isneBinaryOpFloat();
    public static native Buffer isgtBinaryOpFloat();
    public static native Buffer isltBinaryOpFloat();
    public static native Buffer isgeBinaryOpFloat();
    public static native Buffer isleBinaryOpFloat();
    public static native Buffer lorBinaryOpFloat();
    public static native Buffer landBinaryOpFloat();
    public static native Buffer lxorBinaryOpFloat();
    public static native Buffer firstBinaryOpDouble();
    public static native Buffer secondBinaryOpDouble();
    public static native Buffer anyBinaryOpDouble();
    public static native Buffer pairBinaryOpDouble();
    public static native Buffer minBinaryOpDouble();
    public static native Buffer maxBinaryOpDouble();
    public static native Buffer plusBinaryOpDouble();
    public static native Buffer minusBinaryOpDouble();
    public static native Buffer rminusBinaryOpDouble();
    public static native Buffer timesBinaryOpDouble();
    public static native Buffer divBinaryOpDouble();
    public static native Buffer rdivBinaryOpDouble();
    public static native Buffer iseqBinaryOpDouble();
    public static native Buffer isneBinaryOpDouble();
    public static native Buffer isgtBinaryOpDouble();
    public static native Buffer isltBinaryOpDouble();
    public static native Buffer isgeBinaryOpDouble();
    public static native Buffer isleBinaryOpDouble();
    public static native Buffer lorBinaryOpDouble();
    public static native Buffer landBinaryOpDouble();
    public static native Buffer lxorBinaryOpDouble();

        public static native Buffer eqBinaryOpBoolean();
        public static native Buffer neBinaryOpBoolean();
        public static native Buffer gtBinaryOpBoolean();
        public static native Buffer ltBinaryOpBoolean();
        public static native Buffer geBinaryOpBoolean();
        public static native Buffer leBinaryOpBoolean();
        public static native Buffer eqBinaryOpByte();
        public static native Buffer neBinaryOpByte();
        public static native Buffer gtBinaryOpByte();
        public static native Buffer ltBinaryOpByte();
        public static native Buffer geBinaryOpByte();
        public static native Buffer leBinaryOpByte();
        public static native Buffer eqBinaryOpShort();
        public static native Buffer neBinaryOpShort();
        public static native Buffer gtBinaryOpShort();
        public static native Buffer ltBinaryOpShort();
        public static native Buffer geBinaryOpShort();
        public static native Buffer leBinaryOpShort();
        public static native Buffer eqBinaryOpInt();
        public static native Buffer neBinaryOpInt();
        public static native Buffer gtBinaryOpInt();
        public static native Buffer ltBinaryOpInt();
        public static native Buffer geBinaryOpInt();
        public static native Buffer leBinaryOpInt();
        public static native Buffer eqBinaryOpLong();
        public static native Buffer neBinaryOpLong();
        public static native Buffer gtBinaryOpLong();
        public static native Buffer ltBinaryOpLong();
        public static native Buffer geBinaryOpLong();
        public static native Buffer leBinaryOpLong();
        public static native Buffer eqBinaryOpFloat();
        public static native Buffer neBinaryOpFloat();
        public static native Buffer gtBinaryOpFloat();
        public static native Buffer ltBinaryOpFloat();
        public static native Buffer geBinaryOpFloat();
        public static native Buffer leBinaryOpFloat();
        public static native Buffer eqBinaryOpDouble();
        public static native Buffer neBinaryOpDouble();
        public static native Buffer gtBinaryOpDouble();
        public static native Buffer ltBinaryOpDouble();
        public static native Buffer geBinaryOpDouble();
        public static native Buffer leBinaryOpDouble();

    public static native Buffer lorBinaryOp();
    public static native Buffer landBinaryOp();
    public static native Buffer lxorBinaryOp();
}