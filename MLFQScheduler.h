#pragma once
#ifndef MLFQ_SCHEDULER_H
#define MLFQ_SCHEDULER_H

#include <vector>
#include <queue>

class Process {
public:
    int id;
    int burstTime;
    int remainingTime;
    bool ioBound; // Indicates whether the process is I/O bound

    Process(int id, int burstTime, bool ioBound);
};

class MLFQScheduler {
private:
    std::vector<std::queue<Process>> queues;
    std::vector<int> timeQuanta;
    int processCounter;

public:
    MLFQScheduler(std::vector<int> timeQuanta);
    void addProcesses(std::vector<std::vector<int>>& processes);
    void run();
    void displayQueues();
    bool allQueuesEmpty();
};

#endif
