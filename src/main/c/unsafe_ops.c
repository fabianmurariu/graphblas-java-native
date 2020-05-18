#include "com_github_fabianmurariu_unsafe_GRBCORE.h"
#include <stdlib.h>
#include <jni.h>
#include "GraphBLAS.h"
#include <assert.h>
void check_grb_error(GrB_Info info);

JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_mxm
  (JNIEnv * env, jclass cls, jobject mat, jobject mask, jobject accum, jobject semiring, jobject A, jobject B, jobject desc) {
        // Must haves
        GrB_Matrix out = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);
        GrB_Matrix second = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, B);
        GrB_Semiring semi = (GrB_Semiring) (*env)->GetDirectBufferAddress(env, semiring);

        // Optionals
        GrB_Matrix m = mask != NULL ? (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return GrB_mxm(out, m, acc, semi, first, second, d);

  }
