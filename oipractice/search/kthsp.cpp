#include <bits/stdc++.h>
using namespace std;
#define il inline
#define re register
typedef pair<int,int>pii;
typedef pair<int,pii>piii;
const int N=1005,M=200005;
int n,m,sta,en,k,head[M],nex[M],to[M],w[M],cnt=1,dist[N],bh[M];
bool vis[N];
il void add(int h[],int a,int b,int c){
    to[cnt]=b,w[cnt]=c,nex[cnt]=h[a],h[a]=cnt++;
    return;
}
il void dijksta(){
    memset(dist,0x3f,sizeof dist);
    dist[en]=0;
    priority_queue <pii,vector<pii>,greater<pii>> q; 
    q.push({0,en});
    while(!q.empty()){
        pii node=q.top();
        q.pop();
        if(vis[node.second])continue;
        vis[node.second]=true;
        for(int i=bh[node.second];i;i=nex[i]){
            if(dist[to[i]]>node.first+w[i]){
                dist[to[i]]=node.first+w[i];
                q.push({dist[to[i]],to[i]});
            }
        //printf("%d %d\n",node.first,node.second);
        }
    }
}
il int bfs(){
    int cn=0;
    priority_queue<piii,vector<piii>,greater<piii>>q;
    q.push({dist[sta],{0,sta}});
    while(!q.empty()){
        piii hh=q.top();
        q.pop();
        if(hh.second.second==en)cn++;
        if(cn==k)return hh.second.first;
        for(int i=head[hh.second.second];i;i=nex[i]){
            q.push({dist[to[i]]+w[i]+hh.second.first,{w[i]+hh.second.first,to[i]}});
        }
        //printf("%d %d %d\n",hh.second.second,hh.second.first,hh.first);
    }
    return -1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(re int i=0;i<m;i++){
        int a,b,l;
        scanf("%d%d%d",&a,&b,&l);
        add(head,a,b,l);
        add(bh,b,a,l);
    }
    scanf("%d%d%d",&sta,&en,&k);
    if(sta==en)k++;
    dijksta();
    cout<<bfs();
    return 0;
}