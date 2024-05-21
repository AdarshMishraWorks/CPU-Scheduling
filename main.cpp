#include "WRRScheduler.h"
#include "EDFScheduler.h"
#include "FBScheduler.h"
#include "MLFQScheduler.h"
#include <iostream>

using namespace std;
void showMenu() {
    cout << "MLFQ Scheduler Menu:" << endl;
    cout << "1. Add processes" << endl;
    cout << "2. Run the scheduler" << endl;
    cout << "3. Display the current state of the queues" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int MLFQS() {
    vector<int> timeQuanta = { 4, 8, 16 };
    MLFQScheduler scheduler(timeQuanta);
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int numProcesses;
            cout << "Enter the number of processes: ";
            cin >> numProcesses;

            vector<vector<int>> processes(numProcesses, vector<int>(2));
            for (int i = 0; i < numProcesses; ++i) {
                cout << "Enter burst time for process " << i << ": ";
                cin >> processes[i][0];
                cout << "Is process " << i << " I/O bound? (1 for Yes, 0 for No): ";
                cin >> processes[i][1];
            }
            scheduler.addProcesses(processes);
            break;
        }

        case 2:
            scheduler.run();
            break;

        case 3:
            scheduler.displayQueues();
            break;

        case 4:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }


    } while (choice != 4);

    return 0;
}

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
                MLFQS();
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
