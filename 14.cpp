//
// Created by DELL on 2019/2/28.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,int> ans;
const int maxn = 1e6;
void work(ll x){
    if (ans.find(x)!= ans.end())return;
    if (x & 1){
        work(3*x+1);
        ans[x] = ans[3*x+1]+1;
    }else{
        work(x/2);
        ans[x] = ans[x/2] + 1;
    }

}
int main(){
    int max_ans = -1;
    int true_ans = -1;
    ans[1] = 1;
    for (int i=2;i<maxn;i++){
        work(i);
        if (ans[i] > max_ans){
            max_ans = ans[i];
            true_ans = i;
        }
    }
    cout<<true_ans<<endl;
    return 0;
}
