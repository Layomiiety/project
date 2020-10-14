//acw2523
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,m,w[N],cnt[N],len;
ll ans[N];
struct query{
    int id,l,r;
}q[N];
vector <int> ma;
inline int get(int x){return x/len;}
bool cmp(query a,query b){
    if(get(a.l)==get(b.l))return a.r<b.r;
    return a.l<b.l; 
}
void add(int x,ll &res){
    cnt[x]++;
    res=max(res,(ll)cnt[x]*ma[x]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        ma.push_back(w[i]);
    }
    len=sqrt(n);
    sort(ma.begin(),ma.end());
    ma.erase(unique(ma.begin(),ma.end()),ma.end());
    for(int i=1;i<=n;i++)w[i]=lower_bound(ma.begin(),ma.end(),w[i])-ma.begin();
    for(int i=0;i<m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        q[i]={i,l,r};
        }
    sort(q,q+m,cmp);
    for(int i=0,j;i<m;){
        while(get(q[i].l)==get(q[j].l))j++;
        int rb=get(q[i].l)*len+len-1;
        ll res=0;
        while(i<j&&q[i].r<=rb){
            res=0;
            int l=q[i].l,r=q[i].r,id=q[i].id;
            for(int k=l;k<=r;k++)add(w[k],res);
            ans[id]=res;
            for(int k=l;k<=r;k++)cnt[w[k]]--;
            i++;
        }
        int x=rb,y=rb+1;
        res=0;
        while(i<j){
            int l=q[i].l,r=q[i].r,id=q[i].id;
            while(x<r)add(w[++x],res);
            ll bc=res;
            while(y>l)add(w[--y],res);
            ans[id]=res;
            while(y<rb+1)cnt[w[y++]]--;
            res=bc;
            i++;
        }
        memset(cnt,0,sizeof cnt);
    }
    for(int i=0;i<m;i++)printf("%lld\n",ans[i]);
    return 0;
}