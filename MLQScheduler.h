#ifndef MLQ_SCHEDULER_H
#define MLQ_SCHEDULER_H
#include <queue>
#include <vector>
#include <string>

#include "SchedulingAlgorithm.h"
#include <iostream>

class MLQScheduler : public SchedulingAlgorithm {
public:
    void WRR_Scheduling() override;
    void EDF_Scheduling() override;
    void F_B_Scheduling() override;
    void MLQ_Scheduling() override;

    void addProcess(Process p) {
        if (p.priority >= 0 && p.priority < queues.size()) {
            queues[p.priority].push(p);
        } else {
            std::cerr << "Invalid priority for process " << p.name << std::endl;
        }
    }
    
private:
    std::vector<std::queue<Process>> queues;

};
class Process {
public:
    int pid;
    int priority;
    std::string name;

    Process(int p, int pr, std::string n) : pid(p), priority(pr), name(n) {}
};

#endif // MLQ_SCHEDULER_H
