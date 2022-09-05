//
// Created by katle on 9/5/2022.
//

#ifndef TIMER_KATTIMER_H
#define TIMER_KATTIMER_H

#include <chrono>

class KatTimer {
public:

    std::chrono::high_resolution_clock::time_point start;

    KatTimer();

    double getTimeMS();
};


#endif //TIMER_KATTIMER_H
