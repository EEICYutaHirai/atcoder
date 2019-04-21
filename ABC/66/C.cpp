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
    vector<int> A;
    vector<int> B;
    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    int max_n = (((N - 1) % 2 == 0) ? N - 1 : N - 2);
    for (int i = max_n; i >= 0; i -= 2)
    {
        B.push_back(A[i]);
    }
    max_n = (((N - 1) % 2 == 1) ? N - 1 : N - 2);
    for (int i = 1; i <= max_n; i += 2)
    {
        B.push_back(A[i]);
    }

    if (N % 2 == 0)
    {
        reverse(B.begin(), B.end());
    }
    rep(i, N)
    {
        cout << B[i] << " ";
    }
    cout << endl;
}