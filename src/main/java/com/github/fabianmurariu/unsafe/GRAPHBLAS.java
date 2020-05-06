package com.github.fabianmurariu.unsafe;

import java.nio.ByteBuffer;

public class GRAPHBLAS {
    static {
        NarSystem.loadLibrary();
    }

    public static native void initNonBlocking();

    // generic functions on Any item types
    public static native ByteBuffer createMatrix(ByteBuffer tpe, long rows, long cols);
    public static native long nvals(ByteBuffer mat);
    public static native long rows(ByteBuffer mat);
    public static native long cols(ByteBuffer mat);

    // GrB functions for GrB_BOOL as boolean

    public static native ByteBuffer booleanType();
    public static native void setElementBoolean(ByteBuffer mat, long rows, long cols, boolean value);
    public static native boolean[] getElementBoolean(ByteBuffer mat, long rows, long cols);

    // GrB functions for GrB_INT8 as byte

    public static native ByteBuffer byteType();
    public static native void setElementByte(ByteBuffer mat, long rows, long cols, byte value);
    public static native byte[] getElementByte(ByteBuffer mat, long rows, long cols);

    // GrB functions for GrB_INT16 as short

    public static native ByteBuffer shortType();
    public static native void setElementShort(ByteBuffer mat, long rows, long cols, short value);
    public static native short[] getElementShort(ByteBuffer mat, long rows, long cols);

    // GrB functions for GrB_INT32 as int

    public static native ByteBuffer intType();
    public static native void setElementInt(ByteBuffer mat, long rows, long cols, int value);
    public static native int[] getElementInt(ByteBuffer mat, long rows, long cols);

    // GrB functions for GrB_INT64 as long

    public static native ByteBuffer longType();
    public static native void setElementLong(ByteBuffer mat, long rows, long cols, long value);
    public static native long[] getElementLong(ByteBuffer mat, long rows, long cols);

    // GrB functions for GrB_FP32 as float

    public static native ByteBuffer floatType();
    public static native void setElementFloat(ByteBuffer mat, long rows, long cols, float value);
    public static native float[] getElementFloat(ByteBuffer mat, long rows, long cols);

    // GrB functions for GrB_FP64 as double

    public static native ByteBuffer doubleType();
    public static native void setElementDouble(ByteBuffer mat, long rows, long cols, double value);
    public static native double[] getElementDouble(ByteBuffer mat, long rows, long cols);

}