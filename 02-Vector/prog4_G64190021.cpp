#include <bits/stdc++.h>
using namespace std;

int *getValues()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
        arr[i] = i + 1;
    return arr;
}

int main()
{
    int *array;
    array = getValues();

    for (int i = 0; i < 10; i++)
    {
        cout << "*(array + " << i << ") : ";
        cout << *(array + i) << endl;
    }
    return 0;
}
