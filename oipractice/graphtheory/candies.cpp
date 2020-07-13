//acw1169
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
const int N=1e5+10, K=3e5+10,inf=0x3f3f3f3f;
int n,k,x,a,b,h[K],nex[K],to[K],w[K],cnt=1,cc[N];
ll dist[N];
il void add(int aa,int bb,int c){to[cnt]=bb,w[cnt]=c,nex[cnt]=h[aa],h[aa]=cnt++;}
bool spfa(){
    bool st[N];
    memset(dist,-0x3f,sizeof dist);
    int ss[N],hh=0,tt=0;
    dist[0]=0;
    ss[tt++]=0;
    while(hh!=tt){
            int nn=ss[--tt];
            st[nn]=false;
            for(int j=h[nn];j;j=nex[j]){
                int nj=to[j];
                if(dist[nj]<dist[nn]+(ll)w[j]){
                    dist[nj]=dist[nn]+(ll)w[j];
                    cc[nj]=cc[nn]+1;
                    if(cc[nj]>n)return false;
                    if(!st[nj]){
                        st[nj]=true;
                        ss[tt++]=nj;
                    }
                }
            }
        }
    return true;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        scanf("%d%d%d",&x,&a,&b);
        switch(x){
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
    for(int i=1;i<=n;i++)add(0,i,1);
    if(spfa()){
        ll res=0;
        for(int i=1;i<=n;i++){
            res+=dist[i];
        }
        printf("%lld",res);
    }
    else printf("-1");
    return 0;
}