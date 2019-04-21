/*
title:C - Linear Approximation

url:https://abc102.contest.atcoder.jp/tasks/arc100_a

1.A_i - i　をしておくことで、関数を単純にする
2.グラフを考えればわかるが、真ん中あたりでさいしょうになる。
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
    int data[n];
    REP(i, n)
    {
        cin >> data[i];
        data[i] -= i + 1;
    }
    sort(data, data + n);
    int b = data[n / 2];
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        res += abs(data[i] - b);
    }
    cout << res << endl;
}