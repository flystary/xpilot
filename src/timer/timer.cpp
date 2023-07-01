//

#include <cstring>
#include <ctime>

#include "config/config.h"
#include "timer/timer.h"


static timer_t activationTimer;

void initTimer(timer_t& timer, void (*handleFun)(sigval), int intervalSec, int delaySec, int sival_int);

void initTimers() {
    int delaySec = 20;
    int sival = 1;

    initTimer(activationTimer, handleActivationTimer, 60, delaySec++, sival++);
}

void initTimer(timer_t& timer, void (*handleFun)(sigval), int intervalSec, int delaySec, int sival_int) {
    struct sigevent evp;
    struct itimerspec its;

    memset(&evp, 0, sizeof(evp));
    evp.sigev_value.sival_ptr = &timer;
    evp.sigev_notify = SIGEV_THREAD;
    evp.sigev_notify_function = handleFun;
    evp.sigev_value.sival_int = sival_int;

    if (timer_create(CLOCK_REALTIME, &evp, &timer)) {
        logger.error("timer create error");
    }

    its.it_interval.tv_sec = intervalSec;
    its.it_interval.tv_nsec = 0;
    its.it_value.tv_sec = delaySec;
    its.it_value.tv_nsec = 0;

    if (timer_settime(timer, 0, &its, NULL)) {
        logger.error("timer create error");
    }
}

void stopTimers() {
    timer_delete(activationTimer);
}
