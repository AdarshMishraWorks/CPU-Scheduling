// Scheduler.cpp
#include <iostream>

// Base class
class SchedulingAlgorithm {
public:
    virtual void WRR_Scheduling() = 0;
    virtual void EDF_Scheduling() = 0;
    virtual void F_B_Scheduling() = 0;
    virtual void MLFQ_Scheduling() = 0;
};

// Weighted Round Robin Scheduler
class WRRScheduler : public SchedulingAlgorithm {
public:
    void WRR_Scheduling() override {
        std::cout << "Weighted Round Robin Scheduling\n";
    }
    void EDF_Scheduling() override {
        std::cout << "EDF Scheduling\n";
    }
    void F_B_Scheduling() override {
        std::cout << "Feedback Scheduling\n";
    }
    void MLFQ_Scheduling() override {
        std::cout << "Multilevel Feedback Queue Scheduling\n";
    }
};

// Earliest Deadline First Scheduler
class EDFScheduler : public SchedulingAlgorithm {
public:
    void WRR_Scheduling() override {
        std::cout << "Weighted Round Robin Scheduling\n";
    }
    void EDF_Scheduling() override {
        std::cout << "EDF Scheduling\n";
    }
    void F_B_Scheduling() override {
        std::cout << "Feedback Scheduling\n";
    }
    void MLFQ_Scheduling() override {
        std::cout << "Multilevel Feedback Queue Scheduling\n";
    }
};

// Feedback Scheduler
class FBScheduler : public SchedulingAlgorithm {
public:
    void WRR_Scheduling() override {
        std::cout << "Weighted Round Robin Scheduling\n";
    }
    void EDF_Scheduling() override {
        std::cout << "EDF Scheduling\n";
    }
    void F_B_Scheduling() override {
        std::cout << "Feedback Scheduling\n";
    }
    void MLFQ_Scheduling() override {
        std::cout << "Multilevel Feedback Queue Scheduling\n";
    }
};

// Multilevel Feedback Queue Scheduler
class MLFQScheduler : public SchedulingAlgorithm {
public:
    void WRR_Scheduling() override {
        std::cout << "Weighted Round Robin Scheduling\n";
    }
    void EDF_Scheduling() override {
        std::cout << "EDF Scheduling\n";
    }
    void F_B_Scheduling() override {
        std::cout << "Feedback Scheduling\n";
    }
    void MLFQ_Scheduling() override {
        std::cout << "Multilevel Feedback Queue Scheduling\n";
    }
};

int main() {
    WRRScheduler wrr;
    EDFScheduler edf;
    FBScheduler fb;
    MLFQScheduler mlfq;

    SchedulingAlgorithm* scheduler = &wrr;

    // Polymorphism example
    scheduler->WRR_Scheduling();

    scheduler = &edf;
    scheduler->EDF_Scheduling();

    scheduler = &fb;
    scheduler->F_B_Scheduling();

    scheduler = &mlfq;
    scheduler->MLFQ_Scheduling();

    return 0;
}
