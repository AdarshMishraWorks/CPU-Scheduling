#include "WRRScheduler.h"
#include "EDFScheduler.h"
#include "FBScheduler.h"
#include "MLFQScheduler.h"

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
