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

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

int n, k;
int a[50];

int solve(int index, int rest)
{
}

signed main()
{
    cin >> n >> k;
    int sum = 0;
    REP(i, n)
    {
        cin >> a[i];
        int count = 0;
        while (a[i] != 0)
        {
            a[i] /= 2;
            count++;
        }
        a[i] = count;
        sum += count;
    }
}