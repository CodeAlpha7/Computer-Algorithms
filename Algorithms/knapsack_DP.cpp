#include <bits/stdc++.h>
using namespace std;


int max(int x, int y)
{
	if (x>y)
        return x;
    else
        return y;
}


int knapSack(int W, int weights[], int profit[], int n)
{
	int i, w;
	int dp[n + 1][W + 1];

	
	for(i = 0; i <= n; i++)
	{
		for(w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				dp[i][w] = 0;
			else if (weights[i - 1] <= w)
				dp[i][w] = max(profit[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
			else
				dp[i][w] = dp[i - 1][w];
		}
	}
	return dp[n][W];
}

int main()
{
    cout<<"-----0/1 Knapsack using DP-----"<<endl<<endl;
    int p1, p2, p3, p4, p5;
    cout<<"Enter profit values: ";
    cin>>p1>>p2>>p3>>p4>>p5;
    int profit[] = { p1, p2, p3, p4, p5 };

	int w1, w2, w3, w4, w5;
    cout<<"Enter weights for corresponding profits: ";
    cin>>w1>>w2>>w3>>w4>>w5;
    int weights[] = { w1, w2, w3, w4, w5 };

	int W = 50;
	int n = sizeof(profit) / sizeof(profit[0]);
	
	cout <<endl<<"Maximum Profit = " << knapSack(W, weights, profit, n);
	
	return 0;
}

