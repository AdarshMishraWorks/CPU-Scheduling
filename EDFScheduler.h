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
private:
    class Process {
    public:
        int id;
        int period;
        int processingTime;
        int deadline;
        int remainingTime;

        Process(int id, int period, int processingTime)
            : id(id), period(period), processingTime(processingTime),
              deadline(period), remainingTime(processingTime) {}

        void reset() {
            remainingTime = processingTime;
        }

        void updateDeadline() {
            deadline += period;
        }
    };

    // Execute process for a certain time period
    void executeProcess(Process* process, int &currentTime) {
        int executionTime = std::min(process->remainingTime, process->deadline - currentTime);
        std::cout << "Time " << currentTime << " - " << currentTime + executionTime
                  << ": Process " << process->id << " running\n";
        currentTime += executionTime;
        process->remainingTime -= executionTime;
    }

    // Update the deadline and reset remaining time if necessary
    void updateCriticalPoint(Process* process, int currentTime) {
        if (currentTime >= process->deadline) {
            process->reset();
            process->updateDeadline();
        }
    }

};

#endif // EDF_SCHEDULER_H
