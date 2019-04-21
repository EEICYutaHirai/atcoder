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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a % b) : a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
// a x + b y = gcd(a, b)
int extgcd(int a, int b, int &x, int &y)
{
    int g = a;
    x = 1;
    y = 0;
    if (b != 0)
        g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

signed main()
{
    int n, x;
    cin >> n >> x;
    priority_queue<int, vector<int>, greater<int>> q;
    REP(i, n)
    {
        int tmp;
        cin >> tmp;
        if (abs(tmp - x) != 0)
        {
            q.push(abs(tmp - x));
        }
    }
    if (q.empty())
    {
        cout << 0 << endl;
        return 0;
    }
    int ans = q.top();
    q.top();
    while (!q.empty())
    {
        if (q.top() % ans != 0)
        {
            ans = gcd(ans, q.top());
        }
        q.pop();
    }
    cout << ans << endl;
    return 0;
}