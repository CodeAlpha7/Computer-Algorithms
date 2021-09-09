#include<bits/stdc++.h> 
using namespace std; 
int pageFaults(int pages[], int n, int capacity) { 
    unordered_set<int> s; 
    queue<int> indexes; 
    int page_faults = 0; 
    for (int i=0; i<n; i++) { 
        if (s.size() < capacity) { 
            if (s.find(pages[i])==s.end()) { 
                s.insert(pages[i]); 
                page_faults++; 
                indexes.push(pages[i]);         // use a queue, to keep track of inserted pages
            }                                   // when queue is emptied, first inserted page is removed. so, FIFO.
        } 
        else { 
            if (s.find(pages[i]) == s.end()) { 
                int val = indexes.front(); 
                indexes.pop(); 
                s.erase(val); 
                s.insert(pages[i]); 
                indexes.push(pages[i]); 
                page_faults++; 
            } 
        } 
    } 
    return page_faults; 
} 
int main() { 
    
    int n;
    cout<<"Enter number of pages: ";
    cin>>n;
    int pages[n];
    cout<<"Enter all "<<n<< " pages: ";

    for(int i=0; i<n; i++)
    {
        cin>>pages[i];
    }

    int capacity;
    cout<<"Enter frame size: ";
    cin>>capacity;

    //int pages[] = {6, 0, 2, 3, 0, 4, 0, 3, 1, 2, 1, 4, 3}; 
    //int n = sizeof(pages) / sizeof(pages[0]); 
    //int capacity = 4; 
    cout<<"Number of Page Faults: ";
    cout << pageFaults(pages, n, capacity); 
    return 0; 
} 
