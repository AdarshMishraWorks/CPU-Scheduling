#include "FBScheduler.h"

void FBScheduler::WRR_Scheduling() {
    std::cout << "Weighted Round Robin Scheduling\n";
}

void FBScheduler::EDF_Scheduling() {
    std::cout << "EDF Scheduling\n";
}

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

void FBScheduler::MLQ_Scheduling() {
    std::cout << "Multilevel Feedback Queue Scheduling\n";
}


// Method to add a foreground process
void FBScheduler::addForegroundProcess(int burstTime) {
    if (fgCount < MAX_PROCESSES) {
        foregroundProcesses[fgCount] = fgCount;  // Process ID
        foregroundBurstTimes[fgCount] = burstTime;
        fgCount++;
    } else {
        std::cout << "Foreground process queue is full.\n";
    }
}

// Method to add a background process
void FBScheduler::addBackgroundProcess(int burstTime) {
    if (bgCount < MAX_PROCESSES) {
        backgroundProcesses[bgCount] = bgCount;  // Process ID
        backgroundBurstTimes[bgCount] = burstTime;
        bgCount++;
    } else {
        std::cout << "Background process queue is full.\n";
    }
}

// Method to execute the processes
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

