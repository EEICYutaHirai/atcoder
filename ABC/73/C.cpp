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
    priority_queue<int> q;
    int N;
    cin >> N;
    rep(i, N)
    {
        int a;
        cin >> a;
        q.push(a);
    }

    int ans = 0;
    while (q.size())
    {
        int count = 0;
        int tmp = q.top();
        while ((!q.empty()) && q.top() == tmp)
        {
            q.pop();
            count++;
        }
        if (count % 2)
        {
            ans++;
        }
    }

    cout << ans << endl;
}