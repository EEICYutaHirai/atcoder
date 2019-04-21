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
    int nbigger[N] = {};
    int data[N];
    rep(i, N)
    {
        cin >> data[i];
        rep(j, i)
        {
            if (data[j] > data[i])
            {
                nbigger[i]++;
            }
        }
    }
    int ans = 0;
    //iとjを交換すると?
    rep(i, N)
    {
        rep(j, i)
        {
            int tmp_ans = 1;
            if (data[i] < data[j])
            {
                        }
        }
    }
}