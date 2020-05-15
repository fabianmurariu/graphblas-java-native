package com.github.fabianmurariu.unsafe;

import java.nio.ByteBuffer;

public final class GRBALG {
    static {
        NarSystem.loadLibrary();
    }
// reduce
<#list properties.types as prop>
    public static native ${prop.java_type} matrixReduceAll${prop.java_type?cap_first}(${prop.java_type} init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer mat, ByteBuffer desc);
</#list>
<#list properties.types as prop>
    public static native ${prop.java_type} vectorReduceAll${prop.java_type?cap_first}(${prop.java_type} init, ByteBuffer accum, ByteBuffer monoid, ByteBuffer vec, ByteBuffer desc);
</#list>
}
