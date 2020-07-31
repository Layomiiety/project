//acw1282
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
const int N=1e4+5,M=1e6+5;
int tr[N*55][26],nex[N*55],cnt[N*55],idx;
int q[N*55];
char str[60],ss[M];
int n,m,t;
il void insert(){
    int p=0;
    for(int i=0;str[i];i++){
        int x=str[i]-'a';
        if(!tr[p][x])tr[p][x]=++idx;
        p=tr[p][x];
    }
    cnt[p]++;
}
il void build(){
    int hh=0,tt=-1;
    for(int i=0;i<26;i++){
        if(tr[0][i])q[++tt]=tr[0][i];
    }
    while(hh<=tt){
        int t=q[hh++];
        for(int i=0;i<26;i++){
            if(!tr[t][i])continue;
            int j=nex[t],c=tr[t][i];
            while(j&&!tr[j][i])j=nex[j];
            if(tr[j][i])j=tr[j][i];
            nex[c]=j;
            q[++tt]=c;
        }
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        memset(tr,0,sizeof tr);
        memset(nex,0,sizeof nex);
        memset(cnt,0,sizeof cnt);
        idx=0;
        scanf("%d",&n);
        while(n--){
            scanf("%s",str);
            insert();
        }
        build();
        scanf("%s",ss);
        int res=0;
        for(int i=0,j=0;ss[i];i++){
            int x=ss[i]-'a';
            while(j&&!tr[j][x])j=nex[j];
            if(tr[j][x])j=tr[j][x];
            int t=j;
            while(t){
                res+=cnt[t];
                cnt[t]=0;
                t=nex[t];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}