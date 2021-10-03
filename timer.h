#include "Sorter.h"
#include "chrono"
#ifndef DUDE_TIMER_H
#define DUDE_TIMER_H

class Timer {
private:
    std::chrono::system_clock::time_point Start_Time;
public:
    void Start()
    {
        Start_Time = std::chrono::high_resolution_clock::now();
    }
    float GetDuration()
    {
        std::chrono::duration<float, std::micro> duration = std::chrono::high_resolution_clock::now() - Start_Time;
        return duration.count();
    }
};

#endif //DUDE_TIMER_H
