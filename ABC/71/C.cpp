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
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int N;
    cin >> N;
    priority_queue<int> q;
    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }

    int max_edge[2] = {};
    int index = 0;
    while (!q.empty())
    {
        int tmp = q.top();
        q.pop();
        if ((!q.empty()) && q.top() == tmp)
        {
            q.pop();
            max_edge[index] = tmp;
            index++;
            if (index == 2)
                break;
        }
    }
    cout << max_edge[0] * max_edge[1] << endl;
}