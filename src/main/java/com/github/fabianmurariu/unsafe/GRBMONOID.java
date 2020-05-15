package com.github.fabianmurariu.unsafe;

import java.nio.ByteBuffer;

public final class GRBMONOID {
    static {
        NarSystem.loadLibrary();
    }

// TODO: add createMonoid and freeMonoid

    public static native ByteBuffer minMonoidByte();
    public static native ByteBuffer maxMonoidByte();
    public static native ByteBuffer plusMonoidByte();
    public static native ByteBuffer timesMonoidByte();
    public static native ByteBuffer anyMonoidByte();
    public static native ByteBuffer minMonoidShort();
    public static native ByteBuffer maxMonoidShort();
    public static native ByteBuffer plusMonoidShort();
    public static native ByteBuffer timesMonoidShort();
    public static native ByteBuffer anyMonoidShort();
    public static native ByteBuffer minMonoidInt();
    public static native ByteBuffer maxMonoidInt();
    public static native ByteBuffer plusMonoidInt();
    public static native ByteBuffer timesMonoidInt();
    public static native ByteBuffer anyMonoidInt();
    public static native ByteBuffer minMonoidLong();
    public static native ByteBuffer maxMonoidLong();
    public static native ByteBuffer plusMonoidLong();
    public static native ByteBuffer timesMonoidLong();
    public static native ByteBuffer anyMonoidLong();
    public static native ByteBuffer minMonoidFloat();
    public static native ByteBuffer maxMonoidFloat();
    public static native ByteBuffer plusMonoidFloat();
    public static native ByteBuffer timesMonoidFloat();
    public static native ByteBuffer anyMonoidFloat();
    public static native ByteBuffer minMonoidDouble();
    public static native ByteBuffer maxMonoidDouble();
    public static native ByteBuffer plusMonoidDouble();
    public static native ByteBuffer timesMonoidDouble();
    public static native ByteBuffer anyMonoidDouble();
    // only applicable to aplicable to bool sparse matrix or vector, returns bool
    public static native ByteBuffer lorMonoid();
    public static native ByteBuffer landMonoid();
    public static native ByteBuffer lxorMonoid();
    public static native ByteBuffer eqBoolMonoid();
}
