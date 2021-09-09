#include <iostream>

using namespace std;
 
int main(){
     int i,j,k,p,s=0, got=0, idle=0, temp_burst, temp_row, pre_process_row, done=0;
     float sum=0;
 
     cout<<"Please enter the number of process : ";
     cin>>p;
 
     int a[p][5];
     int b[p][5];
 
     cout<<"\nProcess\t\tArrival\t\tBurst\n";
     for(i=0;i<p;i++){
          for(j=0;j<3;j++){
               cin>>a[i][j];
               }
          a[i][3]=a[i][2]; 
          }
 
     cout<<"\n\nGantt Chart:\n";
 
     i=a[0][1];
     while(done!=p){
          got=0;
          k=0;
          while(k<p){
               if(a[k][1]<=i){
                    if(a[k][2]!=0){
                         got=1;          
                         temp_burst=a[k][2];
                         temp_row=k;
                         idle=0;
                         break;
                         }
                    else
                         k++;             
                    }
               else{
                    if(idle==0)
                         printf("%5d| Idle |",i);
                    idle=1;
                    break;
                    }
               }
          if(got!=0){
               k=0;
               while(a[k][1]<=i && k<p){
                    if(a[k][2]!=0){
                         if(temp_burst>a[k][2]){
                              temp_burst=a[k][2];
                              temp_row=k;
                              }
                         }
                    k++;
                    }
 
               a[temp_row][2]-=1;
                
               if(i==a[0][1])   
                    printf("%d| P%-d |",i,a[temp_row][0]);
               else{
                    if(pre_process_row!=temp_row)
                         printf("%d| P%-d |",i,a[temp_row][0]);                   
                    }
 
               pre_process_row=temp_row;
      
               if(a[temp_row][2]==0){
                    done++;
                    b[s][0]=a[temp_row][0];
                    b[s][1]=a[temp_row][1];
                    b[s][2]=i;
                    b[s][3]=a[temp_row][3];
                    b[s][4]=((i-a[temp_row][1])-a[temp_row][3])+1;        
                    sum+=((i-a[temp_row][1])-a[temp_row][3])+1;
                    s++;
                    }
               }
          i++;
          }
 
 
     printf("%d",i); 
 
     cout<<endl;
     cout<<"\n\nProcessID\t\tArrival time\t\tCompletion time\t\tWaiting time\n";
 
     for(i=0;i<s;i++)
          cout<<b[i][0]<<"\t\t\t"<<b[i][1]<<"\t\t\t"<<b[i][2]<<"\t\t\t"<<b[i][4]<<"\n";
 
     cout<<"\nAvg. Wait time = "<<sum/p<<endl;
     
 
     
     return 0;
     }