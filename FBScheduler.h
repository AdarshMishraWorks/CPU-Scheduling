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
    static const int MAX_PROCESSES = 10;           // Maximum number of processes
    int foregroundProcesses[MAX_PROCESSES];        // Array to store foreground process IDs
    int backgroundProcesses[MAX_PROCESSES];        // Array to store background process IDs
    int foregroundBurstTimes[MAX_PROCESSES];       // Array to store foreground process burst times
    int backgroundBurstTimes[MAX_PROCESSES];       // Array to store background process burst times
    int fgCount = 0;                               // Counter for the number of foreground processes
    int bgCount = 0;                               // Counter for the number of background processes

    void addForegroundProcess(int burstTime);      // Method to add a foreground process
    void addBackgroundProcess(int burstTime);      // Method to add a background process
    void executeProcesses();   
};

#endif // FB_SCHEDULER_H
