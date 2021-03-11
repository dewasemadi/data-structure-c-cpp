#include <bits/stdc++.h>
using namespace std;

void search(char *pat, char *txt)
{
    int M = strlen(pat), N = strlen(txt);

    // a loop to slide pat[] 1 by 1
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        // for current index i, check for pattern match
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        // if pat[0 ... M-1] = txt[i, i+1, ... i+M-1]
        if (j == M)
            cout << "Pattern found at index " << i << endl;
    }
}

int main()
{
    char txt[] = "AABAACAADAABAAABAA", pat[] = "AABA";
    search(pat, txt);
    return 0;
}