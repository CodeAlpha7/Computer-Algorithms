#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int main()
{
  string data;
  int n=0;
  cout<<"Enter number of strings to input: ";
  cin>>n;
  string repo[n];
  cout<<endl<<"Enter data: ";
  for(int j=0; j<n;j++)
  {
    cin>>data;
    repo[j]=data;
  }
  cout<<endl<<"Transmitted data: ";
  for(int j=0; j<n; j++)
  {
    int count=0;
    data=repo[j];                                 //for each string, one at a time
    for(int i=0; i<data.size(); i++)
    {
      if(data[i]=='1')
      ++count;
    }
    if(count%2 != 0)                            //if odd number of 1s, parity bit is 1 to generate even parity
    data = '1'+data;
    else
    data = '0'+data;
    cout<<data<<" ";
  }
  return 0;
}
