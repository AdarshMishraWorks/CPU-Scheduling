#ifndef MLFQ_SCHEDULER_H
#define MLFQ_SCHEDULER_H

#include "SchedulingAlgorithm.h"
#include <iostream>

class MLFQScheduler : public SchedulingAlgorithm {
public:
    void WRR_Scheduling() override;
    void EDF_Scheduling() override;
    void F_B_Scheduling() override;
    void MLFQ_Scheduling() override;
};

#endif // MLFQ_SCHEDULER_H
