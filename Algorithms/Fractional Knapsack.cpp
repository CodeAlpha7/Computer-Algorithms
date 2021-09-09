#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if ((a.first / a.second) > (b.first / b.second))
        return true;
    return false;
}

int main()
{
    cout << "----- FRACTIONAL KNAPSACK -----\n";
    vector<pair<int, int>> l;
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter values and weights of each item: "<<endl;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> temp;
        cout<<"Item "<<i+1<<": ";
        cin >> temp.first >> temp.second;
        l.push_back(temp);
    }
    float weight, profit = 0;
    cout << "Enter weight contraint: ";
    cin >> weight;
    sort(l.begin(), l.end(), compare);
    int sum = 0, j = 0;
    while (sum < weight && j < n)
    {
        sum += l[j].second;
        profit += l[j].first;
        j++;
    }
    j--;
    sum -= l[j].second;
    profit -= l[j].first;
    float left = weight - sum;
    float canTake = ((float)left / l[j].second) * l[j].first;
    profit += canTake;
    j++;
    cout << "\nMax profit: " << profit;
    return 0;
}