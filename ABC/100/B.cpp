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
    int d, n;
    cin >> d >> n;
    int res = 1;
    for (int i = 0; i < d; i++)
    {
        res *= 100;
    }
    n = (n == 100) ? 101 : n;
    cout << res * n << endl;
}