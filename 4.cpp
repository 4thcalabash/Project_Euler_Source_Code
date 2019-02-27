//
// Created by Administrator on 2019/2/27.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll x){
    string s = to_string(x);
    string t = s;
    reverse(t.begin(),t.end());
    return t == s;
}
int main(){
    ll ans = -1;
    for (int i=100;i<=999;i++){
        for (int j=100;j<=999;j++){
            ll x = i * j;
            if (check(x)){
                ans = max(ans,x);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
