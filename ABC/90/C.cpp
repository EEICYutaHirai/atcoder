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
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    else if (n == 1)
    {
        cout << m - 2 << endl;
        return 0;
    }
    else if (m == 1)
    {
        cout << n - 2 << endl;
        return 0;
    }
    else if (n == 2 || m == 2)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        cout << n * m - 2 * (n - 1) - 2 * (m - 1) << endl;
        return 0;
    }
    return -1;
}