#include <bits/stdc++.h>
using namespace std;

int what(int arr[], int n)
{
    int m = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > m)
            m = arr[i];
    return m;
}

int main()
{
    int arr[] = {10, 324, 45, 90, 9808};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Hasilnya adalah : " << what(arr, n);
    return 0;
}
