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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;

    ll res = 0;
    ll t;
    for (int a = 1; a <= n; a++)
    {
        if (a * 2 % k == 0)
        {
            if ((1 + a) % k == 0)
            {
                t = (n + a) / k - (1 + a) / k + 1;
                res += t * t;
            }
            else
            {
                t = (n + a) / k - (1 + a) / k;
                res += t * t;
            }
        }
    }
    cout << res << endl;
}