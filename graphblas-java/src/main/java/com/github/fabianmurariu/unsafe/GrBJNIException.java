package com.github.fabianmurariu.unsafe;

public class GrBJNIException extends RuntimeException{
    public final long code;
    public GrBJNIException(long code) {
        this.code = code;
    }
}
