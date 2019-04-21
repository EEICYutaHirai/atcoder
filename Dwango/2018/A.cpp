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
    vector<int> data;
    int sum = 0;
    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
        sum += tmp;
    }
    int ans = 0;
    int min_diff = INF;
    rep(i, N)
    {
        if (min_diff > (N * data[i] - sum > 0 ? N * data[i] - sum : sum - N * data[i]))
        {
            ans = i;
            min_diff = (N * data[i] - sum > 0 ? N * data[i] - sum : sum - N * data[i]);
        }
    }
    cout << ans << endl;
}