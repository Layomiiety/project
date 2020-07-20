//acw257
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
const int N=20005,M=200005;
int h[N],nex[M],to[M],w[M],n,m,cnt=1,color[N];
il void add(int a,int b,int c){
    to[cnt]=b,nex[cnt]=h[a],w[cnt]=c,h[a]=cnt++;
}
il bool check(int x){
    queue<int>q;
    //for(int i=1;i<=n;i++)printf("%d ",color[i]);
    //printf("\n%d\n",x);
    memset(color,0,sizeof color);
    for(int i=1;i<=n;i++){
        if(color[i])continue;
        color[i]=1;
        q.push(i);
        while(!q.empty()){
            int hh=q.front();
            q.pop();
            for(int j=h[hh];j;j=nex[j]){
                int k=to[j];
                if(w[j]<=x)continue;
                if(color[k]){
                    if(color[k]==color[hh]){
                        //printf("%d %d\n",k,hh);
                        return false;
                    }
                }
                else {
                    color[k]=3-color[hh];
                    q.push(k);
                    }
            }
        }
    }
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    int l=0,r=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c),add(b,a,c);
        r=max(r,c);
    }
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    printf("%d",r);
}