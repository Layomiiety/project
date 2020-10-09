//acw2492
#include <bits/stdc++.h>
using namespace std;
const int N=5e4+5,M=2e5+5,S=1e6+5;
int n,m,len;
struct query{
    int id,l,r;
}q[M];
int a[N],cnt[S],res[M];
inline int get(int x){return x/len;}
bool cmp(query a,query b){
    if(get(a.l)==get(b.l))return a.r<b.r;
    return a.l<b.l;
}
inline void add(int p,int& ans){
    if(!cnt[a[p]])ans++;
    cnt[a[p]]++;
}
inline void del(int p,int& ans){
    cnt[a[p]]--;
    if(!cnt[a[p]])ans--;
}
int main(){
    scanf("%d",&n);
    len=sqrt(n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        q[i]={i,l,r};
    }
    sort(q,q+m,cmp);
    for(int i=0,j=1,k=0,ans=0;k<m;k++){
        int id=q[k].id,l=q[k].l,r=q[k].r;
        while(i<r)add(++i,ans);
        while(i>r)del(i--,ans);
        while(j<l)del(j++,ans);
        while(j>l)add(--j,ans);
        res[id]=ans;
    }
    for(int i=0;i<m;i++)printf("%d\n",res[i]);
    return 0;
}