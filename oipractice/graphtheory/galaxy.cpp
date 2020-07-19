//acw368
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#define il inline
#define ll long long
using namespace std;
const int N=1e5+5,M=2e5+5;
int h[N],nex[M],w[M],to[M],cnt=1,n,m,dist[N],cc[N];
il void add(int a,int b ,int c){to[cnt]=b,w[cnt]=c,nex[cnt]=h[a],h[a]=cnt++;}
bool dijkstra(){
    memset(dist,-0x3f,sizeof dist);
    priority_queue<int> q;
    bool st[N];
    dist[0]=0;
    q.push(0);
    int tcc=0;
    while(!q.empty()){
        tcc++;
        if(tcc>N<<4)return false;
        int hh=q.top();
        q.pop();
        st[hh]=false;
        for(int i=h[hh];i;i=nex[i]){
            int j=to[i];
            if(dist[j]<dist[hh]+w[i]){
                dist[j]=dist[hh]+w[i];
                cc[j]=cc[hh]+1;
                if(cc[j]>n)return false;
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
        return true;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)add(0,i,1);
    for(int i=0;i<m;i++){
        int a,b,t;
        scanf("%d%d%d",&t,&a,&b);
        switch(t){
            case 1: 
                add(a,b,0),add(b,a,0);
                break;
            case 2:
                add(a,b,1);
                break;
            case 3:
                add(b,a,0);
                break;
            case 4:
                add(b,a,1);
                break;
            case 5:
                add(a,b,0);
                break;
        }
    }
    ll ans=0;
    if(!dijkstra())ans=-1;
    else {
        for(int i=1;i<=n;i++){
            ans+=(ll)dist[i];
        }
    }
    printf("%lld",ans);
    return 0;
}
