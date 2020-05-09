package com.github.fabianmurariu.unsafe;

import java.nio.ByteBuffer;

public class GRBCORE {

    static {
        NarSystem.loadLibrary();
    }

    public static native void initNonBlocking();
    public static native void grbWait();
    public static native void grbFinalize();

    // generic functions on Any item types
    public static native ByteBuffer createMatrix(ByteBuffer tpe, long rows, long cols);
    public static native long nvals(ByteBuffer mat);
    public static native long nrows(ByteBuffer mat);
    public static native long ncols(ByteBuffer mat);
    public static native void free(ByteBuffer mat);
}
