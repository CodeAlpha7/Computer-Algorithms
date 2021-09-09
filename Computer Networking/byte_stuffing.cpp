#include<bits/stdc++.h>
using namespace std;       

main(){
    char a[20], b[20];
    int i, n, j;
    char f, s;
    cout << "Enter the size of the frame : ";
    cin >> n;
    
    cout << "\nEnter the characters in frame : \n";
    for(i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n INPUT FRAME: ";                 // d = data sequence
    for(i = 0; i < n; i++)                      // e = escape sequence
        cout << a[i]<<" ";                      // f = flag sequence
    j = 0;
    
    for(i = 0; i < n; i++) {
        if(a[i] == 'f') {                   // in the input frame, if f comes, stuff S before every f.
            b[j] = 's';
            j++;
            b[j] = a[i];
        }
        else if(a[i] == 's') {              // in the input frame, if s comes, stuff s before every s
            b[j] = 's';                     
            j++;
            b[j] = a[i];
        }
        else
        b[j] = a[i];
        j++;
    }
    cout << "\n RESULTING STUFFED MESSAGE: ";
    cout << f;
    for(i = 0; i < j; i++) {
        cout << b[i]<<" ";
    }
    cout << f;
}