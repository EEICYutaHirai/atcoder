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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + b > c + d)
        cout << "Left" << endl;
    else if (a + b == c + d)
        cout << "Balanced" << endl;
    else
        cout << "Right" << endl;
    return 0;
}