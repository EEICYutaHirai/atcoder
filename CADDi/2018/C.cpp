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
#define int unsigned long long

typedef pair<int, int> pint;
typedef long long ll;

int pow_kai(int a, int n)
{ //aのn乗を計算します。
    int x = 1ull;
    while (n > 0ull)
    { //全てのbitが捨てられるまで。
        if (n & 1ull)
        { //1番右のbitが1のとき。
            x = x * a;
        }
        if (x >= 1125899906842624)
        {
            return -1;
        }
        if (x == 0)
        {
            return -1;
        }
        a = a * a;
        n >>= 1ull; //bit全体を右に1つシフトして一番右を捨てる。
    }
    return x;
}

signed main()
{
    int N, P;
    cin >> N >> P;
    if (N == 1)
    {
        cout << P << endl;
        return 0;
    }
    int ans = 1;
    for (int i = 2; i <= P; i++)
    {
        int tmp = pow_kai(i, N);
        if (tmp < 0)
        {
            continue;
        }
        if (tmp > P)
        {
            break;
        }
        if (P % tmp == 0 && tmp != 0)
        {
            P /= tmp;
            ans *= i;
            i--;
        }
    }
    cout << ans << endl;
    return 0;
}