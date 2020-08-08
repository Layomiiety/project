//acw1307
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define il inline
typedef unsigned long long LL;
const int N=10005,M=100010;
int n,m,a[M],b[M];
int cnt,pr[N>>1];
bool st[N];
il void init(){
    for(int i=2;i<N;i++){
        if(!st[i])pr[cnt++]=i;
        for(int j=0;j<cnt&&pr[j]*i<N;j++){
            st[i*pr[j]]=true;
            if(!(i%pr[j]))break;
        }
    }
}
il int get(int x,int p){
    int s=0;
    while(x){
        s+=x/p;
        x/=p;
    }
    return s;
}
il void mul(int r[],int &len, int p){
    int t=0;
    for(int i=0;i<len;i++){
        t+=r[i]*p;
        r[i]=t%10;
        t/=10;
    }
    while(t){
        r[len++]=t%10;
        t/=10;
    }
}
il int C(int x,int y,int r[]){
    int len=1;
    r[0]=1;
    for(int i=0;i<cnt;i++){
        int p=pr[i];
        int s=get(y,p)-get(x,p)-get(y-x,p);
        while(s--)mul(r,len,p);
    }
    return len;
}
il void subs(int al,int a[],int bl,int b[]){
    int t=0;
    for(int i=0;i<al;i++){
        a[i]-=t+b[i];
        if(a[i]<0){
            a[i]+=10;
            t=1;
        }
        else t=0;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    init();
    int al=C(m,n+m,a),bl=C(n+1,n+m,b);
    subs(al,a,bl,b);
    for(int i=al-1;i>=0;i--){
        if(a[i]){
            for(int j=i;j>=0;j--)printf("%d",a[j]);
            break;
        }
    }
    return 0;
}
