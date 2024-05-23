#include "EDFScheduler.h"

void EDFScheduler::WRR_Scheduling() {
    std::cout << "Weighted Round Robin Scheduling\n";
}

void EDFScheduler::EDF_Scheduling() {

    int id, period, processingTime;
        std::cout << "Enter details for Process 1:\n";
        std::cout << "ID: ";
        std::cin >> id;
        std::cout << "Period: ";
        std::cin >> period;
        std::cout << "Processing Time: ";
        std::cin >> processingTime;
        Process p1(id, period, processingTime);

        std::cout << "Enter details for Process 2:\n";
        std::cout << "ID: ";
        std::cin >> id;
        std::cout << "Period: ";
        std::cin >> period;
        std::cout << "Processing Time: ";
        std::cin >> processingTime;
        Process p2(id, period, processingTime);
        int currentTime = 0;

        while (currentTime < 150) {
            // Determine which process should run next based on deadlines
            if (p1.deadline <= currentTime && p1.remainingTime > 0) {
                executeProcess(&p1, currentTime);
            } else if (p2.deadline <= currentTime && p2.remainingTime > 0) {
                executeProcess(&p2, currentTime);
            } else {
                // No process is ready, wait until the next deadline
                int nextDeadline = std::min(p1.deadline, p2.deadline);
                std::cout << "Waiting until next deadline: " << nextDeadline << std::endl;
                currentTime = nextDeadline;
            }

            // Update deadlines and reset remaining time if necessary
            updateCriticalPoint(&p1, currentTime);
            updateCriticalPoint(&p2, currentTime);
        }
}

void EDFScheduler::F_B_Scheduling() {
    std::cout << "Feedback Scheduling\n";
}

void EDFScheduler::MLQScheduler() {
    std::cout << "Multilevel Feedback Queue Scheduling\n";
}

