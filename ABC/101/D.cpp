/*
title:D - Snuke Numbers

url:https://abc101.contest.atcoder.jp/tasks/arc099_b

方針:
各桁に関して偏微分すれば、末尾が全て9であればいいということが証明できる。
確認のためtestd.cppでこのことを確かめている。
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
#define int long long

typedef pair<int, int> p_i;

void print_sunuke(int n)
{
    int n_digit;
    int max_digit;
    n_digit = (n % 9 == 0) ? n / 9 : n / 9 + 1;
    max_digit = (n % 9 == 0) ? 9 : n % 9;
    cout << max_digit;
    for (int i = 0; i < n_digit - 1; i++)
    {
        cout << 9;
    }
    cout << endl;
}

signed main()
{
    int k;
    cin >> k;

    for (int i = 1; i <= k; i++)
    {
        print_sunuke(i);
    }
}