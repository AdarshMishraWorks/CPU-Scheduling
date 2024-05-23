#include "MLQScheduler.h"
#include <sstream>
#include <algorithm>

int Process::nextPID = 1;

Process::Process(int a, int b, int pr)
    : pid(nextPID++), arrivalTime(a), burstTime(b), priority(pr),
      startTime(-1), finishTime(-1), remainingTime(b), waitTime(0),
      responseTime(-1), started(false) {}

class MLQSchedulerImpl : public MLQScheduler {
private:
    std::vector<std::queue<Process>> queues;
    int numQueues;
    const int timeQuantum = 2;

public:
    MLQSchedulerImpl(int n) : numQueues(n) {
        if (n <= 0) {
            throw std::invalid_argument("Number of queues must be greater than zero.");
        }
        queues.resize(numQueues);
    }

    void addProcess(int arrivalTime, int burstTime, int priority) override {
        if (priority < 0 || priority >= numQueues) {
            throw std::out_of_range("Invalid priority level.");
        }
        if (arrivalTime < 0 || burstTime <= 0) {
            throw std::invalid_argument("Invalid arrival time or burst time.");
        }
        queues[priority].emplace(arrivalTime, burstTime, priority);
    }

    void schedule() override {
        std::cout << "Scheduling processes...\n";
        bool done = false;
        int currentTime = 0;
        int totalProcesses = 0;

        for (const auto& queue : queues) {
            totalProcesses += queue.size();
        }

        while (!done) {
            done = true;
            for (int i = 0; i < numQueues; ++i) {
                if (!queues[i].empty()) {
                    done = false;
                    Process p = queues[i].front();
                    queues[i].pop();

                    if (!p.started) {
                        p.startTime = currentTime;
                        p.responseTime = currentTime - p.arrivalTime;
                        p.started = true;
                    }

                    int timeSlice = (i == 0) ? p.remainingTime : std::min(timeQuantum, p.remainingTime);

                    currentTime += timeSlice;
                    p.remainingTime -= timeSlice;

                    for (int j = 0; j < numQueues; ++j) {
                        std::queue<Process> tempQueue;
                        while (!queues[j].empty()) {
                            Process q = queues[j].front();
                            queues[j].pop();
                            if (q.pid != p.pid) {
                                q.waitTime += timeSlice;
                                tempQueue.push(q);
                            }
                        }
                        queues[j] = tempQueue;
                    }

                    if (p.remainingTime > 0) {
                        queues[i].push(p);
                    } else {
                        p.finishTime = currentTime;
                        std::cout << "Process PID: " << p.pid << " finished at time " << p.finishTime << "\n";
                        std::cout << "PID: " << p.pid << ", Wait Time: " << p.waitTime
                                  << ", Turnaround Time: " << p.finishTime - p.arrivalTime
                                  << ", Response Time: " << p.responseTime << "\n";
                    }
                }
            }
        }
    }

    void displayProcesses() override {
        std::cout << "Displaying processes:\n";
        for (int i = 0; i < numQueues; ++i) {
            std::cout << "Queue " << i << ":\n";
            std::queue<Process> tempQueue = queues[i];
            while (!tempQueue.empty()) {
                Process p = tempQueue.front();
                std::cout << "PID: " << p.pid << ", Arrival: " << p.arrivalTime
                          << ", Burst: " << p.burstTime << ", Priority: " << p.priority
                          << ", Remaining: " << p.remainingTime << ", Wait Time: " << p.waitTime
                          << ", Response Time: " << (p.responseTime == -1 ? 0 : p.responseTime) << "\n";
                tempQueue.pop();
            }
        }
    }
};

void executeScheduler() {
    int numQueues, choice;
    int arrivalTime, burstTime, priority;
    std::string input;

    try {
        std::cout << "Enter the number of priority levels: ";
        std::cin >> numQueues;
        if (std::cin.fail()) {
            throw std::invalid_argument("Invalid input for number of priority levels.");
        }

        MLQSchedulerImpl scheduler(numQueues);

        while (true) {
            std::cout << "\n1. Add Process\n2. Schedule\n3. Display Processes\n4. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input for menu choice.");
            }

            switch (choice) {
                case 1:
                    std::cout << "Enter Arrival Time, Burst Time, Priority (comma-separated): ";
                    std::cin.ignore();
                    std::getline(std::cin, input);
                    {
                        std::istringstream ss(input);
                        char comma;
                        if (!(ss >> arrivalTime >> comma >> burstTime >> comma >> priority) || comma != ',') {
                            throw std::invalid_argument("Invalid input for process details.");
                        }
                    }
                    scheduler.addProcess(arrivalTime, burstTime, priority);
                    break;
                case 2:
                    scheduler.schedule();
                    break;
                case 3:
                    scheduler.displayProcesses();
                    break;
                case 4:
                    std::cout << "Exiting...\n";
                    return;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}
