/*
title:

url:

似たような問題がC問題であったはずなのでそこから連想。
https://abc104.contest.atcoder.jp/tasks/abc104_c
この問題にとても似ていると感じた。特に状態を制限できるところが
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
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int n, h;
    cin >> n >> h;
    //huru, nageru
    priority_queue<int> hr, ng;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        hr.push(a);
        ng.push(b);
    }
    int ans = 0;
    while (h > 0)
    {
        if (ng.empty() || hr.top() > ng.top())
        {
            ans += h / hr.top();
            if (h % hr.top() != 0)
                ans++;
            break;
        }
        else
        {
            h -= ng.top();
            ans++;
            ng.pop();
        }
    }
    cout << ans << endl;
}