#include<iostream>
using namespace std;

int main()
{
  int n;
  cout<<"Enter number of processes: ";
  cin>>n;
  int process_name[n];
  int burst_time[n];
  cout<<"Enter process name and reqd CPU time: ";
  for(int i=0; i<n; i++)
  {
    cin>>process_name[i];
    cin>>burst_time[i];
  }
  int waiting_time[n];
  waiting_time[0]=0;
  for(int i=1; i<n; i++)
  {
    waiting_time[i]=burst_time[i-1]+waiting_time[i-1];
  }
  cout<<"Process name \t burst time \t waiting time"<<endl;
  for(int i=0; i<n; i++)
  {
    cout<<process_name[i]<<" \t\t "<<burst_time[i]<<" \t\t "<<waiting_time[i]<<endl;
  }

  int total_time=0;
  for(int i=0; i<n; i++)
  {
    total_time = total_time + waiting_time[i];
  }
  int average_wt = total_time/n;
  cout<<endl<<"Average waiting time is: "<<average_wt<<endl;

  cout<<endl<<"Gantt chart"<<endl;
  cout<<"|";
  for(int i=0; i<n; i++)
  {
    cout<<" P"<<process_name[i]<<" |";
  }

  int time=0;
  cout<<endl<<"0";
  for(int i=0; i<n;i++)
  {
    time = time+burst_time[i];
    cout<<"    "<<time;
  }
  


  return 0;
}
