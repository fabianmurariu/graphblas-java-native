#include "com_github_fabianmurariu_unsafe_GRAPHBLAS.h"
#include "com_github_fabianmurariu_unsafe_GRBMONOID.h"
#include <stdlib.h>
#include <jni.h>
#include "GraphBLAS.h"
#include <assert.h>
long check_grb_error(GrB_Info info);


            // generic functions
            <#list properties.types as prop>

            JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_${prop.java_type}Type
            (JNIEnv * env, jclass cls) {
                return (*env)->NewDirectByteBuffer(env, GrB_${prop.grb_type}, 0);
            }

            </#list>

            <#list properties.types as prop>
            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setMatrixElement${prop.java_type?cap_first}
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j, j${prop.java_type} value) {
                GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = (GrB_Index)i;
                GrB_Index J = (GrB_Index)j;
                return check_grb_error( GrB_Matrix_setElement_${prop.grb_type}(A, value, I, J) ) ;
            }


            JNIEXPORT j${prop.java_type}Array JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getMatrixElement${prop.java_type?cap_first}
            (JNIEnv * env, jclass cls, jobject mat, jlong i, jlong j) {
                ${prop.c_type} x;
                GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = (GrB_Index)i;
                GrB_Index J = (GrB_Index)j;
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


            // FIXME: this is terrible, we copy twice the indices because java does not have an option for unsigned long
            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_extractMatrixTuples${prop.java_type?cap_first}
              (JNIEnv * env, jclass cls, jobject mat, j${prop.java_type}Array vs, jlongArray is, jlongArray js) {
                GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index nvals;
                GrB_Matrix_nvals(&nvals, A);

                j${prop.java_type} *elms = (*env)->GetPrimitiveArrayCritical(env, vs, NULL);
                GrB_Index * java_is = (GrB_Index*) (*env)->GetPrimitiveArrayCritical(env, is, NULL);
                GrB_Index * java_js = (GrB_Index*) (*env)->GetPrimitiveArrayCritical(env, js, NULL);

                long res = check_grb_error(GrB_Matrix_extractTuples_${prop.grb_type}(java_is, java_js, elms, &nvals, A));

                // JNI tell Java we're done
                (*env)->ReleasePrimitiveArrayCritical(env, vs, elms, 0);
                (*env)->ReleasePrimitiveArrayCritical(env, is, java_is, 0);
                (*env)->ReleasePrimitiveArrayCritical(env, js, java_js, 0);
                return res;
              }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_extractVectorTuples${prop.java_type?cap_first}
              (JNIEnv * env, jclass cls, jobject mat, j${prop.java_type}Array vs, jlongArray is) {
                GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index nvals;
                GrB_Vector_nvals(&nvals, A);

                j${prop.java_type} *elms = (*env)->GetPrimitiveArrayCritical(env, vs, NULL);
                GrB_Index *java_is = (GrB_Index*) (*env)->GetPrimitiveArrayCritical(env, is, NULL);

                long res = check_grb_error(GrB_Vector_extractTuples_${prop.grb_type}(java_is, elms, &nvals, A));

                // JNI tell Java we're done
                (*env)->ReleasePrimitiveArrayCritical(env, vs, elms, 0);
                (*env)->ReleasePrimitiveArrayCritical(env, is, java_is, 0);
                return res;
              }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_buildMatrixFromTuples${prop.java_type?cap_first}
              (JNIEnv * env, jclass cls, jobject mat, jlongArray is, jlongArray js, j${prop.java_type}Array vs, jlong n, jobject dupOp) {
                GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
                GrB_BinaryOp dup = (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, dupOp);
                GrB_Index nvals = (GrB_Index)n;

                j${prop.java_type}* elms = (*env)->GetPrimitiveArrayCritical(env, vs, NULL);
                GrB_Index* java_is = (GrB_Index*) (*env)->GetPrimitiveArrayCritical(env, is, NULL);
                GrB_Index* java_js = (GrB_Index*) (*env)->GetPrimitiveArrayCritical(env, js, NULL);

                long res = check_grb_error(GrB_Matrix_build_${prop.grb_type}(A, java_is, java_js, elms, nvals, dup));
                // JNI tell Java we're done
                (*env)->ReleasePrimitiveArrayCritical(env, vs, elms, 0);
                (*env)->ReleasePrimitiveArrayCritical(env, is, java_is, 0);
                (*env)->ReleasePrimitiveArrayCritical(env, js, java_js, 0);
                return res;
              }

            JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_buildVectorFromTuples${prop.java_type?cap_first}
              (JNIEnv * env, jclass cls, jobject mat, jlongArray is, j${prop.java_type}Array vs, jlong n, jobject dupOp) {
                GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
                GrB_BinaryOp dup = (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, dupOp);
                GrB_Index nvals = (GrB_Index)n;

                j${prop.java_type} *elms = (*env)->GetPrimitiveArrayCritical(env, vs, NULL);
                GrB_Index* java_is = (GrB_Index*) (*env)->GetPrimitiveArrayCritical(env, is, NULL);

                long res = check_grb_error(GrB_Vector_build_${prop.grb_type}(A, java_is, elms, nvals, dup));
                // JNI tell Java we're done
                (*env)->ReleasePrimitiveArrayCritical(env, vs, elms, 0);
                (*env)->ReleasePrimitiveArrayCritical(env, is, java_is, 0);
                return res;
              }
            </#list>

            <#list properties.types as prop>
                JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_setVectorElement${prop.java_type?cap_first}
                (JNIEnv * env, jclass cls, jobject mat, jlong i, j${prop.java_type} value) {
                GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = (GrB_Index) i;
                return check_grb_error( GrB_Vector_setElement_${prop.grb_type}(A, value, I) ) ;
                }


                JNIEXPORT j${prop.java_type}Array JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_getVectorElement${prop.java_type?cap_first}
                (JNIEnv * env, jclass cls, jobject mat, jlong i) {
                ${prop.c_type} x;
                GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, mat);
                GrB_Index I = (GrB_Index) i;
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
                JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_assignVector${prop.java_type?cap_first}
                (JNIEnv * env, jclass cls, jobject vec, jobject mask, jobject accum, j${prop.java_type} value,  jlongArray is, jlong ni, jobject desc) {

                // NON OPTIONAL STUFF
                GrB_Vector w = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);

                GrB_Index* I = NULL;
                GrB_Index grb_ni = (GrB_Index) ni;
                jlong * java_is = (*env)->GetPrimitiveArrayCritical(env, is, NULL);
                long java_min = -9223372036854775808;

                I = java_is[0] != java_min ? (GrB_Index*) java_is : GrB_ALL;

                // OPTIONAL STUFF
                GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
                GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;
                GrB_Vector m = mask != NULL ? (GrB_Vector) (*env)->GetDirectBufferAddress(env, mask) : NULL;


                long res = check_grb_error(GrB_Vector_assign_${prop.grb_type}(w, m, acc, value, I, grb_ni, d));

                (*env)->ReleasePrimitiveArrayCritical(env, is, java_is, 0);

                return res;
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

JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRBMONOID_createMonoid${prop.java_type?cap_first}
  (JNIEnv * env, jclass cls, jobject bin_op, j${prop.java_type} identity) {
        GrB_BinaryOp op = (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, bin_op);
        GrB_Monoid m;
        ${prop.c_type} id = identity;
        GrB_Info status = GrB_Monoid_new(&m, op, id);
        check_grb_error(status);
        return (*env)->NewDirectByteBuffer(env, m, 0);
  }

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

    <#list properties.select_ops as op>
        JNIEXPORT jobject JNICALL Java_com_github_fabianmurariu_unsafe_GRAPHBLAS_selectOp${op}
        (JNIEnv * env, jclass cls){
        return (*env)->NewDirectByteBuffer(env, GxB_${op}, 0);
        }
    </#list>
