#include<iostream>
#include<time.h>
using namespace std;
int main()
{
 clock_t start_time,endt_time;
 int array[10000];
 for(int i=0;i<10000;i++)
    array[i]=i+1;
 int input=0;
 int flag=1;
 cout<<"Enter Input:";
 cin>>input;
 cout<<endl;
 start_time=clock();
 for(int i=0;i<10000;i++)
 {
 if(input==array[i])
 {
 cout<<input<<" found at index "<<i;
 flag=0;
 break;
 }
 }
 if(flag)
 cout<<input<<" not found in the array";
 cout<<endl;
 endt_time=clock();
 cout<<endl<<"Time taken (in seconds):"<<((double) (endt_time - start_time)) / CLOCKS_PER_SEC<<endl;
 return 0;
}