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
    int a[n + 2] = {};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int l = 0;
    for (int i = 1; i < n + 2; i++)
    {
        l += abs(a[i] - a[i - 1]);
    }
    for (int i = 1; i < n + 1; i++)
    {
        int tmp[3] = {a[i - 1], a[i], a[i + 1]};
        sort(tmp, tmp + 3);
        int tmpl = l;
        if (tmp[1] == a[i])
        {
            cout << tmpl << endl;
        }
        else if (tmp[1] == a[i - 1])
        {
            tmpl -= 2 * abs(a[i] - a[i - 1]);
            cout << tmpl << endl;
        }
        else
        {
            tmpl -= 2 * abs(a[i] - a[i + 1]);
            cout << tmpl << endl;
        }
    }
    return 0;
}