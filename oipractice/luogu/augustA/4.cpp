#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define LL long long
#define il inline
const int N=5e5+5,M=N<<1;
int n,m,a[N],d[N];
int h[N],to[M],nex[M],idx,ans=0;
bool vis[N];
int e[10][10],v[10],mm[10][2];
il void dfs(int x,int sum){
    if(x==n-1){
        if(sum<=ans)return;
        for(int i=1;i<n;i++){
            for(int j=1;j<=e[i][0];j++)e[i][j]=v[e[i][j]];
            sort(e[i]+1,e[i]+e[i][0]+1);
            if(e[i][d[i]/2+1]>a[i])return;
        }
        ans=max(ans,sum);
        return;
    }
    v[x]=m;
    dfs(x+1,sum+m);
    v[x]=max(a[mm[x][0]],a[mm[x][1]]);
    dfs(x+1,sum+v[x]);
    v[x]=min(a[mm[x][0]],a[mm[x][1]]);
    dfs(x+1,sum+v[x]);
    return;
}
il void add(int u,int v){to[idx]=v,nex[idx]=h[u],h[u]=idx++;}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    memset(h,-1,sizeof h);
    if(n<=8){
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            mm[idx][0]=u,mm[idx][1]=v;
            e[u][++e[u][0]]=idx;
            e[u][++e[u][0]]=idx++;
            d[u]++,d[v]++;
        }
        dfs(0,0);
        printf("%d",ans);
        return 0;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
        d[u]++,d[v]++;
    }
    if(m==1){
        printf("%d",n-1);
    }
    else {
        bool c4=false;
        int r=0;
        for(int i=1;i<=n;i++){
            if(d[i]==1)r=i;
            if(d[i]==n-1){
                c4=true;
                r=i;
                break;
            }
        }
        if(c4){
            LL ans=0;
            int k=(n-1)/2+1;
            vector <int> big;
            for(int i=1;i<=n;i++){
                if(i==r)continue;
                if(a[i]<=a[r]){
                    ans+=(LL)a[i];
                    k--;
                }
                else {
                    big.push_back(a[i]);
                }
            }
            sort(big.begin(),big.end());
            for(int i=0;i<big.size();i++){
                if(k>0){
                    ans+=(LL)a[r];
                    k--;
                }
                else ans+=big[i];
            }
            printf("%lld",ans);
        }
        else {
            LL ans=0;
            int cur=1;
            while(cur++){
                int ne=0;
                vis[r]=true;
                for(int i=h[r];~i;i=nex[i]){
                    int j=to[i];
                    if(vis[j])continue;
                    ne=j;
                    ans+=min(a[r],a[j]);
                }
                if(!ne)break;
                r=ne;
            }
            printf("%lld",ans);
        }
    }
}
