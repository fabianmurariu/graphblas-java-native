package com.github.fabianmurariu.unsafe;

import java.nio.Buffer;

public final class GRBCORE {

    static {
        NarSystem.loadLibrary();
    }

    public static int GrB_SUCCESS = 0;            // all is well

    //--------------------------------------------------------------------------
    // informational codes; not an error:
    //--------------------------------------------------------------------------

    // The GraphBLAS spec lists GrB_NO_VALUE as an 'error' code; it means that
    // A(i;j) is not present in the matrix, having been requested by
    // GrB_*_extractElement.  The function cannot return the proper value
    // because the value of 'implicit zeros' depends on the semiring.  For the
    // conventational plus-times semiring, the implied 'zero' actually has the
    // value of zero.  For the max-plus semiring, it has the value -infinity.
    // A matrix does not keep track of its semiring, and the user can change
    // the semiring used to operate on the matrix.  How mathematically
    // well-defined that change of semiring is depends the user; GraphBLAS will
    // not change the explicit values in the matrix if the semiring changes.
    // As a result, GraphBLAS needs to return not a value, but an indication
    // that the value of A(i,j) is implicit.  The user application can use this
    // indicator (GrB_NO_VALUE) to use the semiring's addititive identity, or
    // it can take other action, as it chooses.  In either case, it is safe to
    // ask for values that are not there, which is why this return condition is
    // not really an 'error' code but an informational code.

    public static int GrB_NO_VALUE = 1;           // A(i,j) requested but not there

    //--------------------------------------------------------------------------
    // API errors:
    //--------------------------------------------------------------------------

    // In non-blocking mode, these errors are caught right away.

    public static int GrB_UNINITIALIZED_OBJECT = 2;   // object has not been initialized
    public static int GrB_INVALID_OBJECT = 3;         // object is corrupted
    public static int GrB_NULL_POINTER = 4;           // input pointer is NULL
    public static int GrB_INVALID_VALUE = 5;          // generic error code; some value is bad
    public static int GrB_INVALID_INDEX = 6;          // a row or column index is out of bounds;
                                    // used for indices passed as scalars, not
                                    // in a list.
    public static int GrB_DOMAIN_MISMATCH = 7;        // object domains are not compatible
    public static int GrB_DIMENSION_MISMATCH = 8;     // matrix dimensions do not match
    public static int GrB_OUTPUT_NOT_EMPTY = 9;       // output matrix already has values in it

    //--------------------------------------------------------------------------
    // execution errors:
    //--------------------------------------------------------------------------

                                    // In non-blocking mode, these errors can be deferred.

    public static int GrB_OUT_OF_MEMORY = 10;         // out of memory
    public static int GrB_INSUFFICIENT_SPACE = 11;    // output array not large enough
    public static int GrB_INDEX_OUT_OF_BOUNDS = 12;   // a row or column index is out of bounds; used for indices in a list of indices.
    public static int GrB_PANIC = 13;                  // SuiteSparse:GraphBLAS only panics if
                                                        // a critical section fails

    public static long GxB_RANGE = Long.MAX_VALUE;
    public static long GxB_STRIDE = Long.MAX_VALUE -1;
    public static long GxB_BACKWARDS = Long.MAX_VALUE -2;
    public static long NOT_REALLY_GRB_ALL = Long.MIN_VALUE; // placeholder for GrB_ALL
    public static long[] GrB_ALL = {NOT_REALLY_GRB_ALL};
    public static native long initNonBlocking();
    public static native long initBlocking();
    public static native long grbWait();
    public static native long grbFinalize();


    //Matrix
    public static native Buffer createMatrix(Buffer tpe, long rows, long cols);
    public static native long nvalsMatrix(Buffer mat);
    public static native long nrows(Buffer mat);
    public static native long ncols(Buffer mat);
    public static native long clearMatrix(Buffer mat);
    public static native long freeMatrix(Buffer mat);
    public static native long removeElementMatrix(Buffer mat, long row, long col);
    public static native Buffer dupMatrix(Buffer mat);
    public static native int getFormat(Buffer mat);
    public static native long makeCSC(Buffer mat);
    public static native long makeCSR(Buffer mat);
    public static native long setHyperRatio(Buffer mat, double ratio);
    public static native double getHyperRatio(Buffer mat);
    public static native long neverHyper(Buffer mat);

    public static native long resizeMatrix(Buffer mat, long rows, long cols);
    public static native long matrixApply(Buffer outMat, Buffer mask, Buffer accum, Buffer op, Buffer firstInput, Buffer desc);
    public static native long matrixWait(Buffer mat);

    //Vector
    public static native Buffer createVector(Buffer tpe, long size);
    public static native long nvalsVector(Buffer vec);
    public static native long size(Buffer vec);
    public static native long freeVector(Buffer vec);
    public static native long clearVec(Buffer vec);
    public static native long resizeVector(Buffer vec, long size);
    public static native Buffer dupVector(Buffer vec);
    public static native long removeElementVector(Buffer mat, long id);

    public static native long vectorApply(Buffer outVec, Buffer mask, Buffer accum, Buffer op, Buffer firstInput, Buffer desc);
    public static native long vectorWait(Buffer mat);

    // Semiring
    public static native Buffer createSemiring(Buffer monoidAdd, Buffer binOpMul);
    public static native long freeSemiring(Buffer semiring);

    // Monoid
    public static native long freeMonoid(Buffer monoid);

    // Global options
    // Fields (get and set)
    public static int GxB_HYPER = 0;
    public static int GxB_FORMAT = 1;  // defines CSR/CSC format: GxB_BY_ROW or GxB_BY_COL
    public static int GxB_NTHREADS = 5;
    public static int GxB_CHUNK = 7;

    // Fields only for get (only supporting the ones returning ints for now)
    public static int GxB_MODE = 2;  // mode passed to GrB_init (blocking or non-blocking)
    public static int GxB_THREAD_SAFETY = 3; // thread library that allows GraphBLAS to be thread-safe for user threads.
    public static int GxB_THREADING = 4;  // thread library used for internal GraphBLAS threads

    // Values
    // for GxB_FORMAT
    public static int GxB_BY_ROW = 0; // CSR
    public static int GxB_BY_COL = 1; // CSC
    public static int GxB_NO_FORMAT = -1; // not defined

    // for GrB_Mode
    public static int GrB_NONBLOCKING = 0;
    public static int GrB_BLOCKING = 1;

    public static int GxB_THREAD_NONE = 0;    // no threading
    public static int GxB_THREAD_OPENMP = 1;  // OpenMP
    public static int GxB_THREAD_POSIX = 2;  // POSIX pthreads
    public static int GxB_THREAD_WINDOWS = 3; // Windows threads
    public static int GxB_THREAD_ANSI = 4;     // ANSI C11 threads


    public static native long setGlobalInt(int field, int value);
    // f.i. for hyper ratio or chunk
    public static native long setGlobalDouble(int field, double value);
    public static native int getGlobalInt(int field);
    public static native double getGlobalDouble(int field);
    // TODO return global string value or int array? f.i. version or library date

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
    public static native long setDescriptorValue(Buffer desc, int field, int value);
    public static native int getDescriptorValue(Buffer desc, int field);
    public static native long freeDescriptor(Buffer desc);
}
