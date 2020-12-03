#include "com_github_fabianmurariu_unsafe_GRBCORE.h"
#include <stdlib.h>
#include <jni.h>
#include "GraphBLAS.h"
#include <assert.h>
long check_grb_error(GrB_Info info);

JavaVM *javavm;

JNIEXPORT jint JNICALL JNI_OnLoad (JavaVM *jvm, void *reserved) {
    javavm=jvm;
    return JNI_VERSION_1_2;
}
            long check_grb_error(GrB_Info info)
            {
            if (! (info == GrB_SUCCESS || info == GrB_NO_VALUE))
            {
            printf ("Error in GRB: %d \n", info) ;
            return (long) info;
            }
            return (long) info;
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_initNonBlocking
            (JNIEnv * env, jclass cls) {
            return check_grb_error(GrB_init(GrB_NONBLOCKING) );
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_initBlocking
            (JNIEnv * env, jclass cls) {
            return check_grb_error(GrB_init(GrB_BLOCKING) );
            }

            JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_getGlobalInt
            (JNIEnv * env, jclass cls, jint field) {
            GxB_Option_Field global_field = (GxB_Option_Field) field;
            int value;
            check_grb_error(GxB_Global_Option_get(global_field, &value));

            return (jint) value;
            }

            JNIEXPORT jdouble JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_getGlobalDouble
            (JNIEnv * env, jclass cls, jint field) {
            GxB_Option_Field global_field = (GxB_Option_Field) field;
            double value;
            check_grb_error(GxB_Global_Option_get(global_field, &value));

            return (jdouble) value;
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_setGlobalInt
            (JNIEnv * env, jclass cls, jint field, jint value) {
            GxB_Option_Field global_field = (GxB_Option_Field) field;
            return check_grb_error(GxB_Global_Option_set(global_field, value));
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_setGlobalDouble
            (JNIEnv * env, jclass cls, jint field, jdouble value) {
            GxB_Option_Field global_field = (GxB_Option_Field) field;
            return check_grb_error(GxB_Global_Option_set(global_field, value));
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_grbWaitVector
            (JNIEnv * env, jclass cls, jobject vec) {
            GrB_Vector grb_vec = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
            return check_grb_error(GrB_wait(&grb_vec));
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_grbWaitMatrix
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Matrix grb_mat = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            return check_grb_error(GrB_wait(&grb_mat));
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_grbFinalize
            (JNIEnv * env, jclass cls) {
            return check_grb_error(GrB_finalize());
            }

            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_createMatrix
            (JNIEnv * env, jclass cls, jobject tpe, jlong rows, jlong cols) {
            GrB_Type grb_type = (GrB_Type) (*env)->GetDirectBufferAddress(env, tpe);
            GrB_Matrix A;
            GrB_Index mat_rows = (GrB_Index)rows;
            GrB_Index mat_cols = (GrB_Index)cols;

            jclass err_cls;
            GrB_Info err = check_grb_error (GrB_Matrix_new(&A, grb_type, mat_rows, mat_cols) );
            if (err != 0) {
               err_cls = (*env)->FindClass(env, "com/github/fabianmurariu/unsafe/GrBJNIException");
               (*env)->ThrowNew(env, err_cls, (long)err);
               goto done;
            }
            return (*env)->NewDirectByteBuffer(env, A, 0);
            done:
                if (err_cls != NULL)
                    (*env)->DeleteLocalRef(env, err_cls);
            }

            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_createVector
            (JNIEnv * env, jclass cls, jobject tpe, jlong size) {
            GrB_Type grb_type = (GrB_Type) (*env)->GetDirectBufferAddress(env, tpe);
            GrB_Vector A;
            GrB_Index vec_size = (GrB_Index)size;
            check_grb_error (GrB_Vector_new(&A, grb_type, vec_size) );
            return (*env)->NewDirectByteBuffer(env, A, 0);
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_nvalsMatrix
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Index n;
            check_grb_error(GrB_Matrix_nvals(&n, A) );
            return (jlong)n;
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_nvalsVector
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Index n;
            check_grb_error(GrB_Vector_nvals(&n, A) );
            return (jlong)n;
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_nrows
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Index n;
            check_grb_error(GrB_Matrix_nrows(&n, A) );
            return (jlong)n;
            }


            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_ncols
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Index n;
            check_grb_error(GrB_Matrix_ncols(&n, A) );
            return (jlong)n;
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_size
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Index n;
            check_grb_error(GrB_Vector_size(&n, A) );
            return (jlong)n;
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_clearVec
            (JNIEnv * env, jclass cls, jobject vec) {
            GrB_Vector V = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
            return check_grb_error(GrB_Vector_clear(V));
            }

             JNIEXPORT long JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_clearMatrix
             (JNIEnv * env, jclass cls, jobject mat) {
             GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
             return check_grb_error(GrB_Matrix_clear(A) );
             }

            JNIEXPORT long JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_freeMatrix
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            return check_grb_error(GrB_Matrix_free(&A) );
            }

            JNIEXPORT long JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_freeVector
            (JNIEnv * env, jclass cls, jobject vec) {
            GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
            return check_grb_error(GrB_Vector_free(&A) );
            }

        JNIEXPORT long JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_freeMonoid
          (JNIEnv * env, jclass cls, jobject monoid) {
            GrB_Monoid A = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);
            return check_grb_error(GrB_Monoid_free(&A));
          }
            JNIEXPORT long JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_resizeMatrix
            (JNIEnv * env, jclass cls, jobject mat, jlong rows, jlong cols) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Index mat_rows = (GrB_Index)rows;
            GrB_Index mat_cols = (GrB_Index)cols;
             return check_grb_error(GxB_Matrix_resize(A, mat_rows, mat_cols));
            }

            JNIEXPORT long JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_resizeVector
            (JNIEnv * env, jclass cls, jobject vec, jlong size) {
            GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
            GrB_Index vec_size = (GrB_Index)size;
            return check_grb_error(GxB_Vector_resize(A, vec_size));
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_matrixApply
            (JNIEnv * env, jclass cls, jobject out_mat, jobject mask, jobject acc, jobject unary_op, jobject input_mat, jobject desc) {

            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, out_mat);
            GrB_Matrix first_mat = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, input_mat);
            GrB_UnaryOp op = (GrB_UnaryOp) (*env)->GetDirectBufferAddress(env, unary_op);

            GrB_BinaryOp a = acc != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, acc): NULL;
            GrB_Matrix m = mask != NULL ? (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mask): NULL;
            GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc): NULL;

            return check_grb_error(GrB_Matrix_apply(A, m, a, op, first_mat, d));
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_vectorApply
            (JNIEnv * env, jclass cls, jobject out_vec, jobject mask, jobject acc, jobject unary_op, jobject input_vec, jobject desc) {

            GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, out_vec);
            GrB_Vector first_vec = (GrB_Vector) (*env)->GetDirectBufferAddress(env, input_vec);
            GrB_UnaryOp op = (GrB_UnaryOp) (*env)->GetDirectBufferAddress(env, unary_op);

            GrB_BinaryOp a = acc != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, acc): NULL;
            GrB_Vector m = mask != NULL ? (GrB_Vector) (*env)->GetDirectBufferAddress(env, mask): NULL;
            GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc): NULL;

            return check_grb_error(GrB_Vector_apply(A, m, a, op, first_vec, d));
            }

JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_createSemiring
  (JNIEnv * env, jclass cls, jobject add, jobject mul) {
        GrB_Monoid monoid_add = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, add);
        GrB_BinaryOp binop_mul = (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, mul);
        GrB_Semiring s;
        check_grb_error(GrB_Semiring_new(&s, monoid_add, binop_mul));
        return (*env)->NewDirectByteBuffer(env, s, 0);
  }

JNIEXPORT long JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_freeSemiring
  (JNIEnv * env, jclass cls, jobject semi) {
        GrB_Semiring semiring = (GrB_Semiring) (*env)->GetDirectBufferAddress(env, semi);
        return check_grb_error(GrB_Semiring_free(&semiring));
  }

JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_dupMatrix
  (JNIEnv * env, jclass cls, jobject mat) {
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Matrix C;
        GrB_Matrix_dup(&C, A);
        return (*env)->NewDirectByteBuffer(env, C, 0);
  }

JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_dupVector
  (JNIEnv * env, jclass cls, jobject vec) {
        GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Vector C;
        check_grb_error(GrB_Vector_dup(&C, A));
        return (*env)->NewDirectByteBuffer(env, C, 0);
  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_makeCSC
  (JNIEnv * env, jclass cls, jobject mat) {
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        return check_grb_error(GxB_Matrix_Option_set(A, GxB_FORMAT, GxB_BY_COL));
  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_makeCSR
  (JNIEnv * env, jclass cls, jobject mat) {
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        return check_grb_error(GxB_Matrix_Option_set(A, GxB_FORMAT, GxB_BY_ROW));
  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_setHyperRatio
  (JNIEnv * env, jclass cls, jobject mat, jdouble ratio) {
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        double r = ratio;
        return check_grb_error(GxB_Matrix_Option_set(A, GxB_HYPER, r));
  }

JNIEXPORT jdouble JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_getHyperRatio
  (JNIEnv * env, jclass cls, jobject mat) {
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        double r = 0;
        check_grb_error(GxB_Matrix_Option_get(A, GxB_HYPER, &r));
        return r;
  }

JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_getFormat
  (JNIEnv * env, jclass cls, jobject mat) {
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GxB_Format_Value r = -1;
        check_grb_error(GxB_Matrix_Option_get(A, GxB_FORMAT, &r));
        return r;
  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_neverHyper
  (JNIEnv * env, jclass cls, jobject mat) {
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        return check_grb_error(GxB_Matrix_Option_set(A, GxB_FORMAT, GxB_NEVER_HYPER));
  }


JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_createDescriptor
  (JNIEnv * env, jclass cls) {
    GrB_Descriptor d;
    check_grb_error(GrB_Descriptor_new(&d));
    return (*env)->NewDirectByteBuffer(env, d, 0);
  }


JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_setDescriptorValue
  (JNIEnv * env, jclass cls, jobject desc, jint field, jint value){
        GrB_Descriptor d = (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc);
        GrB_Desc_Field f = field;
        GrB_Desc_Value v = value;
        return check_grb_error(GrB_Descriptor_set(d, f, v));
  }

JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_getDescriptorValue
  (JNIEnv * env, jclass cls, jobject desc, jint field) {
        GrB_Descriptor d = (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc);
        GrB_Desc_Field f = field;
        GrB_Desc_Value v = -1;
        check_grb_error(GxB_Descriptor_get(&v, d, f));
        return v;
  }

JNIEXPORT long JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_freeDescriptor
  (JNIEnv * env, jclass cls, jobject desc) {
    GrB_Descriptor d = (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc);
    return check_grb_error(GrB_Descriptor_free(&d));
  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_removeElementMatrix
  (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        return check_grb_error(GrB_Matrix_removeElement(A, (GrB_Index)i, (GrB_Index)j));
  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_matrixWait
  (JNIEnv * env, jclass cls, jobject mat) {
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        return check_grb_error(GrB_Matrix_wait(&A));
  }
JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_removeElementVector
  (JNIEnv * env, jclass cls, jobject vec, jlong i) {
        GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        return check_grb_error(GrB_Vector_removeElement(A, (GrB_Index)i));
  }
JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_vectorWait
  (JNIEnv * env, jclass cls, jobject vec) {
        GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        return check_grb_error(GrB_Vector_wait(&A));
  }
