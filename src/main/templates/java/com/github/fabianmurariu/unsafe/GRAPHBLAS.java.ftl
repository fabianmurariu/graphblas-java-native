package com.github.fabianmurariu.unsafe;

import java.nio.ByteBuffer;

public class GRAPHBLAS {
    static {
        NarSystem.loadLibrary();
    }

    public static native void initNonBlocking();

    // generic functions on Any item types
    public static native ByteBuffer createMatrix(ByteBuffer tpe, long rows, long cols);
    public static native long nvals(ByteBuffer mat);
    public static native long rows(ByteBuffer mat);
    public static native long cols(ByteBuffer mat);

<#list properties as prop>
    // GrB functions for ${prop.grb_type} as ${prop.java_type}

    public static native ByteBuffer ${prop.java_type}Type();
    public static native void setElement${prop.java_type?cap_first}(ByteBuffer mat, long rows, long cols, ${prop.java_type} value);
    public static native ${prop.java_type}[] getElement${prop.java_type?cap_first}(ByteBuffer mat, long rows, long cols);

</#list>
}