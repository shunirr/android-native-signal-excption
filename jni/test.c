#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

#include <android/log.h>

#include "jp_s5r_android_signal_TestActivity.h"

#define LOGD(...) (__android_log_print(ANDROID_LOG_DEBUG, "ANSE", __VA_ARGS__))

jmp_buf g_jmp;
JNIEnv* g_env;

static void handler(int sig)
{
    jclass exception;
    
    signal(sig, SIG_IGN);

    LOGD("SIGSEGV!");

    exception = (*g_env)->FindClass(g_env, "java/lang/RuntimeException");
    if (exception != NULL) {
        (*g_env)->ThrowNew(g_env, exception, "THIS IS NATIVE RUNTIME EXCEPTION !!! CALLED SIGSEGV !!!!");
        (*g_env)->DeleteLocalRef(g_env, exception);
        longjmp(g_jmp, 1);
    }
}

static void register_handler(JNIEnv* env)
{
    g_env = env;
    signal(SIGSEGV, &handler);
}

void Java_jp_s5r_android_signal_TestActivity_nativeMethod(JNIEnv* env, jobject thiz)
{
    int* i;

    register_handler(env);
    if (setjmp(g_jmp) == 0) {
        *i = 10;
    }
}

