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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int n, x;
    cin >> n >> x;
    int m[n];
    int min = INF;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
        x -= m[i];
        min = min > m[i] ? m[i] : min;
    }
    int ans = n;
    ans += x / min;
    cout << ans << endl;
}