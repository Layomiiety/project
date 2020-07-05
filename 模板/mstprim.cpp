#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
inline ll read() {
    char ch=getchar();
    register ll x=0;
    int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int maxn=2e5+5;
int head[5005],n,m,cnt=0,dis[5005],ans=0,l=0;
bool vis[5005];
struct edge{
    int to,next,val;
}e[maxn<<1];
il void add(int u,int v,int w){
    e[++cnt].to=v;
    e[cnt].val=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
typedef pair<int,int>pi;
priority_queue <pi,vector<pi>,greater<pi> >q;
il void prim(){
    dis[1]=0;
    q.push(make_pair(0,1));
    while(!q.empty()&&l<n){
        pi t=q.top();
        q.pop();
        if(vis[t.second])continue;
        l++;
        ans+=t.first;
        vis[t.second]=true;
        for(re int i=head[t.second];i;i=e[i].next){
            if(dis[e[i].to]>e[i].val){
                dis[e[i].to]=e[i].val;
                q.push(make_pair(dis[e[i].to],e[i].to));
            }
        }
    }
}
int main(){
    n=read(),m=read();
    for(int i=1,x,y,z;i<=m;i++){
        x=read(),y=read(),z=read();
        add(x,y,z),add(y,x,z);
    }
    memset(dis,0x3f3f3f3f,sizeof(dis));
    prim();
    if(l!=n)printf("orz");
    else printf("%d",ans);
    return 0;
}