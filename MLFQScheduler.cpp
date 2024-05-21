#include "MLFQScheduler.h"
#include <iostream>
#include <algorithm>

Process::Process(int id, int burstTime, bool ioBound)
    : id(id), burstTime(burstTime), remainingTime(burstTime), ioBound(ioBound) {}

MLFQScheduler::MLFQScheduler(std::vector<int> timeQuanta) {
    this->timeQuanta = timeQuanta;
    queues.resize(timeQuanta.size());
    processCounter = 0;
}

void MLFQScheduler::addProcesses(std::vector<std::vector<int>>& processes) {
    for (const auto& p : processes) {
        int burstTime = p[0];
        bool ioBound = p[1];
        Process process(processCounter++, burstTime, ioBound);
        int priority = ioBound ? 2 : 0; 
        queues[priority].push(process);
        std::cout << "Added process " << process.id << " with burst time " << burstTime << " to queue " << priority << "." << std::endl;
    }
}

void MLFQScheduler::run() {
    std::cout << "\nRunning scheduler...\n" << std::endl;
    while (!allQueuesEmpty()) {
        bool processRun = false;
        for (int i = 0; i < queues.size(); ++i) {
            if (!queues[i].empty()) {
                Process p = queues[i].front();
                queues[i].pop();

                int timeToRun = std::min(p.remainingTime, timeQuanta[i]);
                p.remainingTime -= timeToRun;

                std::cout << "Running process " << p.id
                    << " from queue " << i
                    << " for " << timeToRun << " units." << std::endl;

                if (p.remainingTime > 0) {
                    if (i < queues.size() - 1) {
                        queues[i + 1].push(p);
                        std::cout << "Process " << p.id << " moved to queue " << (i + 1) << "." << std::endl;
                    }
                    else {
                        queues[i].push(p);
                    }
                }
                else {
                    std::cout << "Process " << p.id << " finished." << std::endl;
                }

                processRun = true;
                break;
            }
        }
        if (!processRun) break;  
    }
}

void MLFQScheduler::displayQueues() {
    std::cout << "\nCurrent state of the queues:\n" << std::endl;
    for (int i = 0; i < queues.size(); ++i) {
        std::cout << "Queue " << i << ": ";
        std::queue<Process> q = queues[i];
        if (q.empty()) {
            std::cout << "Empty";
        }
        else {
            while (!q.empty()) {
                Process p = q.front();
                q.pop();
                std::cout << "Process " << p.id << " (burst time: " << p.burstTime << ", remaining time: " << p.remainingTime << ", I/O bound: " << (p.ioBound ? "Yes" : "No") << ") ";
            }
        }
        std::cout << std::endl;
    }
}

bool MLFQScheduler::allQueuesEmpty() {
    for (const auto& q : queues) {
        if (!q.empty()) return false;
    }
    return true;
}
