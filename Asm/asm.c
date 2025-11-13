#include <jni.h>
#include <stdio.h>
#include <string.h>
#include "Asm_Asm.h"

JNIEXPORT void JNICALL Java_Asm_Asm_inlineasm(JNIEnv *env, jobject thisObj, jstring sometext) {
  const char *received_string = (*env)->GetStringUTFChars(env, sometext, NULL);
  if (received_string == NULL) {
    jclass exClass = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
    (*env)->ThrowNew(env, exClass, "Error while reading string parameter.");
    return;
  }

  printf("[C - Inline Asm] Received: %s", received_string);

  long len = (long)strlen(received_string);

  asm volatile (
    "mov $1, %%rax\n\t" // 1 (write) -> rax
    "mov $2, %%rdi\n\t" // 1 (stdout) -> rdi
    "mov %0, %%rsi\n\t" // %0 -> rsi
    "mov %1, %%rdx\n\t" // %1 -> rdx
    "syscall\n\t"       // syscall
    :
    : "r"(received_string) // string pointer -> %0
    , "r"(len) // string length -> %1
    : "%rax"
    , "%rdi"
    , "%rsi"
    , "%rdx"
    );

  (*env)->ReleaseStringUTFChars(env, sometext, received_string);
}
