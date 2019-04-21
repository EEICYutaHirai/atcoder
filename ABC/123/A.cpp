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

int main()
{
    int l[5], k;
    for (int i = 0; i < 5; i++)
    {
        cin >> l[i];
    }
    cin >> k;
    if (l[4] - l[0] <= k)
    {
        cout << "Yay!" << endl;
    }
    else
    {
        cout << ":(" << endl;
    }
}