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
    int x, a, b;
    cin >> x >> a >> b;
    if (b - a <= 0)
    {
        cout << "delicious" << endl;
    }
    else if (b - a <= x)
    {
        cout << "safe" << endl;
    }
    else
    {
        cout << "dangerous" << endl;
    }
    return 0;
}