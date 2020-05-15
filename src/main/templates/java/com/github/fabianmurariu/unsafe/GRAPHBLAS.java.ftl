package com.github.fabianmurariu.unsafe;

import java.nio.ByteBuffer;

// this file is generated with GRAPHBLAS.java.ftl

public final class GRAPHBLAS {
    static {
        NarSystem.loadLibrary();
    }
// GrB_Type
<#list properties.types as prop>
    // GrB functions for ${prop.grb_type} as ${prop.java_type}
    public static native ByteBuffer ${prop.java_type}Type();
</#list>

<#list properties.types as prop>

    public static native void setMatrixElement${prop.java_type?cap_first}(ByteBuffer mat, long i, long j, ${prop.java_type} value);
    public static native ${prop.java_type}[] getMatrixElement${prop.java_type?cap_first}(ByteBuffer mat, long i, long j);

</#list>

<#list properties.types as prop>
    public static native void setVectorElement${prop.java_type?cap_first}(ByteBuffer vec, long i, ${prop.java_type} value);
    public static native ${prop.java_type}[] getVectorElement${prop.java_type?cap_first}(ByteBuffer vec, long i);

</#list>

<#list properties.types as prop>
    <#list properties.unary_ops as uop>
    public static native ByteBuffer ${uop.name}UnaryOp${prop.java_type?cap_first}();
    </#list>
</#list>

<#list properties.types as prop>
    <#list properties.binary_ops as op>
    public static native ByteBuffer ${op.name}BinaryOp${prop.java_type?cap_first}();
    </#list>
</#list>

<#list properties.types as prop>
    <#list properties.binary_ops_bool as op>
        public static native ByteBuffer ${op.name}BinaryOp${prop.java_type?cap_first}();
    </#list>
</#list>

<#list properties.binary_ops_bool_bool as op>
    public static native ByteBuffer ${op.name}BinaryOp();
</#list>
}