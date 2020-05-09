package com.github.fabianmurariu.unsafe;

import java.nio.ByteBuffer;

public class GRBCORE {

    static {
        NarSystem.loadLibrary();
    }

    public static native void initNonBlocking();
    public static native void grbWait();
    public static native void grbFinalize();

    //Matrix
    public static native ByteBuffer createMatrix(ByteBuffer tpe, long rows, long cols);
    public static native long nvalsMatrix(ByteBuffer mat);
    public static native long nrows(ByteBuffer mat);
    public static native long ncols(ByteBuffer mat);
    public static native void freeMatrix(ByteBuffer mat);
    public static native void resizeMatrix(ByteBuffer mat, long rows, long cols);

    //Vector
    public static native ByteBuffer createVector(ByteBuffer tpe, long size);
    public static native long nvalsVector(ByteBuffer mat);
    public static native long size(ByteBuffer mat);
    public static native void freeVector(ByteBuffer mat);
    public static native void resizeVector(ByteBuffer mat, long rows, long cols);
}
