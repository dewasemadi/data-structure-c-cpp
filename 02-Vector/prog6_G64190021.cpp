#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

#define M 4
#define N 5

int main()
{
    int **A = new int *[M];
    // dynamic allocate memory of size N for each row
    for (int i = 0; i < M; i++)
        A[i] = new int[N];

    // assign values to allocated memory
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = rand() % 100;

    // print the 2D array
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            cout << A[i][j];
            // cek spasi dan newline
            if (j == N - 1)
                cout << endl;
            else
                cout << " ";
        }

    // deallocate memory
    for (int i = 0; i < M; i++)
        delete[] A[i];
    delete[] A;
    return 0;
}
