//
// Created by Administrator on 2019/2/27.
//

//
// Created by Administrator on 2019/2/27.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll ans = 1;
    vector<int> prime = {2,3,5,7,11,13,17,19};
    for (int x : prime){
        int temp = 20;
        while (temp/x){
            ans *= x;
            temp /=x;
        }
    }
    cout<<ans<<endl;
}