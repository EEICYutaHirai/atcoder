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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a % 2 == 0 || b % 2 == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}