#include "WRRScheduler.h"

void WRRScheduler::WRR_Scheduling() {
    std::cout << "Weighted Round Robin Scheduling\n";

        int numProcesses;
        std::cout << "Enter the number of processes: ";
        std::cin >> numProcesses;

        Process processes[10]; 
        for (int i = 0; i < numProcesses; ++i) {
            processes[i].id = i + 1;
            std::cout << "Enter weight and burst time for process " << processes[i].id << ": ";
            std::cin >> processes[i].weight >> processes[i].burstTime;
            processes[i].remainingTime = processes[i].burstTime;
        }

        int quantum = 2;  

        bool done;
        do {
            done = true;

            for (int i = 0; i < numProcesses; ++i) {
                Process &p = processes[i];
                int weightedQuantum = quantum * p.weight;

                if (p.remainingTime > 0) {
                    done = false;  

                    if (p.remainingTime > weightedQuantum) {
                        std::cout << "Process " << p.id << " runs for " << weightedQuantum << " units\n";
                        p.remainingTime -= weightedQuantum;
                    } else {
                        std::cout << "Process " << p.id << " runs for " << p.remainingTime << " units (finishes)\n";
                        p.remainingTime = 0;
                    }
                }
            }
        } while (!done);
}

void WRRScheduler::EDF_Scheduling() {
    std::cout << "EDF Scheduling\n";
}

void WRRScheduler::F_B_Scheduling() {
    std::cout << "Feedback Scheduling\n";
}

void WRRScheduler::MLQScheduler() {
    std::cout << "Multilevel Feedback Queue Scheduling\n";
}
