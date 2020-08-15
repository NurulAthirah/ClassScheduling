// Note: Ni semata2 untuk senang compare I guess. 
// Coding FCFS, SJF and Priority Scheduling I think kena separate so ada file lain untuk yang tu

#include<bits/stdc++.h>
using namespace std;
 
struct Process
{
   int ccode;    		 // course code
   int duration;     	 // class duration
   int priority;  		 // priority
   int arrival_time;     // prefered arrival time
};

// sort the processes based on priority
bool sortProcesses(Process a, Process b) 
{ 

    return (a.priority > b.priority); 
} 
// function to find the waiting time for all processes
void findWaitingTime(Process proc[], int n, int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;
 
    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        wt[i] = proc[i-1].duration + wt[i-1] ;
    }
}
 
// function to calculate turn around time
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
    {
        tat[i] = proc[i].duration + wt[i];
    }
}
 
// function to calculate average time
void findAverageTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    // function to find waiting time of all processes
    findWaitingTime(proc, n, wt);
 
    // function to find turn around time for all processes
    findTurnAroundTime(proc, n, wt, tat);
 
    // display processes along with all details
    cout << "\nProcesses "<< " Burst time "
         << " Waiting time " << " Turn around time\n";
 
    // calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].ccode << "\t\t"
             << proc[i].duration << "\t " << wt[i]
             << "\t\t " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

void priorityScheduling(Process proc[], int n) 
{ 
    // Sort processes by priority 
    sort(proc, proc + n, sortProcesses); 
  	cout<< endl << endl;
  	cout<< "Priority Scheduling: ";
  	cout<< endl << endl;
    cout<< "Order in which processes gets executed \n"; 
    for (int  i = 0 ; i <  n; i++) 
        cout << proc[i].ccode <<" " ; 
  
    findAverageTime(proc, n); 
} 
 
bool comparison(Process a, Process b)
{
    return (a.duration < b.duration);
}
void findWaitingTimeSJF(Process proc[], int n, int wt[]) {
   int rt[n];
   for (int i = 0; i < n; i++)
   rt[i] = proc[i].duration;
   int complete = 0, t = 0, minm = INT_MAX;
   int shortest = 0, finish_time;
   bool check = false;
   while (complete != n) {
      for (int j = 0; j < n; j++) {
         if ((proc[j].arrival_time <= t) && (rt[j] < minm) && rt[j] > 0) {
            minm = rt[j];
            shortest = j;
            check = true;
         }
      }
      if (check == false) {
         t++;
         continue;
      }
      // decrementing the remaining time
      rt[shortest]--;
      minm = rt[shortest];
      if (minm == 0)
         minm = INT_MAX;
         // If a process gets completely
         // executed
         if (rt[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;
            // Calculate waiting time
            wt[shortest] = finish_time -
            proc[shortest].duration -
            proc[shortest].arrival_time;
            if (wt[shortest] < 0)
               wt[shortest] = 0;
         }
         // Increment time
         t++;
   }
}
void findavgTimeSJF(Process proc[], int n) {
   int wt[n], tat[n], total_wt = 0,
   total_tat = 0;
   // Function to find waiting time of all
   // processes
   findWaitingTimeSJF(proc, n, wt);
   // Function to find turn around time for
   // all processes
   findTurnAroundTime(proc, n, wt, tat);
   cout << "Processes " << " Burst time " << " Waiting time " << " Turn around time\n";
   for (int i = 0; i < n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      cout << " " << proc[i].ccode << "\t\t" << proc[i].duration << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;
   }
   cout << "\nAverage waiting time = " << (float)total_wt / (float)n; cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}
  

int main()
{
	// courses CSC2201 with priority 2 for 3 hours with prefered to start first, 
	// CSC3401 with priority 3 for 2 hours prefered to start second, 
	// and CSC1103 with priority 1 for 1 hour 
	
	Process proc[] = {{2201,3,2,1}, {3401, 2, 3,2}, {1103, 1,1,3}};
    int n = sizeof proc / sizeof proc[0];
    
    
  	cout << "First Come First Serve: ";
	cout << endl << endl;
    cout << "Order in which process gets executed";    
     findAverageTime(proc, n);
 
    // SJF
  
	cout << endl << endl;
 	cout << "Shortest Job First: ";
	cout << endl << endl;
    cout << "Order in which process gets executed\n";
    for (int i = 0 ; i < n; i++)
    {
        cout << proc[i].ccode <<" ";
    }
    
    cout << endl;
 	  findavgTimeSJF(proc, n);
    
    //Priority scheduling for now tak take into account arrival time lagi, will be fixed 
    
    priorityScheduling(proc, n); 
    
    
    
    
    return 0;
}
