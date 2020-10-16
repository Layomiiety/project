//p2483
#include <bits/stdc++.h>
using namespace std;
const int N=5005,M=2e5+5;
typedef pair<double,int>pii;
typedef pair<double,pii>ppi;
int n,m;
int hs[N],tos[M],nes[M],ht[N],tot[M],net[M],idx,cc[N];
double dis[N],w[M],e;
bool st[N];
inline void add(int a,int b,double c){
    tos[idx]=b,nes[idx]=hs[a],w[idx]=c,hs[a]=idx;
    tot[idx]=a,net[idx]=ht[b],ht[b]=idx++;
}
void dijkstra(){
    memset(st,0,sizeof st);
    priority_queue<pii,vector<pii>,greater<pii> >q;
    q.push({0,n});
    dis[n]=0;
    while(!q.empty()){
        pii x=q.top();
        q.pop();
        double d=x.first;
        int id=x.second;
        if(st[id])continue;
        st[id]=true;
        for(int i=ht[id];~i;i=net[i]){
            int j=tot[i];
            if(dis[j]>w[i]+d){
                dis[j]=w[i]+d;
                q.push({dis[j],j});
            }
        }
    }
}
int bfs(int mm){
    priority_queue<ppi,vector<ppi>,greater<ppi> >q;
    q.push({dis[1],{0,1}});
    while(!q.empty()){
        ppi x=q.top();
        q.pop();
        int id=x.second.second;
        double d=x.second.first,aa=x.first;
        if(aa>e)break;
        if(id==n){
            e-=d;
            if(e<=0)break;
        }
        cc[id]++;
        if(cc[id]>mm)continue;
        for(int i=hs[id];~i;i=nes[i])q.push({dis[tos[i]]+w[i]+d,{w[i]+d,tos[i]}});
        }
    return cc[n];
}
int main(){
    scanf("%d%d%lf",&n,&m,&e);
    memset(hs,-1,sizeof hs);
    memset(ht,-1,sizeof ht);
    for(int i=1;i<=n;i++)dis[i]=0x3f3f3f3f;
    while(m--){
        int a,b;
        double c;
        scanf("%d%d%lf",&a,&b,&c);
        add(a,b,c);
    }
    dijkstra();
    printf("%d",bfs(floor(e/dis[1])));
}