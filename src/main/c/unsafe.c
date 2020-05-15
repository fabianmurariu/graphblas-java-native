#include "com_github_fabianmurariu_unsafe_GRBCORE.h"
#include <stdlib.h>
#include <jni.h>
#include "GraphBLAS.h"
#include <assert.h>

JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_createSemiring
  (JNIEnv * env, jclass cls, jobject add, jobject mul) {
        GrB_Monoid monoid_add = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, add);
        GrB_BinaryOp binop_mul = (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, mul);
        GrB_Semiring s;
        check_grb_error(GrB_Semiring_new(&s, monoid_add, binop_mul));
        return (*env)->NewDirectByteBuffer(env, s, 0);
  }

JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_freeSemiring
  (JNIEnv * env, jclass cls, jobject semi) {
        GrB_Semiring semiring = (GrB_Semiring) (*env)->GetDirectBufferAddress(env, semi);
        check_grb_error(GrB_Semiring_free(&semiring));
  }
