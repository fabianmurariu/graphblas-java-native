package com.github.fabianmurariu.unsafe;

import org.junit.Test;

import java.nio.ByteBuffer;

import static org.junit.Assert.*;

public class GRAPHBLASTest {

    @Test
    public void createBoolMatrix() {
        GRAPHBLAS.initNonBlocking();
        ByteBuffer booleanType =  GRAPHBLAS.booleanType();
        ByteBuffer matrix = GRAPHBLAS.createMatrix(booleanType, 7, 7);
        GRAPHBLAS.setElementBoolean(matrix, 0, 3, true);
        GRAPHBLAS.setElementBoolean(matrix, 1, 4, false);
        assertEquals(2, GRAPHBLAS.nvals(matrix));
        assertArrayEquals(GRAPHBLAS.getElementBoolean(matrix, 1, 1), new boolean[]{});
        assertArrayEquals(new boolean[]{true}, GRAPHBLAS.getElementBoolean(matrix, 0, 3));
        assertArrayEquals(new boolean[]{false}, GRAPHBLAS.getElementBoolean(matrix, 1, 4));
    }
}