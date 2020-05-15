package com.github.fabianmurariu.unsafe;

import java.nio.ByteBuffer;

public final class GRBMONOID {
    static {
        NarSystem.loadLibrary();
    }

// TODO: add createMonoid and freeMonoid

<#list properties.types as prop>
    <#if prop.java_type != "boolean" >
    <#list properties.monoids as op>
    public static native ByteBuffer ${op.name}Monoid${prop.java_type?cap_first}();
    </#list>
    </#if>
</#list>
    // only applicable to aplicable to bool sparse matrix or vector, returns bool
    <#list properties.monoids_bool as op>
    public static native ByteBuffer ${op.name}Monoid();
    </#list>
}
