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
    string a, b;
    cin >> a >> b;
    if (a > b)
    {
        cout << ">" << endl;
    }
    else if (a < b)
    {
        cout << "<" << endl;
    }
    else
    {
        cout << "=" << endl;
    }
    return 0;
}