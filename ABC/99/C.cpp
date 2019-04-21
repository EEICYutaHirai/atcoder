/*
title:C - Strange Bank

url:https://abc099.contest.atcoder.jp/tasks/abc099_c

再帰で解く
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

//残金leftを消費するのに必要な最小の枚数を返す関数
int solve(int left)
{
    if (left < 9)
    {
        if (left < 6)
            return left;
        return 1 + (left - 6);
    }

    int dcr_nine = 1;
    while (left >= dcr_nine * 9)
    {
        dcr_nine *= 9;
    }

    int dcr_six = 1;
    while (left >= dcr_six * 6)
    {
        dcr_six *= 6;
    }

    return min(1 + solve(left - dcr_six), 1 + solve(left - dcr_nine));
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}