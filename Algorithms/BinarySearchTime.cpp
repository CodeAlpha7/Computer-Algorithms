#include<iostream>
#include<time.h>
using namespace std;
int binarysearch(int num[],int start,int end,int target)
{
 int mid=(start+end)/2;
 if(num[mid]==target)
 return 1;
 if(start>=end)
 return 0;
 if(num[mid]>target)
 return binarysearch(num,start,mid-1,target);
return binarysearch(num,mid+1,end,target);
}
int main()
{
 clock_t start_time,endt_time;
 int array[10000]; 
 for(int i=0;i<10000;i++)
 array[i]=i+1;
 int input=0;
 cout<<"Enter Input:";
 cin>>input;
 cout<<endl;
 start_time=clock();
 if(binarysearch(array,0,10000,input))
 cout<<input<<" found in the array";
 else
 cout<<input<<" not found in the array";
 endt_time=clock();
 cout<<endl<<"Time taken (in seconds):"<<((double) (endt_time - start_time)) /CLOCKS_PER_SEC<<endl;
 return 0;
}