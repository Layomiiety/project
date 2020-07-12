//acw361
#include <bits/stdc++.h>
using namespace std;
const int N=1005,M=5005;
int f[N],nex[M],h[M],w[M],to[M],cnt=1,n,m,a,b,c,cc[N];
bool st[N];
double dist[N];
inline void add(int a,int b,int c){to[cnt]=b,w[cnt]=c,nex[cnt]=h[a],h[a]=cnt++;}
inline bool spfa(double x){
    memset(cc,0,sizeof cc);
    queue<int> q;
    for(int i=1;i<=n;i++){q.push(i),st[i]=true;}
    while(!q.empty()){
        int nn=q.front();
        q.pop();
        st[nn]=false;
        for(int i=h[nn];i;i=nex[i]){
            int j=to[i];
            if(dist[j]<dist[nn]+f[nn]-x*w[i]){
                dist[j]=dist[nn]+f[nn]-x*w[i];
                cc[j]=cc[nn]+1;
                if(cc[j]>=n)return true;
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
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    double ll=1,rr=1000;
    while(rr-ll>1e-4){
        double mid=(ll+rr)/2;
        if(spfa(mid))ll=mid;
        else rr=mid;
    }
    printf("%.2lf",ll);
    return 0;
}