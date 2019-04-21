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
    int n, x;
    cin >> n >> x;
    priority_queue<int, vector<int>, greater<int>> q;
    rep(i, n)
    {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
    int ans = 0;
    while (q.size() && x > 0)
    {
        x -= q.top();
        ans++;
        q.pop();
    }
    if (x != 0)
    {
        ans--;
    }
    cout << ans << endl;
}