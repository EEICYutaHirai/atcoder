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

int gcd(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}

int main()
{
    string S,T;
    int S_s, T_s;
    cin >> S_s >> T_s;
    cin >> S>>T;
    int n_ans = S.size()*T.size()/gcd(S.size(),T.size());
    string ans;
    rep(i,n_ans){
        ans+="-";
    }
    rep(i,S.size()){
        ans[n_ans*i/S.size()]=S[i];
    }
    rep(i,T.size()){
        if(ans[n_ans*i/T.size()]=='-'){
            ans[n_ans*i/T.size()]=T[i];
        }else{
            if(ans[n_ans*i/T.size()]!=T[i]){
                cout << -1<<endl;
                return 0;
            }
        }
    }
    rep(i,n_ans){
        if(ans[i]=='-'){
            ans[i] = 'a';
        }
    }
    cout <<ans.size()<<endl;
    return 0;
}