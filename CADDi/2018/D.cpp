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
    int N;
    cin >> N;
    int odd_count = 0;
    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 0)
        {
            odd_count++;
        }
    }
    if (odd_count == 0 || odd_count == 3)
    {
        cout << "second" << endl;
    }
    else
    {
        cout << "first" << endl;
    }
    return 0;
}