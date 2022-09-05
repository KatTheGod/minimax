//
// Created by katle on 9/5/2022.
//

#include "KatTimer.h"

KatTimer::KatTimer() {
    start = std::chrono::high_resolution_clock::now();
}

double KatTimer::getTimeMS() {
    std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
    return time_span.count() * 1000;
}
