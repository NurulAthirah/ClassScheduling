# GROUP MEMBER 
NURUL ATHIRAH BINTI MOHD BORHAN (1813606)


NOR AIMIE NADIA BINTI YUSRIN (1710006)


NUR LAILA HUSNA BINTI MUEIZAM (1727070)


NUR ALIFAH ILYANA BINTI ADNAN (1813160)


# Introduction
Task scheduling is needed to maintain every process that comes with a processor in parallel processing. Therefore, there are several methods used to perform queue process that comes to the processor. Some algorithms are popular among other First Come First Serve (FCFS), Shortest Job First (SJF), and Priority scheduling. In this project, the analysis involves the comparison of the average waiting time of each of these algorithms. The priority of the processes that occur on the processor is something that determines when the process will be done. Several techniques have been applied to maintain the process to make the CPU performance in normal. The objective of this paper is to compare three algorithms, FCFS, SJF, and Priority scheduling. The target is to know which algorithm is the best class scheduling solution that suitable for the certain process. To simplify, the purpose of this comparison is to determine what type of scheduling algorithm is the best for some processes that are in the ready queue.

# Consideration
There are various types of scheduling algorithms which are First Come First Serve (FCFS), Shortest Job First (SJF), Priority Scheduling, Round Robin Scheduling, and Shortest Remaining Time. For this project we decided to use non-preemptive algorithms which are  First Come First Serve (FCFS), Shortest Job First (SJF), and Priority Scheduling.Using FCFS, SJF and priority scheduling, we applied the processes with the same data to evaluate the average time taken and average turn around time. The data are arrival time, burst time and priority.We consider the SJF algorithm will give the shortest average for turn around time.  

# Analysis 

## FCFS
First Come First Serve (FCFS) Scheduling Algorithm is a non-preemptive schedule algorithm, which means the process cannot be pre-empted in between the processing once it starts executing in the processor. Therefore, this type of scheduling algorithm is not implemented the concept of priority and urgency. Besides, in the FCFS algorithm, the process gets executed in the same sequence in which they enter the ready state.  It doesn't include any complex logic, it just puts the process requests in a queue and executes it one by one. Thus, FCFS is quiet simple and easy to implement. Eventually, every process will get a chance to run, hence no starvation will occur. The only disadvantage of FCFS is there is no option for pre-emption of a process. If a process is started, then CPU executes the process until it ends.
We implement this class timetable as an example to examine the three scheduling algorithms. Suppose there are 3 processes with process ID’s 2201, 3401 and 1103 and the processes will be entered into the CPU. Thus, if the OS follows the FCFS algorithm for scheduling these processes, then they will be executed in the following manner:

Process ID	Arrival Time	Burst Time	Waiting Time	Turn Around Time
2201	         1	             3	        0	               3
3401	         2	             2	        3	               5
1103	         3	             1	        5	               6
	
The Gantt chart below shows the time split which represents each process of the FCFS algorithm:
     2201	   2201	     2201	   3401	    3401	    1103
  0	       1	     2		    3		    4	        5	        6

The first-come-first-served scheduler show a simple way to calculate as each job starts as soon as the processor becomes free, and takes exactly its burst time to complete. In addition, after calculated the start and end times to calculate the wait times, thus use that formula to obtain the turnaround time. The calculation below shows the result of average turnaround time and waiting time when using the First Come First Serve scheduler:

Total Turnaround Time = 3 + 5 + 6 
            = 14 milliseconds
    Average Turn Around Time= Total Turn Around Time / Total No. of Processes
            = 14 / 3
            = 4.6667 milliseconds

    Total Waiting Time =0 + 3 + 5
            = 8 milliseconds
    Average Waiting Time = Total Waiting Time / Total No. of Processes
            = 8 / 3
            = 2.66667 milliseconds

The average turnaround time and waiting time will show a different result if using SJF and Priority scheduling process. For Shortest Job First, it similar with FCFS concept, but the process which comes at the same time or the same ready queue must be sorted in ascending order. The smallest burst time will be the first order while the bigger will be the last one. Last but not least, for Priority scheduling, each process is assigned a priority. Process with highest priority is to be executed first and so on. Processes with same priority are executed on first come first served basis

## SJF
For the shortest job first algorithm, this algorithm has the shortest execution time for the next execution. In non-preemptive SJF scheduling,the process holds it until it reaches a waiting state or terminates once the CPU cycle is allocated to the process. This algorithm gives the shortest average waiting time for a process better than FCFS and priority scheduling algorithms. Thus, the processes can be executed faster.

OUTPUT : 2201, 3401, 1103   
Average waiting time = 1.33333
Average turn around time = 3.33333

## Priority Schedulling
Priority Scheduling is a method of scheduling processes that is based on priority. In this algorithm, the scheduler selects the tasks to work as per the priority. The task with higher priority will be carried out while round-robin or FCFS-based jobs with similar priorities are done. Priority depends on the demands on memory and time. In Priority Preemptive Scheduling, the tasks are mostly assigned with their priorities. In Priority Non-preemptive scheduling method, the CPU has been allocated to a specific process. Processes are executed on the basis of priority so high priority does not need to wait for long which saves time. If high priority processes take lots of CPU time, then the lower priority processes may starve and will be postponed for an indefinite time.

OUTPUT : 

Order in which processes gets executed
2201 3401 1103

Processes  Arrival Time  Priority  Burst Time  Turn around  Waiting Time 
 2201           1           2          3           3             0
 3401           3           3          2           4             2
 1103           2           1          1           4             3
Average Response Time = 1.66667
Average waiting time = 1.66667
Average TA time = 1.66667

#Conclusion

Among the three calculation of these algorithms, we found that SJF has the shortest waiting time compared to FCFS and Priority Schedulling.
