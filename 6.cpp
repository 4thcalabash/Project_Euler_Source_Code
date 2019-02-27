//
// Created by Administrator on 2019/2/27.
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
typedef long long ll;
int main(){
    ll temp = maxn * (maxn+1)/2;
    temp *= temp;
    for (int i=1;i<=maxn;i++){
        temp -= i * i;
    }
    cout<<temp<<endl;
    return 0;
}
