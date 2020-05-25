package com.github.fabianmurariu.unsafe;

import java.nio.Buffer;

public final class GRBALG {
    static {
        NarSystem.loadLibrary();
    }
// reduce
<#list properties.types as prop>
    public static native ${prop.java_type} matrixReduceAll${prop.java_type?cap_first}(${prop.java_type} init, Buffer accum, Buffer monoid, Buffer mat, Buffer desc);
</#list>
<#list properties.types as prop>
    public static native ${prop.java_type} vectorReduceAll${prop.java_type?cap_first}(${prop.java_type} init, Buffer accum, Buffer monoid, Buffer vec, Buffer desc);
</#list>
}
