#include "FBScheduler.h"

void FBScheduler::WRR_Scheduling() {
    std::cout << "Weighted Round Robin Scheduling\n";
}

void FBScheduler::EDF_Scheduling() {
    std::cout << "EDF Scheduling\n";
}

void FBScheduler::F_B_Scheduling() {
    std::cout << "Feedback Scheduling\n";
}

void FBScheduler::MLQ_Scheduling() {
    std::cout << "Multilevel Feedback Queue Scheduling\n";
}
// Implementation of the F_B_Scheduling method
void FBScheduler::F_B_Scheduling() {
    std::cout << "Foreground-Background Scheduling\n";
    
    // Adding some sample processes
    addForegroundProcess(5);
    addForegroundProcess(3);
    addBackgroundProcess(8);
    addBackgroundProcess(6);
    addForegroundProcess(2);
    
    executeProcesses();
}

void FBScheduler::addForegroundProcess(int burstTime) {
    if (fgCount < MAX_PROCESSES) {
        foregroundProcesses[fgCount] = fgCount;  // Process ID
        foregroundBurstTimes[fgCount] = burstTime;
        fgCount++;
    } else {
        std::cout << "Foreground process queue is full.\n";
    }
}

void FBScheduler::addBackgroundProcess(int burstTime) {
    if (bgCount < MAX_PROCESSES) {
        backgroundProcesses[bgCount] = bgCount;  // Process ID
        backgroundBurstTimes[bgCount] = burstTime;
        bgCount++;
    } else {
        std::cout << "Background process queue is full.\n";
    }
}

void FBScheduler::executeProcesses() {
    std::cout << "Executing Foreground Processes:\n";
    for (int i = 0; i < fgCount; ++i) {
        std::cout << "Process ID: " << foregroundProcesses[i] 
                  << ", Burst Time: " << foregroundBurstTimes[i] << " units\n";
    }

    std::cout << "\nExecuting Background Processes:\n";
    for (int i = 0; i < bgCount; ++i) {
        std::cout << "Process ID: " << backgroundProcesses[i] 
                  << ", Burst Time: " << backgroundBurstTimes[i] << " units\n";
    }
}