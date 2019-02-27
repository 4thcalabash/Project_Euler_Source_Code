//
// Created by Administrator on 2019/2/27.
//
#include<bits/stdc++.h>
using namespace std;
int main(){

    for (int a = 1;a <1000;a ++){
        for (int b = a ;b < 1000 - a;b ++){
            int c = 1000 - a - b;
            if (c <= b)continue;
            if (a * a + b * b == c * c){
                cout<<a * b * c<<endl;
            }
        }
    }
    return 0;
}
