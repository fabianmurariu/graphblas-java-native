package com.github.fabianmurariu.unsafe;

import java.nio.Buffer;

public final class GRBMONOID {
    static {
        NarSystem.loadLibrary();
    }

<#list properties.types as prop>

    public static native Buffer createMonoid${prop.java_type?cap_first}(Buffer binaryOp, ${prop.java_type} identity);
    <#list properties.monoids as op>
    <#if prop.java_type != "boolean" || op.name == "any">
    public static native Buffer ${op.name}Monoid${prop.java_type?cap_first}();
    </#if>
    </#list>
</#list>
    // only applicable to aplicable to bool sparse matrix or vector, returns bool
    <#list properties.monoids_bool as op>
    public static native Buffer ${op.name}Monoid();
    </#list>
}
