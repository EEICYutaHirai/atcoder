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

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int n = 0;
    cin >> n;
    int a[n];
    REP(i, n)
    {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    int alice = 0, bob = 0;
    REP(i, n)
    {
        if (i % 2 == 0)
            alice += a[i];
        else
            bob += a[i];
    }
    cout << alice - bob << endl;
}