package com.github.fabianmurariu.unsafe;

import java.nio.ByteBuffer;

// this file is generated with GRAPHBLAS.java.ftl

public class GRAPHBLAS {
    static {
        NarSystem.loadLibrary();
    }
// GrB_Type
<#list properties.types as prop>
    // GrB functions for ${prop.grb_type} as ${prop.java_type}
    public static native ByteBuffer ${prop.java_type}Type();
</#list>

// GrB_UnaryOp
<#list properties.types as prop>
    // GrB functions for ${prop.grb_type} as ${prop.java_type}
    public static native ByteBuffer ${prop.java_type}UnaryOpOne();
    public static native ByteBuffer ${prop.java_type}UnaryOpIdentity();
    public static native ByteBuffer ${prop.java_type}UnaryOpAddInv();
    public static native ByteBuffer ${prop.java_type}UnaryOpAbs();
    public static native ByteBuffer ${prop.java_type}UnaryOpMulInv();
    public static native ByteBuffer ${prop.java_type}UnaryOpLNot();
</#list>

<#list properties.types as prop>

    public static native void setMatrixElement${prop.java_type?cap_first}(ByteBuffer mat, long i, long j, ${prop.java_type} value);
    public static native ${prop.java_type}[] getMatrixElement${prop.java_type?cap_first}(ByteBuffer mat, long i, long j);

</#list>

<#list properties.types as prop>
    public static native void setVectorElement${prop.java_type?cap_first}(ByteBuffer mat, long i, ${prop.java_type} value);
    public static native ${prop.java_type}[] getVectorElement${prop.java_type?cap_first}(ByteBuffer mat, long i);

</#list>
}