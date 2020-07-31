//acw197
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
const int N=1e6+5;
int pr[N>>1],cnt,n,cc;
bool st[N];
void init(){
    for(int i=2;i<=n;i++){
        if(!st[i])pr[cnt++]=i;
        for(int j=0;j<cnt&&pr[j]*i<=n;j++){
            st[i*pr[j]]=1;
            if(!(i%pr[j]))break;
        }
    }
}
int main(){
    scanf("%d",&n);
    init();
    for(int i=0;i<cnt;i++){
        int p=pr[i],cc=0;
        for(int j=n;j;j/=p){
            cc+=j/p;
        }
        printf("%d %d\n",p,cc);
    }
    return 0;
}
