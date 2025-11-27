#include <jni.h>

JNIEXPORT jint JNICALL Java_Callbacks_Callbacks_apply_1callback(JNIEnv *env, jobject this, jint value, jobject callback) {
    jclass callback_class = (*env)->GetObjectClass(env, callback);

    jmethodID callback_id = (*env)->GetMethodID(env, callback_class, "callback", "(I)I");

    jint result = (*env)->CallIntMethod(env, callback, callback_id, value);

    (*env)->DeleteLocalRef(env, callback_class);
    (*env)->DeleteLocalRef(env, callback);

    return result;
}

JNIEXPORT jobject JNICALL Java_Callbacks_Callbacks_apply_1bicallback(JNIEnv *env, jobject this, jint x, jint y, jobject callback) {
    jclass integer_class = (*env)->FindClass(env, "java/lang/Integer");
    jmethodID integer_init = (*env)->GetMethodID(env, integer_class, "<init>", "(I)V");

    jobject x_obj = (*env)->NewObject(env, integer_class, integer_init, x);
    jobject y_obj = (*env)->NewObject(env, integer_class, integer_init, y);

    jclass callback_class = (*env)->GetObjectClass(env, callback);
    jmethodID callback_id = (*env)->GetMethodID(env, callback_class, "apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");

    jobject result = (*env)->CallObjectMethod(env, callback, callback_id, x_obj, y_obj);

    (*env)->DeleteLocalRef(env, x_obj);
    (*env)->DeleteLocalRef(env, y_obj);
    (*env)->DeleteLocalRef(env, integer_class);
    (*env)->DeleteLocalRef(env, callback_class);
    (*env)->DeleteLocalRef(env, callback);

    return result;
}
