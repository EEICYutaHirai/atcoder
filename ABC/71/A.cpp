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
    int X, A, B;
    cin >> X >> A >> B;
    if (abs(X - A) < abs(X - B))
    {
        cout << "A" << endl;
    }
    else
    {
        cout << "B" << endl;
    }
    return 0;
}