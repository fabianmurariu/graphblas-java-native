#include "com_github_fabianmurariu_unsafe_GRBCORE.h"
#include <stdlib.h>
#include <jni.h>
#include "GraphBLAS.h"
#include <assert.h>
long check_grb_error(GrB_Info info);

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

JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_vxm
  (JNIEnv * env, jclass cls, jobject vec, jobject mask, jobject accum, jobject semiring, jobject u, jobject A, jobject desc) {
        // Must haves
        GrB_Vector out = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Vector first = (GrB_Vector) (*env)->GetDirectBufferAddress(env, u);
        GrB_Matrix second = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);
        GrB_Semiring semi = (GrB_Semiring) (*env)->GetDirectBufferAddress(env, semiring);

        // Optionals
        GrB_Vector m = mask != NULL ? (GrB_Vector) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return GrB_vxm(out, m, acc, semi, first, second, d);


  }
JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_mxv
  (JNIEnv * env, jclass cls, jobject vec, jobject mask, jobject accum, jobject semiring, jobject A, jobject u, jobject desc) {
        // Must haves
        GrB_Vector out = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Vector second = (GrB_Vector) (*env)->GetDirectBufferAddress(env, u);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);
        GrB_Semiring semi = (GrB_Semiring) (*env)->GetDirectBufferAddress(env, semiring);

        // Optionals
        GrB_Vector m = mask != NULL ? (GrB_Vector) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return GrB_mxv(out, m, acc, semi, first, second, d);

  }

JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_elemWiseMulIntersectMonoid
  (JNIEnv * env, jclass cls, jobject mat, jobject mask, jobject accum, jobject monoid, jobject A, jobject B, jobject desc) {

        GrB_Matrix out = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);
        GrB_Matrix second = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, B);
        GrB_Monoid semi = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // Optionals
        GrB_Matrix m = mask != NULL ? (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return GrB_eWiseMult(out, m, acc, semi, first, second, d);

  }

JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_elemWiseAddUnionMonoid
  (JNIEnv * env, jclass cls, jobject mat, jobject mask, jobject accum, jobject monoid, jobject A, jobject B, jobject desc) {

        GrB_Matrix out = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);
        GrB_Matrix second = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, B);
        GrB_Monoid semi = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // Optionals
        GrB_Matrix m = mask != NULL ? (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return GrB_eWiseAdd(out, m, acc, semi, first, second, d);

  }

JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_elemWiseMulIntersectBinOp
  (JNIEnv * env, jclass cls, jobject mat, jobject mask, jobject accum, jobject monoid, jobject A, jobject B, jobject desc) {

        GrB_Matrix out = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);
        GrB_Matrix second = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, B);
        GrB_BinaryOp semi = (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, monoid);

        // Optionals
        GrB_Matrix m = mask != NULL ? (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return GrB_eWiseMult(out, m, acc, semi, first, second, d);

  }

JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_elemWiseAddUnionBinOp
  (JNIEnv * env, jclass cls, jobject mat, jobject mask, jobject accum, jobject monoid, jobject A, jobject B, jobject desc) {

        GrB_Matrix out = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);
        GrB_Matrix second = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, B);
        GrB_BinaryOp semi = (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, monoid);

        // Optionals
        GrB_Matrix m = mask != NULL ? (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return GrB_eWiseAdd(out, m, acc, semi, first, second, d);

  }
