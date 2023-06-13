#include <pthread.h>
#include "utils/thread_utils.h"

int createThread(void* (*handleFun)(void*), void* arg){
    pthread_t ntid;
    pthread_attr_t attr;

    int ret;
    ret = pthread_attr_init(&attr);
    if (ret != 0) {
        return -1;
    }

    ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (ret != 0) {
        return -1;
    }
    ret = pthread_create(&ntid, &attr, handleFun, arg);
    if (ret != 0) {
        return -1;
    }
    return 0;
}

