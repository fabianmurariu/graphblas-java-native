package com.github.fabianmurariu.unsafe;

import java.nio.Buffer;

public class GRBOPSMAT {

    static {
        NarSystem.loadLibrary();
    }

    /**
     * {@code C<Mask> = accum (C, A*B)}
     *
     * @param C input/output matrix for results
     * @param mask optional mask for C, unused if NULL
     * @param accum optional accum for Z=accum(C,T)
     * @param semiring defines ’+’ and ’*’ for A*B
     * @param A first input: matrix A
     * @param B second input: matrix B
     * @param desc descriptor for C, Mask, A, and B
     * @return GrB_Info status
     */
    public static native int mxm(Buffer C, Buffer mask, Buffer accum, Buffer semiring, Buffer A, Buffer B, Buffer desc);

    /**
     * {@code C<Mask> = accum (C, u'*A)}
     *
     * @param w input/output vector for results
     * @param mask optional mask for C, unused if NULL
     * @param accum optional accum for Z=accum(C,T)
     * @param semiring defines ’+’ and ’*’ for A*B
     * @param u first input: vector u
     * @param A second input: matrix A
     * @param desc descriptor for C, Mask, A, and B
     * @return GrB_Info status
     */
    public static native int vxm(Buffer w, Buffer mask, Buffer accum, Buffer semiring, Buffer u, Buffer A, Buffer desc);

    /**
     * {@code C<Mask> = accum (C, A*u)}
     *
     * @param w input/output vector for results
     * @param mask optional mask for C, unused if NULL
     * @param accum optional accum for Z=accum(C,T)
     * @param semiring defines ’+’ and ’*’ for A*B
     * @param A first input: matrix A
     * @param u second input: vector u
     * @param desc descriptor for C, Mask, A, and B
     * @return GrB_Info status
     */
    public static native int mxv(Buffer w, Buffer mask, Buffer accum, Buffer semiring, Buffer A, Buffer u, Buffer desc);

    /**
     * {@code C<Mask> = accum (C, A.*B)}
     *
     * @param C input/output matrix for results
     * @param mask optional mask for C, unused if NULL
     * @param accum optional accum for Z=accum(C,T)
     * @param monoid defines ’.*’ for T=A.*B
     * @param A first input: matrix A
     * @param B second input: matrix B
     * @param desc descriptor for C, Mask, A, and B
     * @return GrB_Info status
     */
    public static native int elemWiseMulIntersectMonoid(Buffer C, Buffer mask, Buffer accum, Buffer monoid, Buffer A, Buffer B, Buffer desc);

    /**
     * {@code C<Mask> = accum (C, A.*B)}
     *
     * @param C input/output matrix for results
     * @param mask optional mask for C, unused if NULL
     * @param accum optional accum for Z=accum(C,T)
     * @param binOp defines ’.*’ for T=A.*B
     * @param A first input: matrix A
     * @param B second input: matrix B
     * @param desc descriptor for C, Mask, A, and B
     * @return GrB_Info status
     */
    public static native int elemWiseMulIntersectBinOp(Buffer C, Buffer mask, Buffer accum, Buffer binOp, Buffer A, Buffer B, Buffer desc);

    /**
     * {@code C<Mask> = accum (C, A.+B)}
     *
     * @param C input/output matrix for results
     * @param mask optional mask for C, unused if NULL
     * @param accum optional accum for Z=accum(C,T)
     * @param monoid defines ’.+’ for T=A.+B
     * @param A first input: matrix A
     * @param B second input: matrix B
     * @param desc descriptor for C, Mask, A, and B
     * @return GrB_Info status
     */
    public static native int elemWiseAddUnionMonoid(Buffer C, Buffer mask, Buffer accum, Buffer monoid, Buffer A, Buffer B, Buffer desc);

    /**
     * {@code C<Mask> = accum (C, A.+B)}
     *
     * @param C input/output matrix for results
     * @param mask optional mask for C, unused if NULL
     * @param accum optional accum for Z=accum(C,T)
     * @param binOp defines ’.+’ for T=A.+B
     * @param A first input: matrix A
     * @param B second input: matrix B
     * @param desc descriptor for C, Mask, A, and B
     * @return GrB_Info status
     */
    public static native int elemWiseAddUnionBinOp(Buffer C, Buffer mask, Buffer accum, Buffer binOp, Buffer A, Buffer B, Buffer desc);

    /**
     * {@code C<Mask>(I,J) = accum (C(I,J),A)}
     *
     * @param C input/output matrix for results
     * @param mask optional mask for C, unused if NULL
     * @param accum optional accum for Z=accum(C(I,J),T)
     * @param A first input: matrix A
     * @param I row indices
     * @param ni number of row indices
     * @param J column indices
     * @param nj number of column indices
     * @param desc descriptor for C, Mask, and A
     * @return GrB_Info status
     */
    public static native long assign(Buffer C, Buffer mask, Buffer accum, Buffer A, long[] I, long ni, long[] J, long nj, Buffer desc);

    /**
     * {@code C(I,J)<Mask> = accum (C(I,J),A)}
     *
     * @param C input/output matrix for results
     * @param mask optional mask for C, unused if NULL
     * @param accum optional accum for Z=accum(C(I,J),T)
     * @param A first input: matrix A
     * @param I row indices
     * @param ni number of row indices
     * @param J column indices
     * @param nj number of column indices
     * @param desc descriptor for C, Mask, and A
     * @return GrB_Info status
     */
    public static native long subAssign(Buffer C, Buffer mask, Buffer accum, Buffer A, long[] I, long ni, long[] J, long nj, Buffer desc);

    /**
     * {@code C<Mask> = accum (C, A(I,J))}
     *
     * @param C input/output matrix for results
     * @param mask optional mask for C, unused if NULL
     * @param accum optional accum for Z=accum(C(I,J),T)
     * @param A first input: matrix A
     * @param I row indices
     * @param ni number of row indices
     * @param J column indices
     * @param nj number of column indices
     * @param desc descriptor for C, Mask, and A
     * @return GrB_Info status
     */
    public static native long extract(Buffer C, Buffer mask, Buffer accum, Buffer A, long[] I, long ni, long[] J, long nj, Buffer desc);

//  w<mask> = accum (w,reduce(A))
//    input/output vector for results
//    optional mask for w, unused if NULL
//    optional accum for z=accum(w,t)
//    reduce operator for t=reduce(A)
//    first input: matrix A
//    descriptor for w, mask, and A
    public static native long matrixReduceBinOp(Buffer vec, Buffer mask, Buffer accum, Buffer binOp, Buffer mat, Buffer desc);

    //  w<mask> = accum (w,reduce(A))
//    input/output vector for results
//    optional mask for w, unused if NULL
//    optional accum for z=accum(w,t)
//    reduce operator for t=reduce(A)
//    first input: matrix A
//    descriptor for w, mask, and A
    public static native long matrixReduceMonoid(Buffer vec, Buffer mask, Buffer accum, Buffer monoid, Buffer mat, Buffer desc);

// C<Mask> = accum (C, A’)
//    input/output matrix for results
//    optional mask for C, unused if NULL
//    optional accum for Z=accum(C,T)
//    first input: matrix A
//    descriptor for C, Mask, and A
    public static native long transpose(Buffer out, Buffer mask, Buffer accum, Buffer mat, Buffer desc);
}
