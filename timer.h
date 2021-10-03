#include "Sorter.h"
#include "chrono"
#ifndef DUDE_TIMER_H
#define DUDE_TIMER_H

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> Start_Time;
public:
    void Start()
    {
        Start_Time = std::chrono::high_resolution_clock::now();
    }
    float GetDuration()
    {
        return std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1>>>(std::chrono::high_resolution_clock::now() - Start_Time).count();
    }
};

#endif //DUDE_TIMER_H
