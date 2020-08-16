#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int pname;
    int btime;
    int atime;
}a[50];

void insert(int n){


a[0].pname = 2201;
a[0].btime = 3;
a[0].atime = 1;

a[1].pname = 3401;
a[1].btime = 2;
a[1].atime = 2;

a[2].pname = 1103;
a[2].btime = 1;
a[2].atime = 3;



}

bool btimeSort(node a,node b){
    return a.btime < b.btime; 
}

bool atimeSort(node a,node b){
    return a.atime < b.atime; 
}




void disp(int n){
    sort(a,a+n,btimeSort);
    sort(a,a+n,atimeSort);
    int ttime=1,i;
    int j,tArray[n]; //
    
    
    for(i=0;i<n;i++){
        j=i;
        while(a[j].atime<=ttime&&j!=n){
            j++;
        }
        sort(a+i,a+j,btimeSort);
        tArray[i]=ttime;
        ttime+=a[i].btime;
    }
    tArray[i] = ttime;

    float averageWaitingTime=0;
    float averageResponseTime=0;
    float averageTAT=0;
    cout<<"\n";
    cout<<"Processes  Arrival Time\t Burst Time \t Turn Around \t Waiting Time\n";
 
    for (i=0; i<n; i++){
        cout << a[i].pname << "\t\t"; //Process
        cout << a[i].atime << "\t\t"; //Arrival
        cout << a[i].btime << "\t\t"; //Burst
        
        
      
        cout << tArray[i]-a[i].atime+a[i].btime << "\t\t";  //Turnaround
        averageTAT+=tArray[i]-a[i].atime+a[i].btime; // Waiting
        cout << tArray[i]-a[i].atime << "\t\t"; 
        averageWaitingTime+=tArray[i]-a[i].atime; 
        averageResponseTime+=tArray[i]-a[i].atime;
        cout <<"\n"; 
    }
    cout<<"\n";
    cout<<"\nGantt Chart\n";
    for (i=0; i<n; i++){
        cout <<"|   "<< a[i].pname << "   "; 
    }
    cout<<"\n";
    for (i=0; i<n+1; i++){
        cout << tArray[i] << "\t"; 
    }
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
