#include<bits/stdc++.h> 
using namespace std; 
void bestFit(int block_size[], int m, int process_size[], int n) { 
    int allocate[n]; 
    memset(allocate, -1, sizeof(allocate));         // pre-set all process allocation values as -1
    for (int i=0; i<n; i++) {       
        int idx = -1; 
        for (int j=0; j<m; j++) {       
            if (block_size[j] >= process_size[i]) {        // basic condition is block must always be bigger than process
                if (idx == -1) idx = j; 
                else if (block_size[idx] < block_size[j]) idx = j;      // iterate to find worst fit
            } 
        } 
        if (idx != -1) {                // if basic condition satisfied, allocation process
            allocate[i] = idx; 
            block_size[idx] -= process_size[i];   
        } 
    } 
    cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
    for (int i = 0; i < n; i++) { 
        cout << " " << i+1 << "\t\t" << process_size[i] << "\t\t"; 
        if (allocate[i] != -1) 
            cout << allocate[i] + 1; 
        else 
            cout << "Not Allocated"; 
            cout << endl; 
    } 
} 
int main() { 
    int block_size[] = { 100, 500, 200, 300, 600 }; 
    int process_size[] = { 212, 417, 112, 426 }; 
    int m = sizeof(block_size) / sizeof(block_size[0]); 
    int n = sizeof(process_size) / sizeof(process_size[0]); 
    bestFit(block_size, m, process_size, n); 
    return 0; 
} 
