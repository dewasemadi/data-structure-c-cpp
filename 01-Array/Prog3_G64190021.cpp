#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    v.assign(5, 10); // size 5, diisi semua angka 10

    cout << "The vector elements are: ";
    for (int i = 0; i < v.size(); i++) //0 1 2 3 4
        cout << v[i] << " ";

    v.push_back(15);                                   // i = 5, diisi 15
    int n = v.size();                                  //n = 6, dari 0 - 5
    cout << "\nThe  last  element  is:  " << v[n - 1]; //v[5]

    v.pop_back(); //hapus i = 5, yaitu 15

    cout << "\nThe  vector  elements  are:  ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " "; //kembali ke semula

    v.insert(v.begin(), 5); //masukkan 5 ke i = 0, maka total i = 6. v berisi 5 10 10 10 10 10
    cout << "\nThe  first  element  is:  " << v[0];

    v.erase(v.begin()); //hapus 5 saat i = 0, maka total i = 5, v berisi 10 10 10 10 10
    cout << "\nThe  first  element  is:  " << v[0];

    v.emplace(v.begin(), 5); //mirip seperti insert
    cout << "\nThe  first  element  is:  " << v[0];

    v.emplace_back(20);                                //masukin 20 ke i = 5 (i paling akhir, 0 1 2 3 4 5)
    n = v.size();                                      //sekarang n  = 6
    cout << "\nThe  last  element  is:  " << v[n - 1]; //v[5]

    v.clear();                                               //hapus semua konten
    cout << "\nVector  size  after  erase():  " << v.size(); //karena semua udh dihapus, maka v kosong

    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    // v1 = 1 2
    v2.push_back(3);
    v2.push_back(4);
    // v2 = 3 4

    cout << "\n\nVector  1:  ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";

    cout << "\nVector  2:  ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";

    v1.swap(v2); //tukar v1 dan v2

    cout << "\nAfter  Swap  \nVector  1:  ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";

    cout << "\nVector  2:  ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
}
