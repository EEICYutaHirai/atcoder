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
#define MAX_TIME 100001

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int n, c;
    cin >> n >> c;

    bool is_used[c][MAX_TIME];
    rep(i, c)
    {
        fill(is_used[i], is_used[i] + MAX_TIME, false);
    }

    rep(i, n)
    {
        int s, t, c_i;
        cin >> s >> t >> c_i;
        c_i--;
        for (int i = s; i <= t; i++)
        {
            is_used[c_i][i] = true;
        }
    }

    int ans = 0;
    rep(i, MAX_TIME)
    {
        int tmp = 0;
        rep(j, c)
        {
            if (is_used[j][i])
                tmp++;
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;
}