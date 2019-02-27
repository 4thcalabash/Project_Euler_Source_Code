//
// Created by Administrator on 2019/2/27.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ifstream fin("input/input.8");
    if (!fin.is_open()){
        cerr<<"error"<<endl;
        exit(-1);
    }
    string s;
    string temp;
    while (fin>>temp){
        s += temp;
    }
    cout<<s<<endl;
    ll ans = -1;
    for (int i = 12;i < s.size();i++){
        ll t = 1;
        for (int j=i-12;j <=i;j++){
            t *= s[j] - '0';
        }
        ans = max(ans,t);
    }
    cout<<ans<<endl;
    return 0;
}
