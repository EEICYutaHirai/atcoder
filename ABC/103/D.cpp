/*
title:D - Islands War

url:https://abc103.contest.atcoder.jp/tasks/abc103_d

方針
断行したい島の組み合わせai, biにたいして、二次元座標を作って考えてみる
入力が
5 2 
1 4 
2 5
なら
g/s 1 2 3 4 5
1 
2
3
4     1
5   1
ここで、2番目の橋を破壊するということは
g/s 1 2 | 3 4 5
1       |
2       |
- - - - - - - - 
3       |
4     1 |
5   1   |
上のように区切ることと同義。左下の区間が、断行に成功した島。
必ずai<biなのだから、bi=ai+1の数が答えになる
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
    int N, M;
    cin >> N >> M;
    int g_min[N + 1];
    for (int i = 0; i < N + 1; i++)
    {
        g_min[i] = N + 1;
    }

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        if (g_min[a] > b)
        {
            g_min[a] = b;
        }
    }
    int ans = 0;
    int min = g_min[1];
    for (int i = 1; i <= N - 1; i++)
    {
        if ((min == i + 1) || g_min[i] == i + 1)
        {
            ans++;
            min = g_min[i + 1];
            continue;
        }
        else if (min > g_min[i])
            min = g_min[i];
    }
    cout << ans << endl;
}