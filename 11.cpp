//
// Created by Administrator on 2019/2/27.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20;
int num[maxn][maxn];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
ll work(int x,int y){
    ll ans = -1;
    for (int k = 0;k < 8;k++){
        ll t = 1 ;
        for (int step = 0;step < 4;step ++){
            int xx = x + step *dx[k];
            int yy = y + step * dy[k];
            if (xx <maxn && yy < maxn && xx >=0 && yy >=0){
                t *= num[xx][yy];
            }else{
                t = -1;
                break;
            }
        }
        ans = max(ans,t);
    }
    return ans;
}
int main(){
    ifstream fin("input/input.11");
    for (int i=0;i<maxn;i++){
        for (int j=0;j<maxn;j++){
            fin>>num[i][j];
        }
    }
    ll ans = -1;
    for (int i=0;i<maxn;i++){
        for (int j=0;j<maxn;j++){
            ans = max(ans,work(i,j));
        }
    }
    cout<<ans<<endl;
}
