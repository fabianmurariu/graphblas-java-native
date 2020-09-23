package com.github.fabianmurariu.unsafe;

import java.nio.Buffer;

public class GRBOPSVEC {

    static {
        NarSystem.loadLibrary();
    }

    /**
     * {@code w<Mask> = accum (w, u.*v)}
     *
     * @param w input/output matrix for results
     * @param mask optional mask for w, unused if NULL
     * @param accum optional accum for Z=accum(w,T)
     * @param monoid defines ’.*’ for T=u.*v
     * @param u first input: vector u
     * @param v second input: vector v
     * @param desc descriptor for w, Mask, u, and v
     * @return GrB_Info status
     */
    public static native long elemWiseMulIntersectMonoid(Buffer w, Buffer mask, Buffer accum, Buffer monoid, Buffer u, Buffer v, Buffer desc);

    /**
     * {@code w<Mask> = accum (w, u.*v)}
     *
     * @param w input/output vector for results
     * @param mask optional mask for w, unused if NULL
     * @param accum optional accum for Z=accum(w,T)
     * @param binOp defines ’.*’ for T=u.*v
     * @param u first input: vector u
     * @param v second input: vector v
     * @param desc descriptor for w, Mask, u, and v
     * @return GrB_Info status
     */
    public static native long elemWiseMulIntersectBinOp(Buffer w, Buffer mask, Buffer accum, Buffer binOp, Buffer u, Buffer v, Buffer desc);

    /**
     * {@code w<Mask> = accum (w, u.+v)}
     *
     * @param w input/output vector for results
     * @param mask optional mask for w, unused if NULL
     * @param accum optional accum for Z=accum(w,T)
     * @param monoid defines ’.+’ for T=u.+v
     * @param u first input: vector u
     * @param v second input: vector v
     * @param desc descriptor for w, Mask, u, and v
     * @return GrB_Info status
     */
    public static native long elemWiseAddUnionMonoid(Buffer w, Buffer mask, Buffer accum, Buffer monoid, Buffer u, Buffer v, Buffer desc);

    /**
     * {@code w<Mask> = accum (w, u.+v)}
     *
     * @param w input/output vector for results
     * @param mask optional mask for w, unused if NULL
     * @param accum optional accum for Z=accum(w,T)
     * @param binOp defines ’.+’ for T=u.+v
     * @param u first input: vector u
     * @param v second input: vector v
     * @param desc descriptor for w, Mask, u, and v
     * @return GrB_Info status
     */
    public static native long elemWiseAddUnionBinOp(Buffer w, Buffer mask, Buffer accum, Buffer binOp, Buffer u, Buffer v, Buffer desc);

    /**
     * {@code w<Mask>(I,J) = accum (w(i),u)}
     *
     * @param w input/output vector for results
     * @param mask optional mask for w, unused if NULL
     * @param accum optional accum for Z=accum(w(I,J),T)
     * @param u first input: vector u
     * @param I row indices
     * @param ni number of row indices
     * @param desc descriptor for w, Mask, and u
     * @return GrB_Info status
     */
    public static native long assign(Buffer w, Buffer mask, Buffer accum, Buffer u, long[] I, long ni, Buffer desc);

    /**
     * {@code w(I,J)<Mask> = accum (w(i),u)}
     *
     * @param w input/output vector for results
     * @param mask optional mask for w, unused if NULL
     * @param accum optional accum for Z=accum(w(I,J),T)
     * @param u first input: vector u
     * @param I row indices
     * @param ni number of row indices
     * @param desc descriptor for w, Mask, and u
     * @return GrB_Info status
     */
    public static native long subAssign(Buffer w, Buffer mask, Buffer accum, Buffer u, long[] I, long ni, Buffer desc);

    /**
     * {@code w<Mask> = accum (w, u(i))}
     *
     * @param w input/output vector for results
     * @param mask optional mask for w, unused if NULL
     * @param accum optional accum for Z=accum(w(I,J),T)
     * @param u first input: vector u
     * @param I row indices
     * @param ni number of row indices
     * @param desc descriptor for w, Mask, and u
     * @return GrB_Info status
     */
    public static native long extract(Buffer w, Buffer mask, Buffer accum, Buffer u, long[] I, long ni, Buffer desc);
}
