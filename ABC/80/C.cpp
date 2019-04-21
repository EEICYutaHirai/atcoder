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
    int n;
    cin >> n;
    int max_attend[n] = {};
    rep(i, n)
    {
        rep(j, 10)
        {
            int tmp;
            cin >> tmp;
            if (tmp)
                max_attend[i]++;
        }
    }

    int profit[n][11];
    rep(i, n)
    {
        rep(j, 11)
        {
            cin >> profit[i][j];
        }
    }

    int index[n] = {};
    int ans = 0;
    rep(i, n)
    {
        rep(j, max_attend[i] + 1)
        {
            if (profit[i][index[i]] <= profit[i][j])
            {
                index[i] = j;
            }
        }
    }

    bool all_zero = true;
    rep(i, n)
    {
        if (index[i] != 0)
            all_zero = false;
    }

    if (all_zero)
    {
        int minimum = profit[0][0] - profit[0][1];
        pint min_index = pint(0, 1);
        rep(i, n)
        {
            for (int j = 1; j <= max_attend[i]; j++)
            {
                if (minimum >= profit[i][0] - profit[i][j])
                {
                    min_index = pint(i, j);
                    minimum = profit[i][0] - profit[i][j];
                }
            }
        }
        rep(i, n)
        {
            if (i == min_index.first)
            {
                ans += profit[min_index.first][min_index.second];
            }
            else
            {
                ans += profit[i][0];
            }
        }
    }
    else
    {
        rep(i, n)
        {
            ans += profit[i][index[i]];
        }
    }
    cout << ans << endl;
    return 0;
}