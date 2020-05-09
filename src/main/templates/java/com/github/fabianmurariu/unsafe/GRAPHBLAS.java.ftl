package com.github.fabianmurariu.unsafe;

import java.nio.ByteBuffer;

// this file is generated with GRAPHBLAS.java.ftl

public class GRAPHBLAS {
    static {
        NarSystem.loadLibrary();
    }

<#list properties.types as prop>
    // GrB functions for ${prop.grb_type} as ${prop.java_type}

    public static native ByteBuffer ${prop.java_type}Type();
    public static native void setElement${prop.java_type?cap_first}(ByteBuffer mat, long rows, long cols, ${prop.java_type} value);
    public static native ${prop.java_type}[] getElement${prop.java_type?cap_first}(ByteBuffer mat, long rows, long cols);

</#list>
}