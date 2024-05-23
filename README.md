# CPU-Scheduling

Weighted Round Robin (WRR) Scheduling: Similar to RR, but each process is assigned a weight. Processes with higher weights get more CPU time compared to those with lower weights.

Earliest Deadline First (EDF) Scheduling: In EDF scheduling, each process is associated with a deadline. The scheduler selects the process with the earliest deadline for execution. If multiple processes have the same deadline, the one with the shortest remaining time is chosen.

Foreground-Background Scheduling: This scheme divides processes into two categories: foreground and background. Foreground processes are given priority and are scheduled preemptively, while background processes are scheduled only when no foreground processes are ready to run.

Multilevel Queue Scheduling is a CPU scheduling technique where processes are divided into multiple queues based on their priority or other criteria. Each queue has its own scheduling algorithm, and processes are permanently assigned to one queue. This method allows the system to handle different types of processes more efficiently by applying different scheduling strategies to each queue.
