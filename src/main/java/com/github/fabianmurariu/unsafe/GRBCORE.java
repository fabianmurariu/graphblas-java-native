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
    public static native int getFormat(ByteBuffer mat);
    public static native void makeCSC(ByteBuffer mat);
    public static native void makeCSR(ByteBuffer mat);
    public static native void setHyperRatio(ByteBuffer mat, double ratio);
    public static native double getHyperRatio(ByteBuffer mat);
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

    // Descriptor
    // Fields
    public static int GrB_OUTP = 0;   // descriptor for output of a method
    public static int GrB_MASK = 1;   // descriptor for the mask input of a method
    public static int GrB_INP0 = 2;   // descriptor for the first input of a method
    public static int GrB_INP1 = 3;   // descriptor for the second input of a method

    public static int GxB_DESCRIPTOR_NTHREADS = 5;     // max number of threads to use.
    public static int GxB_DESCRIPTOR_CHUNK = 7;   // chunk size for small problems.
    public static int GxB_AxB_METHOD = 1000;  // descriptor for selecting C=A*B algorithm

    // Values
    public static int GxB_DEFAULT = 0;    // default behavior of the method
    public static int GrB_REPLACE = 1;    // clear the output before assigning new values to it
    public static int GrB_COMP = 2;       // use the structural complement of the input
    public static int GrB_TRAN = 3;       // use the transpose of the input
    public static int GrB_STRUCTURE = 4;  // use the only pattern of the mask, not its values

    public static int GxB_AxB_GUSTAVSON = 1001;   // gather-scatter saxpy method
    public static int GxB_AxB_HEAP      = 1002;   // heap-based saxpy method
    public static int GxB_AxB_DOT       = 1003;   // dot product
    public static int GxB_AxB_HASH      = 1004;   // hash-based saxpy method
    public static int GxB_AxB_SAXPY     = 1005;   // saxpy method (any kind)

    public static native ByteBuffer createDescriptor();
    public static native void setDescriptorValue(ByteBuffer desc, int field, int value);
    public static native int getDescriptorValue(ByteBuffer desc, int field);
}
