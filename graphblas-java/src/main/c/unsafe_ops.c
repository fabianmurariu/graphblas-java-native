#include "com_github_fabianmurariu_unsafe_GRBCORE.h"
#include "com_github_fabianmurariu_unsafe_GRBOPSMAT.h"
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

JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_extract
  (JNIEnv * env, jclass cls, jobject mat, jobject mask, jobject accum, jobject A, jlongArray is, jlong ni, jlongArray js, jlong nj, jobject desc) {
        GrB_Index grb_ni = ni == 9223372036854775807 ? GxB_RANGE : (GrB_Index) ni;
        GrB_Index grb_nj = nj == 9223372036854775807 ? GxB_RANGE : (GrB_Index) nj;

        GrB_Matrix out = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);

        jlong *java_is;
        jlong *java_js;
        GrB_Index *I = NULL;
        GrB_Index *J = NULL;

        java_is = (*env)->GetLongArrayElements(env, is, NULL);
        java_js = (*env)->GetLongArrayElements(env, js, NULL);
        I = malloc (ni * sizeof (GrB_Index)) ;
        J = malloc (nj * sizeof (GrB_Index)) ;

        for (int i = 0; i < ni; i++) {
            I[i] = (GrB_Index)java_is[i];
        }
        for (int i = 0; i < nj; i++) {
            J[i] = (GrB_Index)java_js[i];
        }
        // Optionals
        GrB_Matrix m = mask != NULL ? (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        GrB_Index res = check_grb_error(GrB_extract(out, m, acc, first, I, grb_ni, J, grb_nj, desc));

        (*env)->ReleaseLongArrayElements(env, is, java_is, 0);
        (*env)->ReleaseLongArrayElements(env, js, java_js, 0);
        free(I);
        free(J);

       return res;

  }

JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_assign
  (JNIEnv * env, jclass cls, jobject mat, jobject mask, jobject accum, jobject A, jlongArray is, jlong ni, jlongArray js, jlong nj, jobject desc) {
        // if we receive max java long we treat it as GxB_RANGE
        GrB_Index grb_ni = ni == 9223372036854775807 ? GxB_RANGE : (GrB_Index) ni;
        GrB_Index grb_nj = nj == 9223372036854775807 ? GxB_RANGE : (GrB_Index) nj;

        GrB_Matrix out = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);

        jlong *java_is;
        jlong *java_js;
        GrB_Index *I = NULL;
        GrB_Index *J = NULL;

        java_is = (*env)->GetLongArrayElements(env, is, NULL);
        java_js = (*env)->GetLongArrayElements(env, js, NULL);
        I = malloc (ni * sizeof (GrB_Index)) ;
        J = malloc (nj * sizeof (GrB_Index)) ;

        for (int i = 0; i < ni; i++) {
            I[i] = (GrB_Index)java_is[i];
        }
        for (int i = 0; i < nj; i++) {
            J[i] = (GrB_Index)java_js[i];
        }
        // Optionals
        GrB_Matrix m = mask != NULL ? (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        GrB_Index res = check_grb_error(GrB_assign(out, m, acc, first, I, grb_nj, J, grb_nj, desc));

        (*env)->ReleaseLongArrayElements(env, is, java_is, 0);
        (*env)->ReleaseLongArrayElements(env, js, java_js, 0);
        free(I);
        free(J);

       return res;

  }

JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_subAssign
  (JNIEnv * env, jclass cls, jobject mat, jobject mask, jobject accum, jobject A, jlongArray is, jlong ni, jlongArray js, jlong nj, jobject desc) {
        // if we receive max java long we treat it as GxB_RANGE
        GrB_Index grb_ni = ni == 9223372036854775807 ? GxB_RANGE : (GrB_Index) ni;
        GrB_Index grb_nj = nj == 9223372036854775807 ? GxB_RANGE : (GrB_Index) nj;

        GrB_Matrix out = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);

        jlong *java_is;
        jlong *java_js;
        GrB_Index *I = NULL;
        GrB_Index *J = NULL;

        java_is = (*env)->GetLongArrayElements(env, is, NULL);
        java_js = (*env)->GetLongArrayElements(env, js, NULL);
        I = malloc (ni * sizeof (GrB_Index)) ;
        J = malloc (nj * sizeof (GrB_Index)) ;

        for (int i = 0; i < ni; i++) {
            I[i] = (GrB_Index)java_is[i];
        }
        for (int i = 0; i < nj; i++) {
            J[i] = (GrB_Index)java_js[i];
        }
        // Optionals
        GrB_Matrix m = mask != NULL ? (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        GrB_Index res = check_grb_error(GrB_subassign(out, m, acc, first, I, grb_nj, J, grb_nj, desc));

        (*env)->ReleaseLongArrayElements(env, is, java_is, 0);
        (*env)->ReleaseLongArrayElements(env, js, java_js, 0);
        free(I);
        free(J);

       return res;

  }
