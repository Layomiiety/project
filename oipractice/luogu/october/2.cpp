#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define il inline
typedef pair<int,int> pii;
const int N=1e5+5;
int n,m,c,res[N],mxc=0;
LL v;
pii pc[N][N],pd[N][N],sc[N],sd[N];
bool cmp(pii a,pii b){return a.first>b.first;}
int main(){
    scanf("%d%d%d%lld",&n,&m,&c,&v);
    int a,b;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        pd[a][sd[a]++]={b,i};
        }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        pc[a][sc[a]++]={b,i};
        mxc=max(a,mxc);
        }
    for(int i=1;i<=mxc;i++){
        sort(pc[i],pc[i]+sc[i]+1,cmp);
        sort(pd[i]+1,pd[i]+sd[i]+1,cmp);
        if(sc[i]>sd[i]}{
            int p=sc[i]-sd[i];
            for(int j=0;j<p;j++){
                pii x=pc[i][j];
                res[x.second]=-1;
                v-=(LL)c;
            }
            for(int j=p,k1=0,k2=sd[i]-1;j<sc[i];j++){
                pii x=pc[i][j],y1=pd[i][k1],y2=pd[i][k2];
                if(y1.first>=x.first){
                    res[x.second]=y1.second;
                    v+=(LL)c+y1.first;
                    k1++;
                }
                else {
                    res[x.second]=y2.second;
                    v-=(LL)c-y2.first;
                    k2--;
                }
            }
        }
        else {
            for(int j=0,k1=0,k2=sc[i];j<sc[i];j++){
                pii x=pc[i][j],y1=pd[i][k1],y2=pd[i][k2];
                if(y1.first>=x.first){
                    res[x.second]=y1.second;
                    v+=(LL)c+y1.first;
                    k1++;
                }
                else {
                    res[x.second]=y2.second;
                    v-=(LL)c-y2.first;
                    k2--;
                }
            }
        }
    }
    printf("%lld\n",v);
    for(int i=1;i<=m;i++)printf("%d\n",res[i]);
}