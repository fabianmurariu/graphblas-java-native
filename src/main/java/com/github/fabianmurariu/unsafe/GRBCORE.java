package com.github.fabianmurariu.unsafe;

import java.nio.Buffer;

public final class GRBCORE {

    static {
        NarSystem.loadLibrary();
    }

    public static native void initNonBlocking();
    public static native void grbWait();
    public static native void grbFinalize();

    //Matrix
    public static native Buffer createMatrix(Buffer tpe, long rows, long cols);
    public static native long nvalsMatrix(Buffer mat);
    public static native long nrows(Buffer mat);
    public static native long ncols(Buffer mat);
    public static native long clearMatrix(Buffer mat);
    public static native void freeMatrix(Buffer mat);

    public static native Buffer dupMatrix(Buffer mat);
    public static native int getFormat(Buffer mat);
    public static native void makeCSC(Buffer mat);
    public static native void makeCSR(Buffer mat);
    public static native void setHyperRatio(Buffer mat, double ratio);
    public static native double getHyperRatio(Buffer mat);
    public static native void neverHyper(Buffer mat);

    public static native void resizeMatrix(Buffer mat, long rows, long cols);
    public static native void matrixApply(Buffer outMat, Buffer mask, Buffer accum, Buffer op, Buffer firstInput, Buffer desc);

    //Vector
    public static native Buffer createVector(Buffer tpe, long size);
    public static native long nvalsVector(Buffer vec);
    public static native long size(Buffer vec);
    public static native void freeVector(Buffer vec);
    public static native long clearVec(Buffer vec);
    public static native void resizeVector(Buffer vec, long size);
    public static native Buffer dupVector(Buffer vec);

    public static native void vectorApply(Buffer outVec, Buffer mask, Buffer accum, Buffer op, Buffer firstInput, Buffer desc);

    // Semiring
    public static native Buffer createSemiring(Buffer monoidAdd, Buffer binOpMul);
    public static native void freeSemiring(Buffer semiring);

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

    public static native Buffer createDescriptor();
    public static native void setDescriptorValue(Buffer desc, int field, int value);
    public static native int getDescriptorValue(Buffer desc, int field);
    public static native void freeDescriptor(Buffer desc);
}
