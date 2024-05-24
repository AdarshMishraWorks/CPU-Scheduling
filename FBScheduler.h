#ifndef FB_SCHEDULER_H
#define FB_SCHEDULER_H

#include "SchedulingAlgorithm.h"
#include <iostream>

class FBScheduler : public SchedulingAlgorithm {
public:
    void WRR_Scheduling() override;
    void EDF_Scheduling() override;
    void F_B_Scheduling() override;
    void MLQScheduler() override;
private:
    static const int MAX_PROCESSES = 10;          
    int foregroundProcesses[MAX_PROCESSES];       
    int backgroundProcesses[MAX_PROCESSES];        
    int foregroundBurstTimes[MAX_PROCESSES];       
    int backgroundBurstTimes[MAX_PROCESSES];       
    int fgCount = 0;                               
    int bgCount = 0;                               

    void addForegroundProcess(int burstTime, int fgBurstTimes[], int index);  
    void addBackgroundProcess(int burstTime, int bgBurstTimes[], int index);  
    void executeProcesses(int fgBurstTimes[], int bgBurstTimes[], int fgCount, int bgCount);  
};

#endif // FB_SCHEDULER_H
