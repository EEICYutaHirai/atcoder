#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string ans = "";
    while (1)
    {
        int amari = abs(N % (-2));
        N = (N - amari) / (-2);
        char add = amari + '0';
        ans = add + ans;
        if (N == 0)
        {
            break;
        }
    }
    cout << ans << endl;
}