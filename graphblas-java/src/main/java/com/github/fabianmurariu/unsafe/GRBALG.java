package com.github.fabianmurariu.unsafe;

import java.nio.Buffer;

public final class GRBALG {
    static {
        NarSystem.loadLibrary();
    }
// reduce
    public static native boolean matrixReduceAllBoolean(boolean init, Buffer accum, Buffer monoid, Buffer mat, Buffer desc);
    public static native byte matrixReduceAllByte(byte init, Buffer accum, Buffer monoid, Buffer mat, Buffer desc);
    public static native short matrixReduceAllShort(short init, Buffer accum, Buffer monoid, Buffer mat, Buffer desc);
    public static native int matrixReduceAllInt(int init, Buffer accum, Buffer monoid, Buffer mat, Buffer desc);
    public static native long matrixReduceAllLong(long init, Buffer accum, Buffer monoid, Buffer mat, Buffer desc);
    public static native float matrixReduceAllFloat(float init, Buffer accum, Buffer monoid, Buffer mat, Buffer desc);
    public static native double matrixReduceAllDouble(double init, Buffer accum, Buffer monoid, Buffer mat, Buffer desc);
    public static native boolean vectorReduceAllBoolean(boolean init, Buffer accum, Buffer monoid, Buffer vec, Buffer desc);
    public static native byte vectorReduceAllByte(byte init, Buffer accum, Buffer monoid, Buffer vec, Buffer desc);
    public static native short vectorReduceAllShort(short init, Buffer accum, Buffer monoid, Buffer vec, Buffer desc);
    public static native int vectorReduceAllInt(int init, Buffer accum, Buffer monoid, Buffer vec, Buffer desc);
    public static native long vectorReduceAllLong(long init, Buffer accum, Buffer monoid, Buffer vec, Buffer desc);
    public static native float vectorReduceAllFloat(float init, Buffer accum, Buffer monoid, Buffer vec, Buffer desc);
    public static native double vectorReduceAllDouble(double init, Buffer accum, Buffer monoid, Buffer vec, Buffer desc);
}
