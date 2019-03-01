//
// Created by Administrator on 2019/2/27.
//

#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e8+10;

typedef long long ll;

bool used[maxn];

int mu[maxn];

vector<int> prime;

ll f[maxn];

int low[maxn];

void sieve(int size){

    //f:multiplicative function;

    assert(size < maxn);

    mu[1] = 1;

    f[1] = 1;

    for (int i=2;i<=size;i++){

        if (!used[i]){

            prime.push_back(i);

            mu[i] = -1;

            //f:TODO

            low[i] = i;

        }

        for (int j = 0;j < prime.size();j++){

            ll nxt = 1ll * i * prime[j];

            if (nxt > size)break;

            used[nxt] = 1;

            if (i % prime[j]){

                low[nxt] = prime[j];

                mu[nxt] = -mu[i];

                //f: mod or not?

                f[nxt] = f[i] * f[prime[j]];

            }else{

                low[nxt] = prime[j] * low[i];

                mu[nxt] = 0;

                if (low[nxt] != nxt){

                    //mod or not?

                    f[nxt] = 1ll * f[low[nxt]] * f[nxt/low[nxt]];

                }else{

                    // i = prime[j] ^ k

                    //f:TODO

                }

                break;

            }

        }

    }

}
const int MAXN = 5;
void output(vector<int> ans){
    int sum = 0;
    for (int x : ans){
        cout<<x<<" ";
        sum += x;
    }
    cout<<sum<<endl;
}
set<int> P;
vector<int> ans;
bool check(int x,int y){
    vector<int> t(0);
    while (y){
        t.push_back(y % 10);
        y /= 10;
    }
    reverse(t.begin(),t.end());
    for (int dig : t){
        x = x * 10 + dig;
    }
    if (P.count(x) == 0)return false;
    else return true;
}
bool check(vector<int> &tmp){
    int tmp_sum = 0;
    int ans_sum = 0;
    for (int i=0;i<MAXN;i++){
        tmp_sum += tmp[i];
        ans_sum += ans[i];
    }
    if (tmp_sum >=ans_sum)return false;
    return true;
}
void dfs(vector<int> & tmp,int min_limit,int max_limit){
    if (tmp.size() == MAXN){
        if (check(tmp)){
            ans = tmp;
        }
        return ;
    }
    for (int i=min_limit;i <=max_limit;i++){
        bool ok = true;
        for (int x : tmp){
            if (!check(x,prime[i]) || !check(prime[i],x)){
                ok = false;
                break;
            }
        }
        if (!ok)continue;
        tmp.push_back(prime[i]);
        dfs(tmp,i+1,max_limit);
        tmp.pop_back();
    }
}
int main(){

    sieve(1e8);
    for (int x : prime){
        P.insert(x);
    }

    int N = 2000;
    cout<<prime[N]<<endl;
    vector<int> x(0);
    ans.assign(MAXN,10000000);
    dfs(x,0,N);
    output(ans);
    return 0;

}