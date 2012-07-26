#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

#include <android/log.h>

#include "jp_s5r_android_signal_TestActivity.h"

#define LOGD(...) (__android_log_print(ANDROID_LOG_DEBUG, "ANSE", __VA_ARGS__))

jmp_buf g_jmp;
JNIEnv* g_env;

void handler(int sig)
{
    jclass exception;

    LOGD("SIGSEGV!");

    signal(sig, SIG_IGN);

    exception = (*g_env)->FindClass(g_env, "java/lang/RuntimeException");
    if (exception != NULL) {
        (*g_env)->ThrowNew(g_env, exception, "THIS IS NATIVE RUNTIME EXCEPTION !!! CALLED SIGSEGV !!!!");
        (*g_env)->DeleteLocalRef(g_env, exception);
        longjmp(g_jmp, 1);
    }
}

void Java_jp_s5r_android_signal_TestActivity_nativeMethod(JNIEnv* env, jobject thiz)
{
    int ret = 0;
    int* i;

    g_env = env;
    signal(SIGSEGV, &handler);

    ret = setjmp(g_jmp);
    if (ret == 0) {
        *i = 10;
    }
}
