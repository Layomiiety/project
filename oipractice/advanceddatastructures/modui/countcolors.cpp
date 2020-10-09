//acw2521
#include <bits/stdc++.h>
using namespace std;
const int N=10005,M=1005,C=1e6+5;
int n,m,len,cnt[C],c[N],cq,cd,ans[N];
struct query{
    int id,l,r,t;
}q[N];
struct md{
    int x,c;
}dd[M];
inline int get(int x){return x/len;}
bool cmp(query a,query b){
    if(get(a.l)!=get(b.l))return get(a.l)<get(b.l);
    if(get(a.r)!=get(b.r))return get(a.r)<get(b.r);
    return a.t<b.t;
}
inline void add(int x,int& res){
    if(!cnt[x])res++;
    cnt[x]++;
}
inline void del(int x,int& res){
    cnt[x]--;
    if(!cnt[x])res--;
}
int main(){
    scanf("%d%d",&n,&m);
    len=sqrt(n);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    while(m--){
        char op[2];
        int x,y;
        scanf("%s%d%d",op,&x,&y);
        if(*op=='Q')q[cq++]={cq-1,x,y,cd};
        else dd[cd++]={x,y};
    }
    sort(q,q+cq,cmp);
    for(int i=0,j=1,t=0,k=0,res=0;k<cq;k++){
        int l=q[k].l,r=q[k].r,tt=q[k].t,id=q[k].id;
        while(j<l)del(c[j++],res);
        while(j>l)add(c[--j],res);
        while(i<r)add(c[++i],res);
        while(i>r)del(c[i--],res);
        while(t<tt){
            if(dd[t].x<=r&&dd[t].x>=l){
                del(c[dd[t].x],res);
                add(dd[t].c,res);
            }
            swap(c[dd[t].x],dd[t].c);
            t++;
        }
        while(t>tt){
            t--;
            if(dd[t].x<=r&&dd[t].x>=l){
                del(c[dd[t].x],res);
                add(dd[t].c,res);
            }
            swap(c[dd[t].x],dd[t].c);
        }
        ans[id]=res;
    }
    for(int i=0;i<cq;i++)printf("%d\n",ans[i]);
    return 0;
}