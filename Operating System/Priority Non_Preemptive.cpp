#include<iostream>
using namespace std;

int total_wt = 0, total_tat = 0;

void WaitTime(int pro[][5], int n)
{
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < 5 - i - 1; ++j)
            if(pro[j][1] > pro[j + 1][1])
                for(int k = 0; k < n; ++k)
                    swap(pro[j][k], pro[j + 1][k]);
    pro[0][3] = 0;
    for(int i = 1; i < n; ++i)
        pro[i][3] = pro[i - 1][3] + pro[i - 1][2];
}

void TurnAround(int pro[][5], int n)
{
    for(int i = 0; i < n; ++i)
        pro[i][4] = pro[i][2] + pro[i][3];
}

void AvgTime(int pro[][5], int n)
{
    for(int i = 0; i < n; ++i)
        total_wt += pro[i][3];
        
    for(int i = 0; i < n; ++i)
        total_tat += pro[i][4];
}
void Display(int pro[][5], int n)
{
    cout << "\nGantt chart\n";
    for(int i = 0; i < n; ++i)
        cout << "|   P" << pro[i][0] << "   ";
    cout << "|\n";
    cout<<"0\t";
    for(int i = 0; i < n; ++i)
        cout << pro[i][4] << "\t";
    cout << "\nProcess ID\t\tPriority\t\tBurst Time\t\tWait Time\t\tTurn Around Time\n";
    for(int i = 0; i < n; ++i)
        cout << pro[i][0] << "\t\t\t" << pro[i][1] << "\t\t\t" << pro[i][2] << "\t\t\t" << pro[i][3] << "\t\t\t" <<pro[i][4] << "\n";
    cout << "Average Waiting time = " << float(total_wt) / float(n) << "ms\n";
    cout << "Average Turn Around time = " << float(total_tat) / float(n) << "ms";
}
int main()
{
    int n;
    cout << "Enter the number of processes:\n";
    cin >> n;
    int pro[n][5];
    cout << "\nEnter the process id, priority and burst time:\n";
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 3; ++j)
            cin >> pro[i][j];
        
    }
    WaitTime(pro, 4);
    TurnAround(pro, 4);
    AvgTime(pro, 4);
    Display(pro, 4);
    return 0;
}
