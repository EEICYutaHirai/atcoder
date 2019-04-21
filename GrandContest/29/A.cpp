/*
title:

url:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <queue>
#include <limits>
#include <string>
#include <utility>
#include <cstring>
#include <map>
#include <cmath>
#include <iterator>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

string S;

int main()
{
    cin >> S;
    int res = 0;
    for (int i = 0; i < S.size() - 2; i++)
    {
        if (S.substr(i, 3) == "BBW")
        {
            res += 2;
            S[i] = 'W';
            S[i + 2] = 'B';
        }
        else if (S.substr(i, 3) == "BWB")
        {
            res += 1;
            S[i] = 'W';
            S[i + 1] = 'B';
        }
        else if (S.substr(i, 3) == "WBW")
        {
            res += 1;
            S[i + 1] = 'W';
            S[i + 2] = 'B';
        }
        else if (S.substr(i, 3) == "BWW")
        {
            res += 2;
            S[i] = 'W';
            S[i + 2] = 'B';
        }
    }
    cout << res << endl;
}