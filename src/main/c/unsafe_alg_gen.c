#include "com_github_fabianmurariu_unsafe_GRBALG.h"
#include <stdlib.h>
#include <jni.h>
#include "GraphBLAS.h"
#include <assert.h>


JNIEXPORT jboolean JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_matrixReduceAllBoolean
  (JNIEnv * env, jclass cls, jboolean init, jobject accum, jobject monoid, jobject mat, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        bool result = init;
        GrB_Matrix_reduce_BOOL(&result, acc, m, A, d);
        return result;
  }

JNIEXPORT jbyte JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_matrixReduceAllByte
  (JNIEnv * env, jclass cls, jbyte init, jobject accum, jobject monoid, jobject mat, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        int8_t result = init;
        GrB_Matrix_reduce_INT8(&result, acc, m, A, d);
        return result;
  }

JNIEXPORT jshort JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_matrixReduceAllShort
  (JNIEnv * env, jclass cls, jshort init, jobject accum, jobject monoid, jobject mat, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        short result = init;
        GrB_Matrix_reduce_INT16(&result, acc, m, A, d);
        return result;
  }

JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_matrixReduceAllInt
  (JNIEnv * env, jclass cls, jint init, jobject accum, jobject monoid, jobject mat, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        int result = init;
        GrB_Matrix_reduce_INT32(&result, acc, m, A, d);
        return result;
  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_matrixReduceAllLong
  (JNIEnv * env, jclass cls, jlong init, jobject accum, jobject monoid, jobject mat, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        long result = init;
        GrB_Matrix_reduce_INT64(&result, acc, m, A, d);
        return result;
  }

JNIEXPORT jfloat JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_matrixReduceAllFloat
  (JNIEnv * env, jclass cls, jfloat init, jobject accum, jobject monoid, jobject mat, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        float result = init;
        GrB_Matrix_reduce_FP32(&result, acc, m, A, d);
        return result;
  }

JNIEXPORT jdouble JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_matrixReduceAllDouble
  (JNIEnv * env, jclass cls, jdouble init, jobject accum, jobject monoid, jobject mat, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Matrix A = (GrB_Matrix) (*env)->GetDirectBufferAddress(env, mat);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        double result = init;
        GrB_Matrix_reduce_FP64(&result, acc, m, A, d);
        return result;
  }


JNIEXPORT jboolean JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_vectorReduceAllBoolean
  (JNIEnv * env, jclass cls, jboolean init, jobject accum, jobject monoid, jobject vec, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        bool result = init;
        GrB_Vector_reduce_BOOL(&result, acc, m, A, d);
        return result;
  }

JNIEXPORT jbyte JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_vectorReduceAllByte
  (JNIEnv * env, jclass cls, jbyte init, jobject accum, jobject monoid, jobject vec, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        int8_t result = init;
        GrB_Vector_reduce_INT8(&result, acc, m, A, d);
        return result;
  }

JNIEXPORT jshort JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_vectorReduceAllShort
  (JNIEnv * env, jclass cls, jshort init, jobject accum, jobject monoid, jobject vec, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        short result = init;
        GrB_Vector_reduce_INT16(&result, acc, m, A, d);
        return result;
  }

JNIEXPORT jint JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_vectorReduceAllInt
  (JNIEnv * env, jclass cls, jint init, jobject accum, jobject monoid, jobject vec, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        int result = init;
        GrB_Vector_reduce_INT32(&result, acc, m, A, d);
        return result;
  }

JNIEXPORT jlong JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_vectorReduceAllLong
  (JNIEnv * env, jclass cls, jlong init, jobject accum, jobject monoid, jobject vec, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        long result = init;
        GrB_Vector_reduce_INT64(&result, acc, m, A, d);
        return result;
  }

JNIEXPORT jfloat JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_vectorReduceAllFloat
  (JNIEnv * env, jclass cls, jfloat init, jobject accum, jobject monoid, jobject vec, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        float result = init;
        GrB_Vector_reduce_FP32(&result, acc, m, A, d);
        return result;
  }

JNIEXPORT jdouble JNICALL Java_com_github_fabianmurariu_unsafe_GRBALG_vectorReduceAllDouble
  (JNIEnv * env, jclass cls, jdouble init, jobject accum, jobject monoid, jobject vec, jobject desc) {

        // NON OPTIONAL STUFF
        GrB_Vector A = (GrB_Vector) (*env)->GetDirectBufferAddress(env, vec);
        GrB_Monoid m = (GrB_Monoid) (*env)->GetDirectBufferAddress(env, monoid);

        // OPTIONAL STUFF
        GrB_BinaryOp acc = accum != NULL ? (GrB_BinaryOp) (*env)->GetDirectBufferAddress(env, accum): NULL;
        GrB_Descriptor d = desc != NULL ? (GrB_Descriptor) (*env)->GetDirectBufferAddress(env, desc) : NULL;

        double result = init;
        GrB_Vector_reduce_FP64(&result, acc, m, A, d);
        return result;
  }
