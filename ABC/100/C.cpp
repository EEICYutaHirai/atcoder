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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> p_i;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        while (a % 2 == 0)
        {
            a /= 2;
            ans++;
        }
    }
    cout << ans << endl;
}