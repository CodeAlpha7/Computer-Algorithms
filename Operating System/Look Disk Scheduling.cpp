#include <bits/stdc++.h>
using namespace std;

int disk_size = 200;
void LOOK(int arr[], int head, string direction,int size)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    int run = 2;
    while (run--)
    {
        if (direction == "left")
        {
            for (int i = left.size() - 1; i >= 0; i--)
            {
                cur_track = left[i];
                seek_sequence.push_back(cur_track);
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = "right";
        }
        else if (direction == "right")
        {
            for (int i = 0; i < right.size(); i++)
            {
                cur_track = right[i];
                seek_sequence.push_back(cur_track);
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = "left";
        }
    }
    cout <<endl<< "Total number of seek operations = " << seek_count << endl;

    cout << "Seek Sequence is" << endl;
    int k;
    for (k = 0; k < seek_sequence.size()-1; k++)
    {
        cout << seek_sequence[k] <<" ->";
    }
    cout<<seek_sequence[k];
}
int main()
{  int size;
    cout<<endl<<"Enter the size: ";
    cin>>size;
    int *arr = new int[size];

    cout<<"Enter values: ";
    for(int i=0; i<size; i++){
        cin>>arr[i]; 
    }
    int head;
    cout << "Enter the initial position of head: ";
    cin>>head;
    // Fixed size Test case
    // int arr[8] = {176, 79, 34, 60, 92, 11, 41, 114};
    string direction = "left";
    LOOK(arr, head, direction,size);
    return 0;
}