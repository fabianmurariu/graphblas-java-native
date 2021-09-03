#include "com_github_fabianmurariu_unsafe_GRBCORE.h"
#include "com_github_fabianmurariu_unsafe_GRBOPSMAT.h"
#include "com_github_fabianmurariu_unsafe_GRBOPSVEC.h"
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

JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_diag
  (JNIEnv * env, jclass cls, jobject mat, jobject vec, jlong k, jobject desc) {
        GrB_Matrix out = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Vector v = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return GxB_Matrix_diag(out, v, k, d);
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

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSVEC_elemWiseMulIntersectMonoid
  (JNIEnv * env, jclass cls, jobject vec, jobject mask, jobject accum, jobject monoid, jobject u, jobject v, jobject desc) {

        GrB_Vector out = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Vector first = (GrB_Vector) (*env)->GetDirectBufferAddress(env, u);
        GrB_Vector second = (GrB_Vector) (*env)->GetDirectBufferAddress(env, v);
        GrB_Monoid semi = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // Optionals
        GrB_Vector m = mask != NULL ? (GrB_Vector) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return check_grb_error(GrB_eWiseMult(out, m, acc, semi, first, second, d));

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

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSVEC_elemWiseAddUnionMonoid
  (JNIEnv * env, jclass cls, jobject vec, jobject mask, jobject accum, jobject monoid, jobject u, jobject v, jobject desc) {

        GrB_Vector out = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Vector first = (GrB_Vector) (*env)->GetDirectBufferAddress(env, u);
        GrB_Vector second = (GrB_Vector) (*env)->GetDirectBufferAddress(env, v);
        GrB_Monoid semi = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // Optionals
        GrB_Vector m = mask != NULL ? (GrB_Vector) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return check_grb_error(GrB_eWiseAdd(out, m, acc, semi, first, second, d));

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

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSVEC_elemWiseMulIntersectBinOp
  (JNIEnv * env, jclass cls, jobject vec, jobject mask, jobject accum, jobject bin_op, jobject u, jobject v, jobject desc) {

        GrB_Vector out = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Vector first = (GrB_Vector) (*env)->GetDirectBufferAddress(env, u);
        GrB_Vector second = (GrB_Vector) (*env)->GetDirectBufferAddress(env, v);
        GrB_BinaryOp semi = (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, bin_op);

        // Optionals
        GrB_Vector m = mask != NULL ? (GrB_Vector) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return check_grb_error(GrB_eWiseMult(out, m, acc, semi, first, second, d));

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

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSVEC_elemWiseAddUnionBinOp
  (JNIEnv * env, jclass cls, jobject vec, jobject mask, jobject accum, jobject bin_op, jobject u, jobject v, jobject desc) {

        GrB_Vector out = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Vector first = (GrB_Vector) (*env)->GetDirectBufferAddress(env, u);
        GrB_Vector second = (GrB_Vector) (*env)->GetDirectBufferAddress(env, v);
        GrB_BinaryOp semi = (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, bin_op);

        // Optionals
        GrB_Vector m = mask != NULL ? (GrB_Vector) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return check_grb_error(GrB_eWiseAdd(out, m, acc, semi, first, second, d));

  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_extract
  (JNIEnv * env, jclass cls, jobject mat, jobject mask, jobject accum, jobject A, jlongArray is, jlong ni, jlongArray js, jlong nj, jobject desc) {
        long java_max = 9223372036854775807;
        GrB_Index grb_ni;
        GrB_Index grb_nj;

        grb_ni = ni == java_max ? GxB_RANGE : (GrB_Index) ni;
        grb_nj = nj == java_max ? GxB_RANGE : (GrB_Index) nj;

        grb_ni = ni == java_max-1 ? GxB_STRIDE : (GrB_Index) ni;
        grb_nj = nj == java_max-1 ? GxB_STRIDE : (GrB_Index) nj;

        grb_ni = ni == java_max-2 ? GxB_BACKWARDS : (GrB_Index) ni;
        grb_nj = nj == java_max-2 ? GxB_BACKWARDS : (GrB_Index) nj;

        GrB_Matrix out = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);

        jlong *java_is;
        jlong *java_js;
        GrB_Index *I = NULL;
        GrB_Index *J = NULL;

        java_is = (*env)->GetPrimitiveArrayCritical(env, is, NULL);
        java_js = (*env)->GetPrimitiveArrayCritical(env, js, NULL);

        if (java_is == NULL || java_js == NULL) {
            if(java_is != NULL) {
                (*env)->ReleasePrimitiveArrayCritical(env, is, java_is, 0);
            }

            if(java_js != NULL) {
                (*env)->ReleasePrimitiveArrayCritical(env, js, java_js, 0);
            }
            return GrB_OUT_OF_MEMORY;
        }

        long java_min = -9223372036854775808;
        I = java_is[0] != java_min ? (GrB_Index*) java_is : GrB_ALL;
        J = java_js[0] != java_min ? (GrB_Index*) java_js : GrB_ALL;


        // Optionals
        GrB_Matrix m = mask != NULL ? (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        long res = check_grb_error(GrB_extract(out, m, acc, first, I, grb_ni, J, grb_nj, d));

        (*env)->ReleasePrimitiveArrayCritical(env, is, java_is, 0);
        (*env)->ReleasePrimitiveArrayCritical(env, js, java_js, 0);

       return res;

  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSVEC_extract
  (JNIEnv * env, jclass cls, jobject vec, jobject mask, jobject accum, jobject u, jlongArray is, jlong ni, jobject desc) {
        long java_max = 9223372036854775807;
        GrB_Index grb_ni;

        grb_ni = ni == java_max ? GxB_RANGE : (GrB_Index) ni;
        grb_ni = ni == java_max-1 ? GxB_STRIDE : (GrB_Index) ni;
        grb_ni = ni == java_max-2 ? GxB_BACKWARDS : (GrB_Index) ni;

        GrB_Vector out = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Vector first = (GrB_Vector) (*env)->GetDirectBufferAddress(env, u);

        jlong *java_is = (*env)->GetPrimitiveArrayCritical(env, is, NULL);

        if (java_is == NULL) {
            return GrB_OUT_OF_MEMORY;
        }

        long java_min = -9223372036854775808;
        GrB_Index *I = java_is[0] != java_min ? (GrB_Index*) java_is : GrB_ALL;

        // Optionals
        GrB_Vector m = mask != NULL ? (GrB_Vector) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        long res = check_grb_error(GrB_Vector_extract(out, m, acc, first, I, grb_ni, d));

       (*env)->ReleasePrimitiveArrayCritical(env, is, java_is, 0);

       return res;

  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_assign
  (JNIEnv * env, jclass cls, jobject mat, jobject mask, jobject accum, jobject A, jlongArray is, jlong ni, jlongArray js, jlong nj, jobject desc) {
        long java_max = 9223372036854775807;
        GrB_Index grb_ni;
        GrB_Index grb_nj;

        grb_ni = ni == java_max ? GxB_RANGE : (GrB_Index) ni;
        grb_nj = nj == java_max ? GxB_RANGE : (GrB_Index) nj;

        grb_ni = ni == java_max-1 ? GxB_STRIDE : (GrB_Index) ni;
        grb_nj = nj == java_max-1 ? GxB_STRIDE : (GrB_Index) nj;

        grb_ni = ni == java_max-2 ? GxB_BACKWARDS : (GrB_Index) ni;
        grb_nj = nj == java_max-2 ? GxB_BACKWARDS : (GrB_Index) nj;

        GrB_Matrix out = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);

        jlong *java_is = (*env)->GetPrimitiveArrayCritical(env, is, NULL);
        jlong *java_js = (*env)->GetPrimitiveArrayCritical(env, js, NULL);

        if (java_is == NULL || java_js == NULL) {
            if(java_is != NULL) {
                (*env)->ReleasePrimitiveArrayCritical(env, is, java_is, 0);
            }

            if(java_js != NULL) {
                (*env)->ReleasePrimitiveArrayCritical(env, js, java_js, 0);
            }

            return GrB_OUT_OF_MEMORY;
        }

        long java_min = -9223372036854775808;
        GrB_Index *I = java_is[0] != java_min ? (GrB_Index*) java_is : GrB_ALL;
        GrB_Index *J = java_js[0] != java_min ? (GrB_Index*) java_js : GrB_ALL;

        // Optionals
        GrB_Matrix m = mask != NULL ? (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        long res = check_grb_error(GrB_assign(out, m, acc, first, I, grb_ni, J, grb_nj, d));

        (*env)->ReleasePrimitiveArrayCritical(env, is, java_is, 0);
        (*env)->ReleasePrimitiveArrayCritical(env, js, java_js, 0);

       return res;

  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSVEC_assign
  (JNIEnv * env, jclass cls, jobject vec, jobject mask, jobject accum, jobject u, jlongArray is, jlong ni, jobject desc) {
        long java_max = 9223372036854775807;
        GrB_Index grb_ni;

        grb_ni = ni == java_max ? GxB_RANGE : (GrB_Index) ni;
        grb_ni = ni == java_max-1 ? GxB_STRIDE : (GrB_Index) ni;
        grb_ni = ni == java_max-2 ? GxB_BACKWARDS : (GrB_Index) ni;

        GrB_Vector out = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Vector first = (GrB_Vector) (*env)->GetDirectBufferAddress(env, u);

        jlong *java_is = (*env)->GetPrimitiveArrayCritical(env, is, NULL);

        if (java_is == NULL) {
            return GrB_OUT_OF_MEMORY;
        }

        long java_min = -9223372036854775808;

        GrB_Index *I = java_is[0] != java_min ? (GrB_Index*) java_is : GrB_ALL;

        // Optionals
        GrB_Vector m = mask != NULL ? (GrB_Vector) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        long res = check_grb_error(GrB_assign(out, m, acc, first, I, grb_ni, d));

       (*env)->ReleasePrimitiveArrayCritical(env, is, java_is, 0);

       return res;

  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_subAssign
  (JNIEnv * env, jclass cls, jobject mat, jobject mask, jobject accum, jobject A, jlongArray is, jlong ni, jlongArray js, jlong nj, jobject desc) {
        // if we receive max java long we treat it as GxB_RANGE
        long java_max = 9223372036854775807;
        GrB_Index grb_ni;
        GrB_Index grb_nj;

        grb_ni = ni == java_max ? GxB_RANGE : (GrB_Index) ni;
        grb_nj = nj == java_max ? GxB_RANGE : (GrB_Index) nj;

        grb_ni = ni == java_max-1 ? GxB_STRIDE : (GrB_Index) ni;
        grb_nj = nj == java_max-1 ? GxB_STRIDE : (GrB_Index) nj;

        grb_ni = ni == java_max-2 ? GxB_BACKWARDS : (GrB_Index) ni;
        grb_nj = nj == java_max-2 ? GxB_BACKWARDS : (GrB_Index) nj;

        GrB_Matrix out = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);

        jlong *java_is = (*env)->GetPrimitiveArrayCritical(env, is, NULL);
        jlong *java_js = (*env)->GetPrimitiveArrayCritical(env, js, NULL);

        if (java_is == NULL || java_js == NULL) {
            if(java_is != NULL) {
                (*env)->ReleasePrimitiveArrayCritical(env, is, java_is, 0);
            }

            if(java_js != NULL) {
                (*env)->ReleasePrimitiveArrayCritical(env, js, java_js, 0);
            }

            return GrB_OUT_OF_MEMORY;
        }

        long java_min = -9223372036854775808;
        GrB_Index *I = java_is[0] != java_min ? (GrB_Index*) java_is : GrB_ALL;
        GrB_Index *J = java_js[0] != java_min ? (GrB_Index*) java_js : GrB_ALL;

        // Optionals
        GrB_Matrix m = mask != NULL ? (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        long res = check_grb_error(GxB_subassign(out, m, acc, first, I, grb_ni, J, grb_nj, d));

        (*env)->ReleasePrimitiveArrayCritical(env, is, java_is, 0);
        (*env)->ReleasePrimitiveArrayCritical(env, js, java_js, 0);

       return res;

  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSVEC_subAssign
  (JNIEnv * env, jclass cls, jobject vec, jobject mask, jobject accum, jobject u, jlongArray is, jlong ni, jobject desc) {
        // if we receive max java long we treat it as GxB_RANGE
        long java_max = 9223372036854775807;
        GrB_Index grb_ni;

        grb_ni = ni == java_max ? GxB_RANGE : (GrB_Index) ni;
        grb_ni = ni == java_max-1 ? GxB_STRIDE : (GrB_Index) ni;
        grb_ni = ni == java_max-2 ? GxB_BACKWARDS : (GrB_Index) ni;

        GrB_Vector out = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Vector first = (GrB_Vector) (*env)->GetDirectBufferAddress(env, u);

        jlong *java_is = (*env)->GetPrimitiveArrayCritical(env, is, NULL);

        if (java_is == NULL) {
            return GrB_OUT_OF_MEMORY;
        }

        long java_min = -9223372036854775808;
        GrB_Index *I = java_is[0] != java_min ? (GrB_Index*) java_is : GrB_ALL;

        // Optionals
        GrB_Vector m = mask != NULL ? (GrB_Vector) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        long res = check_grb_error(GxB_Vector_subassign(out, m, acc, first, I, grb_ni, d));

       (*env)->ReleasePrimitiveArrayCritical(env, is, java_is, 0);

       return res;
  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_select
  (JNIEnv * env, jclass cls, jobject C, jobject mask, jobject accum, jobject op, jobject A, jobject Thunk, jobject desc) {
        // Non-optionals
        GrB_Matrix out = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, C);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);
        GxB_SelectOp grb_op = (GxB_SelectOp) (*env)->GetDirectBufferAddress(env, op);

        // Optionals
        GrB_Matrix m = mask != NULL ? (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;
        GxB_Scalar grb_thunk = NULL;

        return check_grb_error(GxB_Matrix_select(out, m, acc, grb_op, first, grb_thunk, d));
  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_matrixReduceBinOp
  (JNIEnv * env, jclass cls, jobject vec, jobject mask, jobject accum, jobject bin_op, jobject A, jobject desc) {
        GrB_Vector out = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);
        GrB_BinaryOp op = (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, bin_op);
        // Optionals
        GrB_Vector m = mask != NULL ? (GrB_Vector) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return check_grb_error(GrB_reduce(out, m, acc, op, first, d));
  }
JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_matrixReduceMonoid
  (JNIEnv * env, jclass cls, jobject vec, jobject mask, jobject accum, jobject monoid, jobject A, jobject desc) {
        GrB_Vector out = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);
        GrB_Monoid op = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);
        // Optionals
        GrB_Vector m = mask != NULL ? (GrB_Vector) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return check_grb_error(GrB_reduce(out, m, acc, op, first, d));
  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBOPSMAT_transpose
  (JNIEnv * env, jclass cls, jobject C, jobject mask, jobject accum, jobject A, jobject desc) {
        GrB_Matrix mat = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, C);
        GrB_Matrix first = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, A);
        // Optionals
        GrB_Matrix m = mask != NULL ? (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mask) : NULL ;
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum) : NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        return check_grb_error(GrB_transpose(mat, m, acc, first, d));
  }
