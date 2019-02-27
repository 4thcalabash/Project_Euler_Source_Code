//
// Created by Administrator on 2019/2/27.
//

#include<bits/stdc++.h>

using namespace std;

const int maxn = 4e7+10;

typedef long long ll;

bool used[maxn];

int mu[maxn];

vector<int> prime;

ll f[maxn];

int low[maxn];

int euler[maxn];

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
            f[i] = 2;

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

                    // nxt = prime[j] ^ k

                    //f:TODO
                    f[nxt] = f[nxt / prime[j]] + 1;

                }

                break;

            }

        }

    }

}

int main(){
    sieve(4e7);
    for (int i=1;i < 4e7;i++){
        int x = i;
        int y = i + 1;
        if (x %2 == 0){
            x /=2;
        }else{
            y /=2;
        }
        ll ans = 1ll * x * y;
        ll cnt = 1ll * f[x] * f[y];
        if (cnt > 500){
            cout<<ans<<endl;
            return 0;
        }
    }
    return 0;

}