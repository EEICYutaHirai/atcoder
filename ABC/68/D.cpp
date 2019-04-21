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
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int N = 50;
    int data[N];
    int K;
    cin >> K;
    int syou = K / N;
    int amari = K - syou * N;
    /*
    fill(data, data + N, N - 1 + syou - amari);
    data[0] = N - 1 + syou + amari * N;
    */
    fill(data, data + N, N - 1 + syou - amari);
    fill(data, data + amari, 2 * N + syou - amari);
    cout << N << endl;
    rep(i, N)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}