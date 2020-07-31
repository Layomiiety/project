//acw196
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define LL long long
#define il inline
const int N=2e4+5,M=1e6+5;
int pr[N>>1],l,u,cnt,n;
int pri[M];
bool st[M];
void init(){
    for(int i=2;i<=50000;i++){
        if(!st[i])pr[cnt++]=i;
        for(int j=0;j<cnt&&i*pr[j]<=50000;j++){
            st[i*pr[j]]=1;
            if(!(i%pr[j]))break;
        }
    }
}
int main(){
    init();
    while(cin>>l>>u){
        memset(st,0,sizeof st);
        for(int i=0;i<cnt;i++){
            LL p=pr[i];
            for(LL j=max(2*p,(l+p-1)/p*p);j<=u;j+=p){
                st[j-l]=1;
            }
        }
        int cc=0;
        for(int i=0;i<=u-l;i++){
            if(!st[i]&&(i+l)!=1)pri[cc++]=i+l;
        }
        if(cc<2){
            puts("There are no adjacent primes.");
            continue;
            }
        int mind=M,c1,c2,maxd=0,d1,d2;
        for(int i=0;i<cc-1;i++){
            if(pri[i+1]-pri[i]<mind){
                mind=pri[i+1]-pri[i];
                c1=pri[i],c2=pri[i+1];
            }
            if(pri[i+1]-pri[i]>maxd){
                maxd=pri[i+1]-pri[i];
                d1=pri[i],d2=pri[i+1];
            }
        }
        printf("%d,%d are closest, %d,%d are most distant.\n",c1,c2,d1,d2);
    }
    return 0;
}