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
    int n2, n4, odd;
    n2 = n4 = odd = 0;
    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        if (tmp % 4 == 0)
        {
            n4++;
        }
        else if (tmp % 2 == 0)
        {
            n2++;
        }
        else
        {
            odd++;
        }
    }
    if (n2 != 0)
    {
        odd++;
    }
    if (odd - 1 <= n4)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}