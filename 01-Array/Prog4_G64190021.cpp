#include <iostream>
#define size 5
using namespace std;

int main()
{
    int g1[size];
    // masukin isi array
    for(int i =1; i<=size; i++)
        g1[i]=i;

    cout << "Output of begin and end: ";
    for(int i =1; i<=size; i++)
        cout<<g1[i]<<" ";
    
    cout << "\nOutput  of  rbegin  and  rend:  ";
    for(int i =size; i>=1; i--)
        cout<<g1[i]<<" ";
}
