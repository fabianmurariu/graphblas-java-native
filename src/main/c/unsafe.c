#include "com_github_fabianmurariu_unsafe_GRAPHBLAS.h"
#include "com_github_fabianmurariu_unsafe_GRBCORE.h"
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
            check_grb_error (GrB_Matrix_new(&A, grb_type, rows, cols) );
            return (*env)->NewDirectByteBuffer(env, A, 0);
            }

            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_createVector
            (JNIEnv * env, jclass cls, jobject tpe, jlong size) {
            GrB_Type grb_type = (GrB_Type) (*env)->GetDirectBufferAddress(env, tpe);
            GrB_Vector A;
            check_grb_error (GrB_Vector_new(&A, grb_type, size) );
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
            long n;
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
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
            check_grb_error(GrB_Vector_free(&A) );
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

