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
    int A, B;
    cin >> A >> B;
    int ans = 0;
    for (int i = 0; i < 2; i++)
    {
        if (A >= B)
        {
            ans += A;
            A--;
        }
        else
        {
            ans += B;
            B--;
        }
    }
    cout << ans << endl;
}