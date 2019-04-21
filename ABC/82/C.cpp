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

    priority_queue<int> q;
    rep(i, n)
    {
        int a;
        cin >> a;
        q.push(a);
    }

    int ans = 0;
    while (!q.empty())
    {
        int tmp = q.top();
        int count = 0;
        while ((!q.empty()) && q.top() == tmp)
        {
            q.pop();
            count++;
        }
        if (tmp <= count)
        {
            ans += count - tmp;
        }
        else
        {
            ans += count;
        }
    }

    cout << ans << endl;
}