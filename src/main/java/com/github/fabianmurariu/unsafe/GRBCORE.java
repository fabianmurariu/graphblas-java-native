package com.github.fabianmurariu.unsafe;

import java.nio.ByteBuffer;

public final class GRBCORE {

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

    public static native ByteBuffer dupMatrix(ByteBuffer mat);
    public static native void makeCSC(ByteBuffer mat);
    public static native void makeCSR(ByteBuffer mat);
    public static native void setHyperRatio(ByteBuffer mat, double ratio);
    public static native double getHyperRatio(ByteBuffer mat, double ratio);
    public static native void neverHyper(ByteBuffer mat);

    public static native void resizeMatrix(ByteBuffer mat, long rows, long cols);
    public static native void matrixApply(ByteBuffer outMat, ByteBuffer mask, ByteBuffer accum, ByteBuffer op, ByteBuffer firstInput, ByteBuffer desc);

    //Vector
    public static native ByteBuffer createVector(ByteBuffer tpe, long size);
    public static native long nvalsVector(ByteBuffer vec);
    public static native long size(ByteBuffer vec);
    public static native void freeVector(ByteBuffer vec);
    public static native void resizeVector(ByteBuffer vec, long size);
    public static native ByteBuffer dupVector(ByteBuffer vec);

    public static native void vectorApply(ByteBuffer outVec, ByteBuffer mask, ByteBuffer accum, ByteBuffer op, ByteBuffer firstInput, ByteBuffer desc);

    // Semiring
    public static native ByteBuffer createSemiring(ByteBuffer monoidAdd, ByteBuffer binOpMul);
    public static native void freeSemiring(ByteBuffer semiring);

}
