#include<iostream>
using namespace std;

int* strassen(int **A, int **B, int m, int n)
{
  int P1 = A[0][0]*(B[0][1]-B[1][1]);
  int P2 = (A[0][0]+A[0][1])*B[1][1];
  int P3 = (A[1][0]+A[1][1])*B[0][0];
  int P4 = A[1][1]*(B[1][0]-B[0][0]);
  int P5 = (A[0][0]+A[1][1])*(B[0][0]+B[1][1]);
  int P6 = (A[0][1]-A[1][1])*(B[1][0]+B[1][1]);
  int P7 = (A[0][0]-A[1][0])*(B[0][0]+B[0][1]);

  int r = P5 + P4 - P2 + P6;
  int s = P1 + P2;
  int t = P3 + P4;
  int u = P5 + P1 - P3 - P7;

  int** X = new int* [m];
  for(int i=0; i<m; ++i)
    X[i] = new int[n];
  X[0][0]=r;
  X[0][1]=s;
  X[1][0]=t;
  X[1][1]=u;

  return *X;
}
int main()
{
  int m,n;
  cout<<"Enter size of square matrices as m n:"<<endl<<" (order must be a power of 2. Ex: 2x2, 4x4, 8x8 etc ) "<<endl;
  cin>>m>>n;
  if(m!=n)
  {
    cout<<"Not a square matrix"<<endl;
    cout<<"Program terminated";
    return 0;
  }
  if(m%2!=0 || n%2!=0)
  {
    cout<<"Must be order of the power of 2"<<endl;
    cout<<"Strassen's method not applicable!"<<endl;
    cout<<"Program terminated";
    return 0;
  }
  int** A = new int* [m];
  for(int i=0; i<m; ++i)
    A[i] = new int[n];
  
  int** B = new int* [m];
  for(int i=0; i<m; ++i)
    B[i] = new int[n];
  
  cout<<"Enter matrix 1: ";
  for(int i=0; i<m; i++)
  {
    for(int j=0; j<n; j++)
    {
      cin>>A[i][j];
    }
  }
  cout<<endl<<"Enter matrix 2: ";
  for(int i=0; i<m; i++)
  {
    for(int j=0; j<n; j++)
    {
      cin>>B[i][j];
    }
  }

  if(m==2 && n==2)
  {
    int** output = new int* [m];
    for(int i=0;i<m;++i)
      output[i] = new int[n];

    *output = strassen(A,B,m,n);
    cout<<"The resultant matrix after multiplication is:"<<endl;
    for(int i=0; i<2; i++)
    {
      for(int j=0; j<2; j++)
      {
        cout<<output[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  if(m==4 && n==4)
  {

  }
  return 0;
}
