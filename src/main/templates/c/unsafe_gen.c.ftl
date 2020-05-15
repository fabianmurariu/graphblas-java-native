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
            <#list properties.types as prop>

            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_${prop.java_type}Type
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, GrB_${prop.grb_type}, 0);
            }

            </#list>

            <#list properties.types as prop>
            JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setMatrixElement${prop.java_type?cap_first}
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, j${prop.java_type} value) {
            GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Index J = j;
            check_grb_error( GrB_Matrix_setElement_${prop.grb_type}(A, value, I, J) ) ;
            }


            JNIEXPORT j${prop.java_type}Array JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getMatrixElement${prop.java_type?cap_first}
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

            <#list properties.types as prop>
                JNIEXPORT void JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setVectorElement${prop.java_type?cap_first}
                (JNIEnv * env, jclass cls, jobject mat, jlong i, j${prop.java_type} value) {
                GrB_Vector A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                check_grb_error( GrB_Vector_setElement_${prop.grb_type}(A, value, I) ) ;
                }


                JNIEXPORT j${prop.java_type}Array JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getVectorElement${prop.java_type?cap_first}
                (JNIEnv * env, jclass cls, jobject mat, jlong i) {
                ${prop.c_type} x;
                GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = i;
                GrB_Info info = GrB_Vector_extractElement_${prop.grb_type}(&x, A, I);
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

    <#list properties.types as prop>
        <#list properties.unary_ops as uop>
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_${uop.name}UnaryOp${prop.java_type?cap_first}
            (JNIEnv * env, jclass cls) {
            return (*env)->NewDirectByteBuffer(env, ${uop.grb_name}_${prop.grb_type}, 0);
            }
        </#list>
    </#list>

    <#list properties.types as prop>
        <#list properties.binary_ops as op>
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_${op.name}BinaryOp${prop.java_type?cap_first}
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, ${op.grb_name}_${prop.grb_type}, 0);
            }
        </#list>
    </#list>

    <#list properties.types as prop>
        <#list properties.binary_ops_bool as op>
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_${op.name}BinaryOp${prop.java_type?cap_first}
            (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, ${op.grb_name}_${prop.grb_type}, 0);
            }
        </#list>
    </#list>

    <#list properties.binary_ops_bool_bool as op>
        JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_${op.name}BinaryOp
        (JNIEnv * env, jclass cls){
        return (*env)->NewDirectByteBuffer(env, ${op.grb_name}, 0);
        }
    </#list>

    <#list properties.types as prop>
    <#if prop.java_type != "boolean" >
        <#list properties.monoids as op>
            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_${op.name}Monoid${prop.java_type?cap_first}
            (JNIEnv * env, jclass cls){
                return (*env)->NewDirectByteBuffer(env, ${op.grb_name}_${prop.grb_type}_MONOID, 0);
            }
        </#list>
    </#if>
    </#list>

    <#list properties.monoids_bool as op>
        JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_${op.name}Monoid
        (JNIEnv * env, jclass cls){
            return (*env)->NewDirectByteBuffer(env, ${op.grb_name}_BOOL_MONOID, 0);
        }
    </#list>
