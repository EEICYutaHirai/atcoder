/*
title:

url:D - Five, Five Everywhere

すべての素数が、５であった時の余りが１であればいい
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
    int n;
    cin >> n;
    int nmax = 55556;
    bool is_prime[nmax];
    for (int i = 2; i < nmax; i++)
    {
        is_prime[i] = true;
    }
    int count = 0;
    for (int i = 2; i < nmax; i++)
    {
        if (is_prime[i])
        {
            if (i % 5 == 1)
            {
                cout << i << endl;
                count++;
            }
            for (int j = i; j < nmax; j += i)
            {
                is_prime[j] = false;
            }
        }
        if (count == n)
        {
            return 0;
        }
    }
    return 0;
}