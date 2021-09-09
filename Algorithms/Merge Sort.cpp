#include <bits/stdc++.h>

using namespace std;

void merge(int A[], int l, int mid, int h)
{
    int i, j, k;
    int B[h + 1];
    i = l;
    j = mid + 1;
    k = l;
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];
    for (i = l; i <= h; i++)
        A[i] = B[i];
}

void mergeSort(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h - 1) / 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
    else
        return;
}

int main()
{
    cout <<endl<< "----- MERGE SORT -----\n";
    cout << "Enter Size of Array: ";
    int n;
    cin >> n;
    cout << "Enter elements: ";
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(a, 0, n - 1);
    cout <<endl<< "Array after Merge Sort: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}