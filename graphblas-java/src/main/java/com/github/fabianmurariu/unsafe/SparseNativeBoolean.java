package com.github.fabianmurariu.unsafe;

public class SparseNativeBoolean {
    public final boolean[] vs;
    public final long[] is;
    public final long[] js;

    public SparseNativeBoolean(int nvals) {
        vs = new boolean[nvals];
        is = new long[nvals];
        js = new long[nvals];
    }
}
