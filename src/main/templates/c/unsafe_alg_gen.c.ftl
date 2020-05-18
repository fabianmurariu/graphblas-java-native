#include "com_github_fabianmurariu_unsafe_GRBALG.h"
#include <stdlib.h>
#include <jni.h>
#include "GraphBLAS.h"
#include <assert.h>

<#list properties.types as prop>

JNIEXPORT j${prop.java_type} JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_matrixReduceAll${prop.java_type?cap_first}
  (JNIEnv * env, jclass cls, j${prop.java_type} init, jobject accum, jobject monoid, jobject mat, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        ${prop.c_type} result = init;
        GrB_Matrix_reduce_${prop.grb_type}(&result, acc, m, A, d);
        return result;
  }
</#list>

<#list properties.types as prop>

JNIEXPORT j${prop.java_type} JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_vectorReduceAll${prop.java_type?cap_first}
  (JNIEnv * env, jclass cls, j${prop.java_type} init, jobject accum, jobject monoid, jobject vec, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        ${prop.c_type} result = init;
        GrB_Vector_reduce_${prop.grb_type}(&result, acc, m, A, d);
        return result;
  }
</#list>
