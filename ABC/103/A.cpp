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
    int a[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    int res = 0;
    int dif[3];
    for (int i = 0; i < 3; i++)
    {
        dif[i] = abs(a[i % 3] - a[(i + 1) % 3]);
        res += dif[i];
    }
    res -= max(dif[0], max(dif[1], dif[2]));
    cout << res << endl;
    return 0;
}