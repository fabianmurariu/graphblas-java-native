#include "com_github_fabianmurariu_unsafe_GRAPHBLAS.h"
#include "com_github_fabianmurariu_unsafe_GRBCORE.h"
#include "com_github_fabianmurariu_unsafe_GRBMONOID.h"
#include <stdlib.h>
#include <jni.h>
#include "GraphBLAS.h"
#include <assert.h>
void check_grb_error(GrB_Info info);

            void check_grb_error(GrB_Info info)
            {
            if (! (info == GrB_SUCCESS || info == GrB_NO_VALUE))
            {
            printf ("info: %d error: %s\n", info, GrB_error ( )) ;
            }
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_initNonBlocking
            (JNIEnv * env, jclass cls) {
            check_grb_error(GrB_init(GrB_NONBLOCKING) );
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_grbWait
            (JNIEnv * env, jclass cls) {
            check_grb_error(GrB_wait());
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_grbFinalize
            (JNIEnv * env, jclass cls) {
            check_grb_error(GrB_finalize());
            }

            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_createMatrix
            (JNIEnv * env, jclass cls, jobject tpe, jlong rows, jlong cols) {
            GrB_Type grb_type = (GrB_Type) (*env)->GetDirectBufferAddress(env, tpe);
            GrB_Matrix A;
            GrB_Index mat_rows = rows;
            GrB_Index mat_cols = cols;
            check_grb_error (GrB_Matrix_new(&A, grb_type, mat_rows, mat_cols) );
            return (*env)->NewDirectByteBuffer(env, A, 0);
            }

            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_createVector
            (JNIEnv * env, jclass cls, jobject tpe, jlong size) {
            GrB_Type grb_type = (GrB_Type) (*env)->GetDirectBufferAddress(env, tpe);
            GrB_Vector A;
            GrB_Index vec_size = size;
            check_grb_error (GrB_Vector_new(&A, grb_type, vec_size) );
            return (*env)->NewDirectByteBuffer(env, A, 0);
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_nvalsMatrix
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Index n;
            check_grb_error(GrB_Matrix_nvals(&n, A) );
            return n;
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_nvalsVector
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Index n;
            check_grb_error(GrB_Vector_nvals(&n, A) );
            return n;
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_nrows
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Index n;
            check_grb_error(GrB_Matrix_nrows(&n, A) );
            return n;
            }


            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_ncols
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Index n;
            check_grb_error(GrB_Matrix_ncols(&n, A) );
            return n;
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_size
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Index n;
            check_grb_error(GrB_Vector_size(&n, A) );
            return n;
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_freeMatrix
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            check_grb_error(GrB_Matrix_free(&A) );
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_freeVector
            (JNIEnv * env, jclass cls, jobject vec) {
            GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
            check_grb_error(GrB_Vector_free(&A) );
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_resizeMatrix
            (JNIEnv * env, jclass cls, jobject mat, jlong rows, jlong cols) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Index mat_rows = rows;
            GrB_Index mat_cols = cols;
            check_grb_error(GxB_Matrix_resize(A, mat_rows, mat_cols));
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_resizeVector
            (JNIEnv * env, jclass cls, jobject vec, jlong size) {
            GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
            GrB_Index vec_size = size;
            check_grb_error(GxB_Vector_resize(A, vec_size));
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_matrixApply
            (JNIEnv * env, jclass cls, jobject out_mat, jobject mask, jobject acc, jobject unary_op, jobject input_mat, jobject desc) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, out_mat);
            GrB_Matrix first_mat = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, input_mat);
            GrB_UnaryOp op = (GrB_UnaryOp) (*env)->GetDirectBufferAddress(env, unary_op);
            check_grb_error(GrB_Matrix_apply(A, NULL, NULL, op, first_mat, NULL));
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_vectorApply
            (JNIEnv * env, jclass cls, jobject out_vec, jobject mask, jobject acc, jobject unary_op, jobject input_vec, jobject desc) {
            GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, out_vec);
            GrB_Vector first_vec = (GrB_Vector) (*env)->GetDirectBufferAddress(env, input_vec);
            GrB_UnaryOp op = (GrB_UnaryOp) (*env)->GetDirectBufferAddress(env, unary_op);
            check_grb_error(GrB_Vector_apply(A, NULL, NULL, op, first_vec, NULL));
            }

            // generic functions
            
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_booleanType
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_BOOL, 0);
            }


            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_byteType
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_INT8, 0);
            }


            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_shortType
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_INT16, 0);
            }


            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_intType
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_INT32, 0);
            }


            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_longType
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_INT64, 0);
            }


            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_floatType
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_FP32, 0);
            }


            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_doubleType
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_FP64, 0);
            }


            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setMatrixElementBoolean
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, jboolean value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            check_grb_error( GrB_Matrix_setElement_BOOL(A, value, I, J) ) ;
            }


            JNIEXPORT jbooleanArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getMatrixElementBoolean
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            bool x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            GrB_Info info = GrB_Matrix_extractElement_BOOL(&x, A, I, J);
            jbooleanArray output;
            if (info == GrB_NO_VALUE) {
            output = (*env)->NewBooleanArray(env, 0);
            } else {
            output = (*env)->NewBooleanArray(env, 1);
            bool xs[] = {x};
            (*env)->SetBooleanArrayRegion(env, output, 0, 1, xs);
            }
            return output;
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setMatrixElementByte
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, jbyte value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            check_grb_error( GrB_Matrix_setElement_INT8(A, value, I, J) ) ;
            }


            JNIEXPORT jbyteArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getMatrixElementByte
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            int8_t x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            GrB_Info info = GrB_Matrix_extractElement_INT8(&x, A, I, J);
            jbyteArray output;
            if (info == GrB_NO_VALUE) {
            output = (*env)->NewByteArray(env, 0);
            } else {
            output = (*env)->NewByteArray(env, 1);
            int8_t xs[] = {x};
            (*env)->SetByteArrayRegion(env, output, 0, 1, xs);
            }
            return output;
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setMatrixElementShort
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, jshort value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            check_grb_error( GrB_Matrix_setElement_INT16(A, value, I, J) ) ;
            }


            JNIEXPORT jshortArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getMatrixElementShort
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            short x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            GrB_Info info = GrB_Matrix_extractElement_INT16(&x, A, I, J);
            jshortArray output;
            if (info == GrB_NO_VALUE) {
            output = (*env)->NewShortArray(env, 0);
            } else {
            output = (*env)->NewShortArray(env, 1);
            short xs[] = {x};
            (*env)->SetShortArrayRegion(env, output, 0, 1, xs);
            }
            return output;
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setMatrixElementInt
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, jint value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            check_grb_error( GrB_Matrix_setElement_INT32(A, value, I, J) ) ;
            }


            JNIEXPORT jintArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getMatrixElementInt
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            int x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            GrB_Info info = GrB_Matrix_extractElement_INT32(&x, A, I, J);
            jintArray output;
            if (info == GrB_NO_VALUE) {
            output = (*env)->NewIntArray(env, 0);
            } else {
            output = (*env)->NewIntArray(env, 1);
            int xs[] = {x};
            (*env)->SetIntArrayRegion(env, output, 0, 1, xs);
            }
            return output;
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setMatrixElementLong
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, jlong value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            check_grb_error( GrB_Matrix_setElement_INT64(A, value, I, J) ) ;
            }


            JNIEXPORT jlongArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getMatrixElementLong
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            long x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            GrB_Info info = GrB_Matrix_extractElement_INT64(&x, A, I, J);
            jlongArray output;
            if (info == GrB_NO_VALUE) {
            output = (*env)->NewLongArray(env, 0);
            } else {
            output = (*env)->NewLongArray(env, 1);
            long xs[] = {x};
            (*env)->SetLongArrayRegion(env, output, 0, 1, xs);
            }
            return output;
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setMatrixElementFloat
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, jfloat value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            check_grb_error( GrB_Matrix_setElement_FP32(A, value, I, J) ) ;
            }


            JNIEXPORT jfloatArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getMatrixElementFloat
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            float x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            GrB_Info info = GrB_Matrix_extractElement_FP32(&x, A, I, J);
            jfloatArray output;
            if (info == GrB_NO_VALUE) {
            output = (*env)->NewFloatArray(env, 0);
            } else {
            output = (*env)->NewFloatArray(env, 1);
            float xs[] = {x};
            (*env)->SetFloatArrayRegion(env, output, 0, 1, xs);
            }
            return output;
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setMatrixElementDouble
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, jdouble value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            check_grb_error( GrB_Matrix_setElement_FP64(A, value, I, J) ) ;
            }


            JNIEXPORT jdoubleArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getMatrixElementDouble
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            double x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            GrB_Info info = GrB_Matrix_extractElement_FP64(&x, A, I, J);
            jdoubleArray output;
            if (info == GrB_NO_VALUE) {
            output = (*env)->NewDoubleArray(env, 0);
            } else {
            output = (*env)->NewDoubleArray(env, 1);
            double xs[] = {x};
            (*env)->SetDoubleArrayRegion(env, output, 0, 1, xs);
            }
            return output;
            }


                JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setVectorElementBoolean
                (JNIEnv * env, jclass cls, jobject mat, jlong i, jboolean value) {
                GrB_Vector A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                check_grb_error( GrB_Vector_setElement_BOOL(A, value, I) ) ;
                }


                JNIEXPORT jbooleanArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getVectorElementBoolean
                (JNIEnv * env, jclass cls, jobject mat, jlong i) {
                bool x;
                GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Info info = GrB_Vector_extractElement_BOOL(&x, A, I);
                jbooleanArray output;
                if (info == GrB_NO_VALUE) {
                output = (*env)->NewBooleanArray(env, 0);
                } else {
                output = (*env)->NewBooleanArray(env, 1);
                bool xs[] = {x};
                (*env)->SetBooleanArrayRegion(env, output, 0, 1, xs);
                }
                return output;
                }

                JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setVectorElementByte
                (JNIEnv * env, jclass cls, jobject mat, jlong i, jbyte value) {
                GrB_Vector A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                check_grb_error( GrB_Vector_setElement_INT8(A, value, I) ) ;
                }


                JNIEXPORT jbyteArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getVectorElementByte
                (JNIEnv * env, jclass cls, jobject mat, jlong i) {
                int8_t x;
                GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Info info = GrB_Vector_extractElement_INT8(&x, A, I);
                jbyteArray output;
                if (info == GrB_NO_VALUE) {
                output = (*env)->NewByteArray(env, 0);
                } else {
                output = (*env)->NewByteArray(env, 1);
                int8_t xs[] = {x};
                (*env)->SetByteArrayRegion(env, output, 0, 1, xs);
                }
                return output;
                }

                JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setVectorElementShort
                (JNIEnv * env, jclass cls, jobject mat, jlong i, jshort value) {
                GrB_Vector A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                check_grb_error( GrB_Vector_setElement_INT16(A, value, I) ) ;
                }


                JNIEXPORT jshortArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getVectorElementShort
                (JNIEnv * env, jclass cls, jobject mat, jlong i) {
                short x;
                GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Info info = GrB_Vector_extractElement_INT16(&x, A, I);
                jshortArray output;
                if (info == GrB_NO_VALUE) {
                output = (*env)->NewShortArray(env, 0);
                } else {
                output = (*env)->NewShortArray(env, 1);
                short xs[] = {x};
                (*env)->SetShortArrayRegion(env, output, 0, 1, xs);
                }
                return output;
                }

                JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setVectorElementInt
                (JNIEnv * env, jclass cls, jobject mat, jlong i, jint value) {
                GrB_Vector A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                check_grb_error( GrB_Vector_setElement_INT32(A, value, I) ) ;
                }


                JNIEXPORT jintArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getVectorElementInt
                (JNIEnv * env, jclass cls, jobject mat, jlong i) {
                int x;
                GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Info info = GrB_Vector_extractElement_INT32(&x, A, I);
                jintArray output;
                if (info == GrB_NO_VALUE) {
                output = (*env)->NewIntArray(env, 0);
                } else {
                output = (*env)->NewIntArray(env, 1);
                int xs[] = {x};
                (*env)->SetIntArrayRegion(env, output, 0, 1, xs);
                }
                return output;
                }

                JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setVectorElementLong
                (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong value) {
                GrB_Vector A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                check_grb_error( GrB_Vector_setElement_INT64(A, value, I) ) ;
                }


                JNIEXPORT jlongArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getVectorElementLong
                (JNIEnv * env, jclass cls, jobject mat, jlong i) {
                long x;
                GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Info info = GrB_Vector_extractElement_INT64(&x, A, I);
                jlongArray output;
                if (info == GrB_NO_VALUE) {
                output = (*env)->NewLongArray(env, 0);
                } else {
                output = (*env)->NewLongArray(env, 1);
                long xs[] = {x};
                (*env)->SetLongArrayRegion(env, output, 0, 1, xs);
                }
                return output;
                }

                JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setVectorElementFloat
                (JNIEnv * env, jclass cls, jobject mat, jlong i, jfloat value) {
                GrB_Vector A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                check_grb_error( GrB_Vector_setElement_FP32(A, value, I) ) ;
                }


                JNIEXPORT jfloatArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getVectorElementFloat
                (JNIEnv * env, jclass cls, jobject mat, jlong i) {
                float x;
                GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Info info = GrB_Vector_extractElement_FP32(&x, A, I);
                jfloatArray output;
                if (info == GrB_NO_VALUE) {
                output = (*env)->NewFloatArray(env, 0);
                } else {
                output = (*env)->NewFloatArray(env, 1);
                float xs[] = {x};
                (*env)->SetFloatArrayRegion(env, output, 0, 1, xs);
                }
                return output;
                }

                JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setVectorElementDouble
                (JNIEnv * env, jclass cls, jobject mat, jlong i, jdouble value) {
                GrB_Vector A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                check_grb_error( GrB_Vector_setElement_FP64(A, value, I) ) ;
                }


                JNIEXPORT jdoubleArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getVectorElementDouble
                (JNIEnv * env, jclass cls, jobject mat, jlong i) {
                double x;
                GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Info info = GrB_Vector_extractElement_FP64(&x, A, I);
                jdoubleArray output;
                if (info == GrB_NO_VALUE) {
                output = (*env)->NewDoubleArray(env, 0);
                } else {
                output = (*env)->NewDoubleArray(env, 1);
                double xs[] = {x};
                (*env)->SetDoubleArrayRegion(env, output, 0, 1, xs);
                }
                return output;
                }


            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_oneUnaryOpBoolean
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_ONE_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_identityUnaryOpBoolean
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_IDENTITY_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_addInvUnaryOpBoolean
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_AINV_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_absUnaryOpBoolean
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_ABS_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_mulInvUnaryOpBoolean
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_MINV_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_logicalNotUnaryOpBoolean
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_LNOT_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_oneUnaryOpByte
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_ONE_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_identityUnaryOpByte
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_IDENTITY_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_addInvUnaryOpByte
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_AINV_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_absUnaryOpByte
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_ABS_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_mulInvUnaryOpByte
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_MINV_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_logicalNotUnaryOpByte
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_LNOT_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_oneUnaryOpShort
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_ONE_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_identityUnaryOpShort
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_IDENTITY_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_addInvUnaryOpShort
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_AINV_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_absUnaryOpShort
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_ABS_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_mulInvUnaryOpShort
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_MINV_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_logicalNotUnaryOpShort
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_LNOT_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_oneUnaryOpInt
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_ONE_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_identityUnaryOpInt
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_IDENTITY_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_addInvUnaryOpInt
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_AINV_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_absUnaryOpInt
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_ABS_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_mulInvUnaryOpInt
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_MINV_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_logicalNotUnaryOpInt
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_LNOT_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_oneUnaryOpLong
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_ONE_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_identityUnaryOpLong
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_IDENTITY_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_addInvUnaryOpLong
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_AINV_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_absUnaryOpLong
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_ABS_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_mulInvUnaryOpLong
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_MINV_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_logicalNotUnaryOpLong
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_LNOT_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_oneUnaryOpFloat
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_ONE_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_identityUnaryOpFloat
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_IDENTITY_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_addInvUnaryOpFloat
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_AINV_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_absUnaryOpFloat
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_ABS_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_mulInvUnaryOpFloat
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_MINV_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_logicalNotUnaryOpFloat
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_LNOT_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_oneUnaryOpDouble
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_ONE_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_identityUnaryOpDouble
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_IDENTITY_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_addInvUnaryOpDouble
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_AINV_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_absUnaryOpDouble
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_ABS_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_mulInvUnaryOpDouble
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_MINV_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_logicalNotUnaryOpDouble
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GxB_LNOT_FP64, 0);
            }

            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_firstBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_FIRST_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_secondBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_SECOND_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_anyBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ANY_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_pairBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_PAIR_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_minBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MIN_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_maxBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MAX_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_plusBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_PLUS_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_minusBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MINUS_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_rminusBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_RMINUS_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_timesBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_TIMES_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_divBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_DIV_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_rdivBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_RDIV_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_iseqBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISEQ_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isneBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISNE_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isgtBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISGT_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isltBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISLT_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isgeBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISGE_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isleBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISLE_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lorBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LOR_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_landBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LAND_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lxorBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LXOR_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_firstBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_FIRST_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_secondBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_SECOND_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_anyBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ANY_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_pairBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_PAIR_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_minBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MIN_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_maxBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MAX_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_plusBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_PLUS_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_minusBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MINUS_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_rminusBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_RMINUS_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_timesBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_TIMES_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_divBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_DIV_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_rdivBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_RDIV_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_iseqBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISEQ_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isneBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISNE_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isgtBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISGT_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isltBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISLT_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isgeBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISGE_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isleBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISLE_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lorBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LOR_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_landBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LAND_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lxorBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LXOR_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_firstBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_FIRST_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_secondBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_SECOND_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_anyBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ANY_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_pairBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_PAIR_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_minBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MIN_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_maxBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MAX_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_plusBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_PLUS_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_minusBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MINUS_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_rminusBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_RMINUS_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_timesBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_TIMES_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_divBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_DIV_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_rdivBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_RDIV_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_iseqBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISEQ_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isneBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISNE_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isgtBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISGT_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isltBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISLT_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isgeBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISGE_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isleBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISLE_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lorBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LOR_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_landBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LAND_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lxorBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LXOR_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_firstBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_FIRST_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_secondBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_SECOND_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_anyBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ANY_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_pairBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_PAIR_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_minBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MIN_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_maxBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MAX_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_plusBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_PLUS_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_minusBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MINUS_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_rminusBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_RMINUS_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_timesBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_TIMES_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_divBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_DIV_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_rdivBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_RDIV_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_iseqBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISEQ_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isneBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISNE_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isgtBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISGT_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isltBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISLT_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isgeBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISGE_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isleBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISLE_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lorBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LOR_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_landBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LAND_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lxorBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LXOR_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_firstBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_FIRST_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_secondBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_SECOND_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_anyBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ANY_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_pairBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_PAIR_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_minBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MIN_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_maxBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MAX_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_plusBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_PLUS_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_minusBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MINUS_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_rminusBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_RMINUS_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_timesBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_TIMES_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_divBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_DIV_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_rdivBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_RDIV_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_iseqBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISEQ_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isneBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISNE_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isgtBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISGT_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isltBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISLT_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isgeBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISGE_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isleBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISLE_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lorBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LOR_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_landBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LAND_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lxorBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LXOR_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_firstBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_FIRST_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_secondBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_SECOND_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_anyBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ANY_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_pairBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_PAIR_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_minBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MIN_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_maxBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MAX_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_plusBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_PLUS_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_minusBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MINUS_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_rminusBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_RMINUS_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_timesBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_TIMES_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_divBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_DIV_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_rdivBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_RDIV_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_iseqBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISEQ_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isneBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISNE_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isgtBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISGT_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isltBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISLT_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isgeBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISGE_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isleBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISLE_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lorBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LOR_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_landBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LAND_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lxorBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LXOR_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_firstBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_FIRST_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_secondBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_SECOND_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_anyBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ANY_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_pairBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_PAIR_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_minBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MIN_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_maxBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MAX_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_plusBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_PLUS_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_minusBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_MINUS_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_rminusBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_RMINUS_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_timesBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_TIMES_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_divBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_DIV_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_rdivBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_RDIV_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_iseqBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISEQ_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isneBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISNE_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isgtBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISGT_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isltBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISLT_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isgeBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISGE_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_isleBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_ISLE_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lorBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LOR_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_landBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LAND_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lxorBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LXOR_FP64, 0);
            }

            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_eqBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_EQ_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_neBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_NE_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_gtBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_GT_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_ltBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_LT_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_geBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_GE_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_leBinaryOpBoolean
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_LE_BOOL, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_eqBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_EQ_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_neBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_NE_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_gtBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_GT_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_ltBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_LT_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_geBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_GE_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_leBinaryOpByte
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_LE_INT8, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_eqBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_EQ_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_neBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_NE_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_gtBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_GT_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_ltBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_LT_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_geBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_GE_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_leBinaryOpShort
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_LE_INT16, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_eqBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_EQ_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_neBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_NE_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_gtBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_GT_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_ltBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_LT_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_geBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_GE_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_leBinaryOpInt
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_LE_INT32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_eqBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_EQ_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_neBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_NE_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_gtBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_GT_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_ltBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_LT_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_geBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_GE_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_leBinaryOpLong
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_LE_INT64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_eqBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_EQ_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_neBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_NE_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_gtBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_GT_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_ltBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_LT_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_geBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_GE_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_leBinaryOpFloat
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_LE_FP32, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_eqBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_EQ_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_neBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_NE_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_gtBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_GT_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_ltBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_LT_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_geBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_GE_FP64, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_leBinaryOpDouble
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GrB_LE_FP64, 0);
            }

        JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lorBinaryOp
        (JNIEnv * env, jclass cls){
        return (*env)->NewDirectByteBuffer(env, GrB_LOR, 0);
        }
        JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_landBinaryOp
        (JNIEnv * env, jclass cls){
        return (*env)->NewDirectByteBuffer(env, GrB_LAND, 0);
        }
        JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_lxorBinaryOp
        (JNIEnv * env, jclass cls){
        return (*env)->NewDirectByteBuffer(env, GrB_LXOR, 0);
        }

            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_minMonoidByte
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_MIN_INT8_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_maxMonoidByte
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_MAX_INT8_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_plusMonoidByte
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_PLUS_INT8_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_timesMonoidByte
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_TIMES_INT8_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_anyMonoidByte
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_ANY_INT8_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_minMonoidShort
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_MIN_INT16_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_maxMonoidShort
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_MAX_INT16_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_plusMonoidShort
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_PLUS_INT16_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_timesMonoidShort
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_TIMES_INT16_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_anyMonoidShort
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_ANY_INT16_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_minMonoidInt
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_MIN_INT32_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_maxMonoidInt
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_MAX_INT32_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_plusMonoidInt
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_PLUS_INT32_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_timesMonoidInt
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_TIMES_INT32_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_anyMonoidInt
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_ANY_INT32_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_minMonoidLong
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_MIN_INT64_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_maxMonoidLong
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_MAX_INT64_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_plusMonoidLong
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_PLUS_INT64_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_timesMonoidLong
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_TIMES_INT64_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_anyMonoidLong
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_ANY_INT64_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_minMonoidFloat
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_MIN_FP32_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_maxMonoidFloat
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_MAX_FP32_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_plusMonoidFloat
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_PLUS_FP32_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_timesMonoidFloat
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_TIMES_FP32_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_anyMonoidFloat
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_ANY_FP32_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_minMonoidDouble
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_MIN_FP64_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_maxMonoidDouble
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_MAX_FP64_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_plusMonoidDouble
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_PLUS_FP64_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_timesMonoidDouble
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_TIMES_FP64_MONOID, 0);
            }
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_anyMonoidDouble
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, GxB_ANY_FP64_MONOID, 0);
            }

        JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_lorMonoid
        (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LOR_BOOL_MONOID, 0);
        }
        JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_landMonoid
        (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LAND_BOOL_MONOID, 0);
        }
        JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_lxorMonoid
        (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_LXOR_BOOL_MONOID, 0);
        }
        JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_eqBoolMonoid
        (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, GxB_EQ_BOOL_MONOID, 0);
        }
