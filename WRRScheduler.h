#ifndef WRR_SCHEDULER_H
#define WRR_SCHEDULER_H

#include "SchedulingAlgorithm.h"
#include <iostream>

class WRRScheduler : public SchedulingAlgorithm {
public:
    void WRR_Scheduling() override;
    void EDF_Scheduling() override;
    void F_B_Scheduling() override;
    void MLQScheduler() override;

    struct Process {
        int id;
        int weight;
        int burstTime;
        int remainingTime;
    };
};

#endif // WRR_SCHEDULER_H
