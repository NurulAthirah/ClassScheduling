#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

struct Process{
    int ccode;
    int duration;
    int arrival_time;
}proc[50];

void insert(int n){

proc[0].ccode = 2201;
proc[0].duration = 3;
proc[0].arrival_time = 1;

proc[1].ccode = 3401;
proc[1].duration = 2;
proc[1].arrival_time = 2;

proc[2].ccode = 1103;
proc[2].duration = 1;
proc[2].arrival_time = 3;

}

bool durationSort(Process a,Process b){
    return a.duration < b.duration; 
}

bool arrival_timeSort(Process a,Process b){
    return a.arrival_time < b.arrival_time; 
}




void disp(int n){
    sort(proc,proc+n,durationSort);
    sort(proc,proc+n,arrival_timeSort);
    int ttime=1,i;
    int j,tArray[n]; //
    
    
    for(i=0;i<n;i++){
        j=i;
        while(proc[j].arrival_time<=ttime&&j!=n){
            j++;
        }
        sort(proc+i,proc+j,durationSort);
        tArray[i]=ttime;
        ttime+=proc[i].duration;
    }
    tArray[i] = ttime;

    float averageWaitingTime=0;
    float averageResponseTime=0;
    float averageTAT=0;
    cout << "Shortest Job Scheduling (SJF)" << endl << endl;
    cout << "Order of execution: " << endl;
    for (i=0; i<n; i++){
    	cout << proc[i].ccode << " ";
    }
    cout<<"\n\n";
    cout<<"Processes  Arrival Time\t Burst Time \t Turn Around \t Waiting Time\n";
 
    for (i=0; i<n; i++){
        cout << proc[i].ccode << "\t\t"; //Process
        cout << proc[i].arrival_time << "\t\t"; //Arrival
        cout << proc[i].duration << "\t\t"; //Burst
        
        
      
        cout << tArray[i]-proc[i].arrival_time+proc[i].duration << "\t\t";  //Turnaround
        cout << tArray[i]	-	proc[i].arrival_time << "\t\t"; 			// Waiting
        
        
        
        averageTAT	+=	tArray[i]	-	proc[i].arrival_time	+	proc[i].duration; 
        averageWaitingTime	+=	tArray[i]	-	proc[i].arrival_time; 
        averageResponseTime	+=	tArray[i]	-	proc[i].arrival_time;
        cout <<"\n"; 
    }
    cout<<"\n";

    cout<<"\n";
    cout<<"Average Response time: "<<(float)averageResponseTime/(float)n<<endl;
    cout<<"Average Waiting time: "<<(float)averageWaitingTime/(float)n<<endl;
    cout<<"Average TA time: "<<(float)averageTAT/(float)n<<endl;
}

int main(){
    int nop=3,choice,i;
    
    insert(nop);
    disp(nop);
    return 0;
}
