package com.github.fabianmurariu.unsafe;

import java.nio.ByteBuffer;

public final class GRBALG {
    static {
        NarSystem.loadLibrary();
    }
// reduce
    public static native boolean matrixReduceAllBoolean(boolean init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer mat, ByteBuffer desc);
    public static native byte matrixReduceAllByte(byte init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer mat, ByteBuffer desc);
    public static native short matrixReduceAllShort(short init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer mat, ByteBuffer desc);
    public static native int matrixReduceAllInt(int init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer mat, ByteBuffer desc);
    public static native long matrixReduceAllLong(long init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer mat, ByteBuffer desc);
    public static native float matrixReduceAllFloat(float init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer mat, ByteBuffer desc);
    public static native double matrixReduceAllDouble(double init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer mat, ByteBuffer desc);
    public static native boolean vectorReduceAllBoolean(boolean init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer vec, ByteBuffer desc);
    public static native byte vectorReduceAllByte(byte init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer vec, ByteBuffer desc);
    public static native short vectorReduceAllShort(short init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer vec, ByteBuffer desc);
    public static native int vectorReduceAllInt(int init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer vec, ByteBuffer desc);
    public static native long vectorReduceAllLong(long init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer vec, ByteBuffer desc);
    public static native float vectorReduceAllFloat(float init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer vec, ByteBuffer desc);
    public static native double vectorReduceAllDouble(double init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer vec, ByteBuffer desc);
}
