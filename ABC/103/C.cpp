/*
title:C - Modulo Summation

url:https://abc103.contest.atcoder.jp/tasks/abc103_c

方針
与えらえれた数字の最小公倍数-1のとき、f(m)は最大になる。
このときの最大値は、各数字-1 の和であるので、それを出力するだけでいい
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
    int n;
    cin >> n;
    int a[n];
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        res += a[i] - 1;
    }
    cout << res << endl;
}