#include "WRRScheduler.h"
#include "EDFScheduler.h"
#include "FBScheduler.h"
#include "MLQScheduler.h"
#include <iostream>

void displayMenu() {
    std::cout << "\nScheduler Menu:\n";
    std::cout << "1. Weighted Round Robin Scheduling\n";
    std::cout << "2. EDF Scheduling\n";
    std::cout << "3. Feedback Scheduling\n";
    std::cout << "4. Multilevel Feedback Queue Scheduling\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    WRRScheduler wrr;
    EDFScheduler edf;
    FBScheduler fb;
    MLFQScheduler mlq;

    SchedulingAlgorithm* scheduler = nullptr;

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                scheduler = &wrr;
                scheduler->WRR_Scheduling();
                break;
            case 2:
                scheduler = &edf;
                scheduler->EDF_Scheduling();
                break;
            case 3:
                scheduler = &fb;
                scheduler->F_B_Scheduling();
                break;
            case 4:
                scheduler = &mlq;
                scheduler->MLQ_Scheduling();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
