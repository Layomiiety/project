//acw243
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=320;
#define ll long long
ll a[N],sum[M],add[M];
int m,n,len;
inline int get(int x){return x/len;}
void update(int l,int r,int d){
    if(get(l)==get(r)){
        int x=get(l);
        for(int i=l;i<=r;i++){
            sum[x]+=d;
            a[i]+=d;
        }
        return;
    }
    int i=l,j=r;
    while(get(i)==get(l)){
        a[i]+=d;
        sum[get(i)]+=d;
        i++;
    }
    while(get(j)==get(r)){
        a[j]+=d;
        sum[get(j)]+=d;
        j--;
    }
    for(int k=get(i);k<=get(j);k++){
        sum[k]+=len*d;
        add[k]+=d;
    }
}
ll query(int l,int r){
    ll res=0,x;
    if(get(l)==get(r)){
        x=get(l);
        for(int i=l;i<=r;i++){res+=a[i];res+=add[x];}
        return res;
    }
    int i=l,j=r;
    while(get(i)==get(l)){
        res+=a[i];
        res+=add[get(l)];
        i++;
    }
    while(get(j)==get(r)){
        res+=a[j];
        res+=add[get(r)];
        j--;
    }
    for(int k=get(i);k<=get(j);k++)res+=sum[k];
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    len=sqrt(n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[get(i)]+=a[i];
        }
    while(m--){
        char op[2];
        int l,r,d;
        scanf("%s%d%d",op,&l,&r);
        if(*op=='C'){
            scanf("%d",&d);
            update(l,r,d);
        }
        else printf("%lld\n",query(l,r));
    }
    return 0;
}