#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int main()
{
  int n=0;
  cout <<"Enter number of strings to input: ";
  cin >>n;
  string data[n];                                   //string of arrays = matrix
  cout <<"Enter data:";
  for(int i=0;i<n;i++)
  cin >>data[i];
  string output;
  for(int i=0;i<data[0].size();i++)
  {
    int count = 0;
    for(int j=0;j<n;j++)
    {
      if(data[j][i] == '1')                           //2D matrix
      count++;
    }
    if(count & 1)
    output = output + "1";
    else
    output = output + "0";
  }
  cout <<"The transmitted data is:"<<" "<<output <<" ";
  for(int i=0;i<n;i++)
  cout <<data[i] <<" ";
  cout <<endl;
  return 0;
}
