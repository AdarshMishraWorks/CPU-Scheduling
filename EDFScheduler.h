#ifndef EDF_SCHEDULER_H
#define EDF_SCHEDULER_H

#include "SchedulingAlgorithm.h"
#include <iostream>

class EDFScheduler : public SchedulingAlgorithm {
public:
    void WRR_Scheduling() override;
    void EDF_Scheduling() override;
    void F_B_Scheduling() override;
    void MLFQ_Scheduling() override;
};

#endif // EDF_SCHEDULER_H
