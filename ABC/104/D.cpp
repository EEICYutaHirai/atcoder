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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef long long ll;
typedef pair<int, int> pint;

//動的計画法を使うといいらしい。
//ちゃんとその発想を思いつけるようにしたい...
//計算量が多いがパラメーター自体は少ない、そして左から順番に読んでいく、
//という点が動的計画法の発想のポイントか...

int main()
{
    string s;
    cin >> s;
    ll dp[s.size() + 1][4];
    dp[s.size()][0] = 0;
    dp[s.size()][1] = 0;
    dp[s.size()][2] = 0;
    dp[s.size()][3] = 1;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            if (s[i] == '?')
            {
                dp[i][j] = 3 * dp[i + 1][j] + dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = dp[i + 1][j];
                if ((s[i] - 'A') == j)
                {
                    dp[i][j] += dp[i + 1][j + 1];
                }
            }
        }
        if (s[i] == '?')
        {
            dp[i][3] = 3 * dp[i + 1][3];
        }
        else
        {
            dp[i][3] = dp[i + 1][3];
        }
        for (int j = 0; j < 4; j++)
        {
            dp[i][j] %= INF;
        }
    }

    cout << dp[0][0] << endl;
}