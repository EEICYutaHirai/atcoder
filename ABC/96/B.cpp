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
    int a, b, c;
    cin >> a >> b >> c;
    int k;
    cin >> k;
    int max_n = max({a, b, c});
    int ans = a + b + c;
    ans -= max_n;
    for (int i = 0; i < k; i++)
    {
        max_n *= 2;
    }
    ans += max_n;
    cout << ans << endl;
}