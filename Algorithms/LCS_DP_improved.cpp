#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int lcsDP(string p, string q, int m, int n){
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }

    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){

            if(p[i-1]==q[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string sequence1, sequence2;
    cout<<"Enter 1st sequence: ";
    getline(cin, sequence1);
    cout<<"Enter 2nd sequence: ";
    getline(cin, sequence2);

    int size1 = sequence1.length();
    int size2 = sequence2.length();
    int result = lcsDP(sequence1, sequence2, size1, size2);

    cout<<"LCS length = "<<result;
}