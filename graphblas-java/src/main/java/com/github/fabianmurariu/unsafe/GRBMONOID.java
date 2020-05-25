package com.github.fabianmurariu.unsafe;

import java.nio.Buffer;

public final class GRBMONOID {
    static {
        NarSystem.loadLibrary();
    }


    public static native Buffer createMonoidBoolean(Buffer binaryOp, boolean identity);

    public static native Buffer createMonoidByte(Buffer binaryOp, byte identity);
    public static native Buffer minMonoidByte();
    public static native Buffer maxMonoidByte();
    public static native Buffer plusMonoidByte();
    public static native Buffer timesMonoidByte();
    public static native Buffer anyMonoidByte();

    public static native Buffer createMonoidShort(Buffer binaryOp, short identity);
    public static native Buffer minMonoidShort();
    public static native Buffer maxMonoidShort();
    public static native Buffer plusMonoidShort();
    public static native Buffer timesMonoidShort();
    public static native Buffer anyMonoidShort();

    public static native Buffer createMonoidInt(Buffer binaryOp, int identity);
    public static native Buffer minMonoidInt();
    public static native Buffer maxMonoidInt();
    public static native Buffer plusMonoidInt();
    public static native Buffer timesMonoidInt();
    public static native Buffer anyMonoidInt();

    public static native Buffer createMonoidLong(Buffer binaryOp, long identity);
    public static native Buffer minMonoidLong();
    public static native Buffer maxMonoidLong();
    public static native Buffer plusMonoidLong();
    public static native Buffer timesMonoidLong();
    public static native Buffer anyMonoidLong();

    public static native Buffer createMonoidFloat(Buffer binaryOp, float identity);
    public static native Buffer minMonoidFloat();
    public static native Buffer maxMonoidFloat();
    public static native Buffer plusMonoidFloat();
    public static native Buffer timesMonoidFloat();
    public static native Buffer anyMonoidFloat();

    public static native Buffer createMonoidDouble(Buffer binaryOp, double identity);
    public static native Buffer minMonoidDouble();
    public static native Buffer maxMonoidDouble();
    public static native Buffer plusMonoidDouble();
    public static native Buffer timesMonoidDouble();
    public static native Buffer anyMonoidDouble();
    // only applicable to aplicable to bool sparse matrix or vector, returns bool
    public static native Buffer lorMonoid();
    public static native Buffer landMonoid();
    public static native Buffer lxorMonoid();
    public static native Buffer eqBoolMonoid();
}
