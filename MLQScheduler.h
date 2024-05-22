#ifndef MLQ_SCHEDULER_H
#define MLQ_SCHEDULER_H

#include "SchedulingAlgorithm.h"
#include <iostream>

class MLQScheduler : public SchedulingAlgorithm {
public:
    void WRR_Scheduling() override;
    void EDF_Scheduling() override;
    void F_B_Scheduling() override;
    void MLQ_Scheduling() override;
};

#endif // MLQ_SCHEDULER_H
