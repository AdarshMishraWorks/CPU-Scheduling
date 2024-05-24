#include "FBScheduler.h"

void FBScheduler::WRR_Scheduling() {
    std::cout << "Weighted Round Robin Scheduling\n";
}

void FBScheduler::EDF_Scheduling() {
    std::cout << "EDF Scheduling\n";
}

void FBScheduler::F_B_Scheduling() {
    std::cout << "Foreground-Background Scheduling\n";

    int fgCount, bgCount;
    std::cout << "Enter the number of foreground processes: ";
    std::cin >> fgCount;

    int fgBurstTimes[MAX_PROCESSES]; 

    for (int i = 0; i < fgCount; ++i) {
        int burstTime;
        std::cout << "Enter burst time for foreground process " << i + 1 << ": ";
        std::cin >> burstTime;
        addForegroundProcess(burstTime, fgBurstTimes, i);
    }

    std::cout << "Enter the number of background processes: ";
    std::cin >> bgCount;

    int bgBurstTimes[MAX_PROCESSES]; 

    for (int i = 0; i < bgCount; ++i) {
        int burstTime;
        std::cout << "Enter burst time for background process " << i + 1 << ": ";
        std::cin >> burstTime;
        addBackgroundProcess(burstTime, bgBurstTimes, i);
    }

    executeProcesses(fgBurstTimes, bgBurstTimes, fgCount, bgCount);
}

void FBScheduler::MLQScheduler() {
    std::cout << "Multilevel Feedback Queue Scheduling\n";
}


void FBScheduler::addForegroundProcess(int burstTime, int fgBurstTimes[], int index) {
    if (fgCount < MAX_PROCESSES) {
        foregroundProcesses[fgCount] = fgCount;  
        fgBurstTimes[index] = burstTime;
        fgCount++;
    } else {
        std::cout << "Foreground process queue is full.\n";
    }
}


void FBScheduler::addBackgroundProcess(int burstTime, int bgBurstTimes[], int index) {
    if (bgCount < MAX_PROCESSES) {
        backgroundProcesses[bgCount] = bgCount;  
        bgBurstTimes[index] = burstTime;
        bgCount++;
    } else {
        std::cout << "Background process queue is full.\n";
    }
}


void FBScheduler::executeProcesses(int fgBurstTimes[], int bgBurstTimes[], int fgCount, int bgCount) {
    std::cout << "Executing Foreground Processes:\n";
    for (int i = 0; i < fgCount; ++i) {
        std::cout << "Process ID: " << foregroundProcesses[i] 
                  << ", Burst Time: " << fgBurstTimes[i] << " units\n";
    }

    std::cout << "\nExecuting Background Processes:\n";
    for (int i = 0; i < bgCount; ++i) {
        std::cout << "Process ID: " << backgroundProcesses[i] 
                  << ", Burst Time: " << bgBurstTimes[i] << " units\n";
    }
}
