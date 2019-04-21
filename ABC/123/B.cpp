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

int main()
{
    int data[5];
    int deff[5];
    pint pdata[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> data[i];
        deff[i] = data[i] - data[i] / 10 * 10;
        if (deff[i] != 0)
        {
            deff[i] = 10 - deff[i];
        }
        pdata[i] = make_pair(deff[i], data[i]);
    }

    int ans = 0;
    sort(pdata, pdata + 5);
    bool add_none_zero = false;
    ans += pdata[4].second;
    for (int i = 0; i < 4; i++)
    {
        if (pdata[i].second % 10 == 0)
        {
            ans += pdata[i].second;
        }
        else
        {
            ans += pdata[i].second / 10 * 10 + 10;
        }
    }
    cout << ans << endl;
}