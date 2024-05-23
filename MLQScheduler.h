#ifndef MLQSCHEDULER_H
#define MLQSCHEDULER_H
#include "SchedulingAlgorithm.h"


#include <vector>
#include <queue>
#include <iostream>
#include <stdexcept>
#include <iomanip>

class Process {
public:
    static int nextPID;
    int pid; // Process ID
    int arrivalTime;
    int burstTime;
    int priority; // Priority level (0 = highest priority)
    int startTime;
    int finishTime;
    int remainingTime;
    int waitTime;
    int responseTime;
    bool started;

    Process(int a, int b, int pr);
};

class MLQScheduler {
public:
    virtual void addProcess(int arrivalTime, int burstTime, int priority) = 0;
    virtual void schedule() = 0;
    virtual void displayProcesses() = 0;
    virtual ~MLQScheduler() = default;
};

void executeScheduler();

#endif // MLQSCHEDULER_H
