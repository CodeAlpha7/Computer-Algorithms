#include <bits/stdc++.h>
using namespace std;

int disk_size = 200;
void CSCAN(int arr[], int head,int size)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;
    left.push_back(0);
    right.push_back(disk_size - 1);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < head)
        {
            left.push_back(arr[i]);
        }
        if (arr[i] > head)
        {
            right.push_back(arr[i]);
        }
    }
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    for (int i = 0; i < right.size(); i++)
    {
        cur_track = right[i];
        seek_sequence.push_back(cur_track);
        distance = abs(cur_track - head);
        seek_count += distance;

        head = cur_track;
    }
    head = 0;
    seek_count += (disk_size - 1);
    for (int i = 0; i < left.size(); i++)
    {
        cur_track = left[i];
        seek_sequence.push_back(cur_track);
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
    cout <<endl<< "Total number of seek operations = " << seek_count << endl;
    cout << "Seek Sequence is" << endl;
    int k;
    for (k = 0; k < seek_sequence.size() - 1; k++)
    {
        cout << seek_sequence[k] <<" -> ";
    }
    cout<< seek_sequence[k]<<endl;
}
int main()
{   int size;
    cout<<endl<<"Enter the size: ";
    cin>>size;
    int *arr = new int[size];

    cout<<"Enter values: ";
    for(int i=0; i<size; i++){
        cin>>arr[i]; 
    }
    // Fixed size Test case
    // int arr[8] = {185, 67, 42, 55, 78, 15, 39, 103};
    int head;
    cout << "Enter the initial position of head: ";
    cin>>head;
    CSCAN(arr, head,size);
    return 0;
}