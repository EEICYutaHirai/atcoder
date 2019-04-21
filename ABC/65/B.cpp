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
    int data[N];
    rep(i, N)
    {
        cin >> data[i];
    }
    int count = 0;
    int next_n = 1;

    while (true)
    {
        next_n--;
        next_n = data[next_n];
        count++;
        if (next_n == 1 || next_n == 2)
        {
            break;
        }
        if (count > N)
        {
            break;
        }
    }

    if (next_n != 2)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << count << endl;
    }
    return 0;
}