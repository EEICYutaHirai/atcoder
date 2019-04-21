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
    int a, b, x;
    cin >> a >> b >> x;
    if (x <= b + a && x >= a)
    {
        cout << "YES" << endl;
        return 0;
    }
    else
    {
        cout << "NO" << endl;
        return 0;
    }
}