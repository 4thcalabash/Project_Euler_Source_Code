//
// Created by DELL on 2019/2/28.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 80;
int num[maxn][maxn];
ll f[maxn][maxn];
int main(){
    freopen("input/input.81","r",stdin);
    memset(f,0x3f3f3f3f,sizeof f);
    for (int i=0;i<maxn;i++){
        for (int j=0;j<maxn-1;j++){
            scanf("%d,",&num[i][j]);
        }
        scanf("%d",&num[i][maxn-1]);

    }
    f[79][79] = num[79][79];
    for (int i=79;i>=0;i--){
        for (int j=79;j>=0;j--){
            if (i == 79 && j == 79)continue;
            if (i < 79){
                f[i][j] = min(f[i][j],f[i+1][j]);
            }
            if (j < 79){
                f[i][j] = min(f[i][j],f[i][j+1]);
            }
            f[i][j] += num[i][j];
        }
    }

    cout<<f[0][0]<<endl;
}
