# CPU-Scheduling

Weighted Round Robin (WRR) Scheduling: Similar to RR, but each process is assigned a weight. Processes with higher weights get more CPU time compared to those with lower weights.

Earliest Deadline First (EDF) Scheduling: In EDF scheduling, each process is associated with a deadline. The scheduler selects the process with the earliest deadline for execution. If multiple processes have the same deadline, the one with the shortest remaining time is chosen.

Foreground-Background Scheduling: This scheme divides processes into two categories: foreground and background. Foreground processes are given priority and are scheduled preemptively, while background processes are scheduled only when no foreground processes are ready to run.

Multi-Level Feedback Queue Scheduling (MLFQ): This is an extension of multi-level queue scheduling where processes can move between queues based on their behavior. If a process uses too much CPU time, it may be moved to a lower-priority queue. Conversely, if it uses little CPU time, it may be moved to a higher-priority queue.
