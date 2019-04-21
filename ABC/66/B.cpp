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
    string S;
    cin >> S;
    for (int i = S.size() - 2; i >= 0; i--)
    {
        if (i % 2 == 1)
        {
            bool is_even = true;
            for (int j = 0; j < (i + 1) / 2; j++)
            {
                if (S[j] != S[(i + 1) / 2 + j])
                {
                    is_even = false;
                }
            }
            if (is_even)
            {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}