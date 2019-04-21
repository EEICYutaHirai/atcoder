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
    int data[3];
    rep(i, 3)
    {
        cin >> data[i];
    }
    rep(i, 3)
    {
        if (data[i] == data[(i + 1) % 3])
        {
            cout << data[(i + 2) % 3] << endl;
            return 0;
        }
    }
}