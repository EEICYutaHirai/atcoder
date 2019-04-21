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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int x[n] = {};
    int sortx[n] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        sortx[i] = x[i];
    }
    sort(sortx, sortx + n);

    //less median, greater median
    int lm = sortx[(n / 2) - 1];
    int gm = sortx[n / 2];
    for (int i = 0; i < n; i++)
    {
        if (x[i] <= lm)
        {
            cout << gm << endl;
        }
        else
        {
            cout << lm << endl;
        }
    }
    return 0;
}