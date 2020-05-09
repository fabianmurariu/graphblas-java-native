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

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_nvals
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            long n;
            check_grb_error(GrB_Matrix_nvals(&n, A) );
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
            long n;
            check_grb_error(GrB_Matrix_ncols(&n, A) );
            return n;
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRBCORE_free
            (JNIEnv * env, jclass cls, jobject mat) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
            check_grb_error(GrB_Matrix_free(&A) );
            }
            // generic functions
            <#list properties as prop>

            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_${prop.java_type}Type
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_${prop.grb_type}, 0);
            }

            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setElement${prop.java_type?cap_first}
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, j${prop.java_type} value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            check_grb_error( GrB_Matrix_setElement_${prop.grb_type}(A, value, I, J) ) ;
            }


            JNIEXPORT j${prop.java_type}Array JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getElement${prop.java_type?cap_first}
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
            ${prop.c_type} x;
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            GrB_Info info = GrB_Matrix_extractElement_${prop.grb_type}(&x, A, I, J);
            j${prop.java_type}Array output;
            if (info == GrB_NO_VALUE) {
            output = (*env)->New${prop.java_type?cap_first}Array(env, 0);
            } else {
            output = (*env)->New${prop.java_type?cap_first}Array(env, 1);
            ${prop.c_type} xs[] = {x};
            (*env)->Set${prop.java_type?cap_first}ArrayRegion(env, output, 0, 1, xs);
            }
            return output;
            }

            </#list>
