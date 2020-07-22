//acw456
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
const int N=2005,M=N*N/2;
int n,m,d[N];
int ss[N];
int h[N],to[M],nex[M],w[M],cnt=1;
il void add(int a,int b,int c){to[cnt]=b,w[cnt]=c,nex[cnt]=h[a],h[a]=cnt++;}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        memset(ss,0,sizeof ss);
        int s,st,en;
        int ver=1000+i;
        cin>>s;
        cin>>st;
        ss[st]=true;
        for(int j=1;j<s;j++){
            cin>>en;
            ss[en]=true;
        }
        for(int j=st;j<=en;j++){
            if(ss[j]){
                add(j,ver,0);
                d[ver]++;
                }
            else {add(ver,j,1);d[j]++;}    
        }
    }
    int q[N],tt=-1,hh;
    for(int i=1;i<=n;i++){
        if(!d[i])q[++tt]=i;
    }
    memset(ss,0,sizeof ss);
    while(hh<=tt){
        int x=q[hh++];
        for(int i=h[x];i;i=nex[i]){
            int j=to[i];
            ss[j]=max(ss[j],ss[x]+w[i]);
            if(--d[j]==0)q[++tt]=j;
        }
    }
    printf("%d",ss[q[tt]]+1);
    return 0;
}