


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
    int N;
    cin >>N;
    data[N][N];
    
    rep(i,N){
        rep(j,i+1){
            if(i==0){
                data[i][j]=1;
            }else{
                data[i][j]=i+1;
            }
        }
    }
}