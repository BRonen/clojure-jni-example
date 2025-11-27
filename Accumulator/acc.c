#include <jni.h>
#include <stdio.h>
#include "Accumulator_Acc.h"

jfieldID getValueFieldId(JNIEnv *env, jobject thisObj) {
    jclass this_class = (*env)->GetObjectClass(env, thisObj);

    jfieldID fid = (*env)->GetFieldID(env, this_class, "value", "I");

    (*env)->DeleteLocalRef(env, this_class);

    return fid;
}

JNIEXPORT void JNICALL Java_Accumulator_Acc_accumulate(JNIEnv *env, jobject thisObj, jint x) {
    jfieldID field_id = getValueFieldId(env, thisObj);
    if (field_id == NULL) {
        jclass exClass = (*env)->FindClass(env, "java/lang/Exception");
        (*env)->ThrowNew(env, exClass, "Error while access accumulator value.");
        return;
    }

    jint current_value = (*env)->GetIntField(env, thisObj, field_id);

    printf("[C] Accumulate called with: %d\n", x);
    printf("[C] Accumulator currently holding: %d\n", current_value);

    (*env)->SetIntField(env, thisObj, field_id, current_value + x);
}

JNIEXPORT jint JNICALL Java_Accumulator_Acc_getValue(JNIEnv *env, jobject thisObj) {
    jfieldID field_id = getValueFieldId(env, thisObj);
    if (field_id == NULL) {
        jclass exClass = (*env)->FindClass(env, "java/lang/Exception");
        (*env)->ThrowNew(env, exClass, "Error while access accumulator value.");
        return 0;
    }

    jint current_value = (*env)->GetIntField(env, thisObj, field_id);

    printf("[C] Accumulator getter called while holding: %d\n", current_value);

    return current_value;
}
