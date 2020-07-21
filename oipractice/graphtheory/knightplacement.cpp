//acw378
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
#define il inline 
#define LL long long
typedef pair<int,int>pii;
const int N=10105,M=100000;
int st[N],n,m,t,g[N];
int match[N];
int h[N],to[M],nex[M],cnt;
int dx[8]={-1,-2,-2,-1,1,2,2,1},dy[8]={-2,-1,1,2,2,1,-1,-2};
il pii fc(int x){return {x/m,x%m};}
il int fm(pii x){return x.second+x.first*m;}
il void add(int a,int b){to[cnt]=b,nex[cnt]=h[a],h[a]=cnt++;}
il bool find(int x){
    for(int i=h[x];~i;i=nex[i]){
        int j=to[i];
        if(st[j])continue;
        st[x]=st[j]=true;
        if(!match[j]||find(match[j])){
            match[x]=j;
            match[j]=x;
            return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>m>>t;
    memset(h,-1,sizeof h);
    for(int i=1;i<=t;i++){
        int a,b;
        cin>>a>>b;
        g[fm({a,b})]=true;
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int mf=fm({i,j});
            if(g[mf])continue;
            for(int k=0;k<8;k++){
                int xx=i+dx[k],yy=j+dy[k],mff=fm({xx,yy});
                if(xx<1||xx>n||yy<1||yy>m||g[mff])continue;
                add(mf,mff);
            }
        }
    }
    int ans=n*m-t;
    for(int i=m+1;i<=n*m+m;i++){
        if(g[i]||match[i])continue;
        memset(st,0,sizeof st);
        if(find(i))ans--;
    }
    cout<<ans;
    return 0;
}
