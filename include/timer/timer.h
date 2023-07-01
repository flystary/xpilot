#ifndef TIMER_H
#define TIMER_H

#include <csignal>

void initTimers();

void stopTimers();

void handleActivation(union sigval v);

#endif
