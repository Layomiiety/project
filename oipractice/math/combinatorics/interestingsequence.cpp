//acw1316
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define il inline
#define ll long long
const int N=1e6+5;
int cnt,pr[N];
bool st[N<<1];
int n,p;
void init(int x){
    for(int i=2;i<=x;i++){
        if(!st[i])pr[cnt++]=i;
        for(int j=0;j<cnt&&pr[j]*i<=x;j++){
            st[i*pr[j]]=true;
            if(!(i%pr[j]))break;
        }
    }
}
il int get(int x,int m){
    int s=0;
    while(x){
        s+=x/m;
        x/=m;
    }
    return s;
}
il int qp(int ori,int base,int po){
    for(;po;po>>=1){
        if(po&1)ori=(ll)ori*base%p;
        base=(ll)base*base%p;
    }
    return ori;
}
il int fac(){
    int res=1;
    for(int i=0;i<cnt;i++){
        int pp=pr[i],s=get(2*n,pp)-get(n,pp)-get(n+1,pp);
        //printf("%d %d\n",s,pp);
        res=qp(res,pp,s);
    }
    return res;
}
int main(){
    scanf("%d%d",&n,&p);
    init(2*n);
    printf("%d",fac());
}