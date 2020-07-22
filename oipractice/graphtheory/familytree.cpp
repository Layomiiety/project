//acw1191;
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
const int N=105,M=N*N;
int n,h[N],nex[M],to[M],son,cnt=1;
int din[N],qq[N],tt;
il void add(int a,int b){to[cnt]=b,nex[cnt]=h[a],h[a]=cnt++;}
void toposort(){
    int hh,tt=-1;
    for(int i=1;i<=n;i++){if(!din[i])qq[++tt]=i;}
    while(hh<=tt){
        int x=qq[hh++];
        for(int i=h[x];i;i=nex[i]){
            int y=to[i];
            if(--din[y]==0){
                qq[++tt]=y;
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        while(cin>>son,son){
            add(i,son);
            din[son]++;
        }
    }
    toposort();
    for(int i=0;i<n;i++)printf("%d ",qq[i]);
    return 0;
}