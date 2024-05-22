#include "MLQScheduler.h"

void MLQScheduler::WRR_Scheduling() {
    std::cout << "Weighted Round Robin Scheduling\n";
}

void MLQScheduler::EDF_Scheduling() {
    std::cout << "EDF Scheduling\n";
}

void MLQScheduler::F_B_Scheduling() {
    std::cout << "Feedback Scheduling\n";
}

void MLQScheduler::MLQ_Scheduling() {
    std::cout << "Multilevel Feedback Queue Scheduling\n";
        
        for (int i = 0; i < queues.size(); ++i) {
            std::cout << "Queue " << i << ":\n";
            while (!queues[i].empty()) {
                Process p = queues[i].front();
                queues[i].pop();
                std::cout << "Processing " << p.name << " (PID: " << p.pid << ", Priority: " << p.priority << ")\n";
                
                // Simulate processing time, demote priority if needed
                // For simplicity, we won't demote priority in this example
            }
        }
}
