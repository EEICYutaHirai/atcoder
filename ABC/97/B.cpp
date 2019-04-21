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
    int x;
    int ans = -1;
    cin >> x;
    if (x == 1)
    {
        cout << x << endl;
        return 0;
    }
    for (int i = 2; i <= sqrt(x); i++)
    {
        int tmp = i;
        while (tmp * i <= x)
        {
            tmp *= i;
        }
        ans = tmp > ans ? tmp : ans;
    }
    cout << ans << endl;
    return 0;
}