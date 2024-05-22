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
private:
    static const int MAX_PROCESSES = 10;
    int foregroundProcesses[MAX_PROCESSES];
    int backgroundProcesses[MAX_PROCESSES];
    int foregroundBurstTimes[MAX_PROCESSES];
    int backgroundBurstTimes[MAX_PROCESSES];
    int fgCount = 0;
    int bgCount = 0;

    void addForegroundProcess(int burstTime);
    void addBackgroundProcess(int burstTime);
    void executeProcesses();
};

#endif // FB_SCHEDULER_H
