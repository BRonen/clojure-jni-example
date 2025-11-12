#include <jni.h>
#include <stdio.h>
#include "Foo.h"

JNIEXPORT void JNICALL Java_Foo_helloworld(JNIEnv *env, jobject thisObj) {
  printf("[C] Hello world.\n");
}

JNIEXPORT jstring JNICALL Java_Foo_echo(JNIEnv *env, jobject thisObj, jstring sometext) {
  const char *received_string = (*env)->GetStringUTFChars(env, sometext, NULL);
  if (received_string == NULL)
    return NULL;

  printf("[C] Received: %s\n", received_string);

  jstring result = (*env)->NewStringUTF(env, received_string);

  (*env)->ReleaseStringUTFChars(env, sometext, received_string);

  return result;
}

JNIEXPORT jint JNICALL Java_Foo_arraysum(JNIEnv *env, jobject thisObj, jintArray numbers) {
  jsize length = (*env)->GetArrayLength(env, numbers);

  jint *arr = (*env)->GetIntArrayElements(env, numbers, NULL);
  if (arr == NULL) {
    jclass exClass = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
    (*env)->ThrowNew(env, exClass, "Error while trying to sum.");
    return 0;
  }

  printf("[C] Received array: [ %d", arr[0]);
  for (jsize i = 1; i < length; i++)
    printf(", %d", arr[i]);
  printf(" ]\n");

  int sum = 0;
  for (jsize i = 0; i < length; i++)
    sum = sum + arr[i];

  (*env)->ReleaseIntArrayElements(env, numbers, arr, 0);

  return sum;
}
