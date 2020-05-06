#include "com_github_fabianmurariu_unsafe_GRAPHBLAS.h"
#include <stdlib.h>
#include <jni.h>
#include "GraphBLAS.h"
#include <assert.h>


            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_initNonBlocking
            (JNIEnv * env, jclass cls) {
            assert(GrB_init(GrB_NONBLOCKING) == 0);
            }


            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_createMatrix
            (JNIEnv * env, jclass cls, jobject tpe, jlong rows, jlong cols) {
            GrB_Type grb_type = (GrB_Type) (*env)->GetDirectBufferAddress(env, tpe);
            GrB_Matrix A;
            assert (GrB_Matrix_new(&A, grb_type, rows, cols) == 0);
            return (*env)->NewDirectByteBuffer(env, A, 0);
            }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_nvals
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            long n;
            assert(GrB_Matrix_nvals(&n, A) == 0);
            return n;
            }
            // generic functions
            
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_booleanType
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_BOOL, 0);
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setElementBoolean
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, jboolean value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            assert( GrB_Matrix_setElement(A, value, i, j) == 0) ;
            }


            JNIEXPORT jbooleanArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getElementBoolean
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            bool x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Info info = GrB_Matrix_extractElement(&x, A, i, j);
            jbooleanArray output;
            if (info == GrB_NO_VALUE) {
            output = (*env)->NewBooleanArray(env, 0);
            } else {
            output = (*env)->NewBooleanArray(env, 1);
            int xs[] = {x};
            (*env)->SetBooleanArrayRegion(env, output, 0, 1, xs);
            }
            return output;
            }


            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_byteType
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_INT8, 0);
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setElementByte
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, jbyte value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            assert( GrB_Matrix_setElement(A, value, i, j) == 0) ;
            }


            JNIEXPORT jbyteArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getElementByte
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            int8_t x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Info info = GrB_Matrix_extractElement(&x, A, i, j);
            jbyteArray output;
            if (info == GrB_NO_VALUE) {
            output = (*env)->NewByteArray(env, 0);
            } else {
            output = (*env)->NewByteArray(env, 1);
            int xs[] = {x};
            (*env)->SetByteArrayRegion(env, output, 0, 1, xs);
            }
            return output;
            }


            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_shortType
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_INT16, 0);
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setElementShort
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, jshort value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            assert( GrB_Matrix_setElement(A, value, i, j) == 0) ;
            }


            JNIEXPORT jshortArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getElementShort
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            int16_t x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Info info = GrB_Matrix_extractElement(&x, A, i, j);
            jshortArray output;
            if (info == GrB_NO_VALUE) {
            output = (*env)->NewShortArray(env, 0);
            } else {
            output = (*env)->NewShortArray(env, 1);
            int xs[] = {x};
            (*env)->SetShortArrayRegion(env, output, 0, 1, xs);
            }
            return output;
            }


            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_intType
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_INT32, 0);
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setElementInt
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, jint value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            assert( GrB_Matrix_setElement(A, value, i, j) == 0) ;
            }


            JNIEXPORT jintArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getElementInt
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            int32_t x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Info info = GrB_Matrix_extractElement(&x, A, i, j);
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


            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_longType
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_INT64, 0);
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setElementLong
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, jlong value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            assert( GrB_Matrix_setElement(A, value, i, j) == 0) ;
            }


            JNIEXPORT jlongArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getElementLong
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            long x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Info info = GrB_Matrix_extractElement(&x, A, i, j);
            jlongArray output;
            if (info == GrB_NO_VALUE) {
            output = (*env)->NewLongArray(env, 0);
            } else {
            output = (*env)->NewLongArray(env, 1);
            int xs[] = {x};
            (*env)->SetLongArrayRegion(env, output, 0, 1, xs);
            }
            return output;
            }


            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_floatType
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_FP32, 0);
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setElementFloat
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, jfloat value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            assert( GrB_Matrix_setElement(A, value, i, j) == 0) ;
            }


            JNIEXPORT jfloatArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getElementFloat
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            float x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Info info = GrB_Matrix_extractElement(&x, A, i, j);
            jfloatArray output;
            if (info == GrB_NO_VALUE) {
            output = (*env)->NewFloatArray(env, 0);
            } else {
            output = (*env)->NewFloatArray(env, 1);
            int xs[] = {x};
            (*env)->SetFloatArrayRegion(env, output, 0, 1, xs);
            }
            return output;
            }


            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_doubleType
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_FP64, 0);
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setElementDouble
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, jdouble value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            assert( GrB_Matrix_setElement(A, value, i, j) == 0) ;
            }


            JNIEXPORT jdoubleArray JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getElementDouble
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            double x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            GrB_Info info = GrB_Matrix_extractElement(&x, A, i, j);
            jdoubleArray output;
            if (info == GrB_NO_VALUE) {
            output = (*env)->NewDoubleArray(env, 0);
            } else {
            output = (*env)->NewDoubleArray(env, 1);
            int xs[] = {x};
            (*env)->SetDoubleArrayRegion(env, output, 0, 1, xs);
            }
            return output;
            }

