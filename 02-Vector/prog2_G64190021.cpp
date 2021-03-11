#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, num;
    vector<int> v;
    cin >> n;
    while (n--)
    {
        cin >> num;
        v.push_back(num);
    }
    cout << "Hasilnya adalah : " << *max_element(v.begin(), v.end());
    return 0;
}
