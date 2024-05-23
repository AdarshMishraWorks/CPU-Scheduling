#ifndef FB_SCHEDULER_H
#define FB_SCHEDULER_H

#include "SchedulingAlgorithm.h"
#include <iostream>

class FBScheduler : public SchedulingAlgorithm {
public:
    void WRR_Scheduling() override;
    void EDF_Scheduling() override;
    void F_B_Scheduling() override;
    void MLQ_Scheduling() override;
};

#endif // FB_SCHEDULER_H
