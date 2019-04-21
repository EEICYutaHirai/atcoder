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

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int t[n + 1], x[n + 1], y[n + 1];
    t[0] = x[0] = y[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> x[i] >> y[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int sum = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
        int tm = t[i] - t[i - 1];
        if (!(tm - sum >= 0 && (tm - sum) % 2 == 0))
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}