//acw904
#include <bits/stdc++.h>
using namespace std;
const int N=505,M=5210;
int F,h[M],nex[M],w[M],to[M],cnt=1,cc[N],n,m,ww,a,b,c,dist[N];
bool st[N];
inline void add(int a,int b,int c){
    to[cnt]=b,w[cnt]=c,nex[cnt]=h[a],h[a]=cnt++;
}
inline bool spfa(){
    memset(dist,0,sizeof dist);
    memset(cc,0,sizeof cc);
    queue <int> q;
    for(int i=1;i<=n;i++){q.push(i);st[i]=true;}
    while(!q.empty()){
        int nn=q.front();
        q.pop();
        st[nn]=false;
        for(int i=h[nn];i;i=nex[i]){
            int j=to[i];
            if(dist[j]>dist[nn]+w[i]){
                dist[j]=dist[nn]+w[i];
                cc[j]=cc[nn]+1;
                if(cc[j]>n)return true;
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    return false;
}
int main(){
    scanf("%d",&F);
    while(F--){
        memset(h,0,sizeof h);
        cnt=1;
        scanf("%d%d%d",&n,&m,&ww);
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        for(int i=1;i<=ww;i++){
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,-c);
        }
        if(spfa())printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}