#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
int n,k,di[100100],q[100100],hh=0,tt=0;
bool vis[100100];
int main(){
    scanf("%d%d",&n,&k);
    if(n>=k){printf("%d",n-k);return 0;}
    vis[n]=1;
    q[0]=n;
    while(hh<=tt){
        int h=q[hh++];
        if(!vis[h+1]&&h+1<k+100){
            di[h+1]=di[h]+1;
            if(h+1==k){printf("%d",di[h+1]);return 0;}
            vis[h+1]=true;
            q[++tt]=h+1;
            //printf("%d %d\n",h+1,di[h+1]);
            }
        if(!vis[h-1]&&h-1>0){
            di[h-1]=di[h]+1;
            if(h-1==k){printf("%d",di[h-1]);return 0;}
            vis[h-1]=true;
            q[++tt]=h-1;
            //printf("%d %d\n",h-1,di[h-1]);
            }
        if(!vis[h*2]&&h*2<k+100){
            di[h*2]=di[h]+1;
            if(h*2==k){printf("%d",di[h*2]);return 0;}
            vis[h*2]=true;
            q[++tt]=h*2;
            //printf("%d %d\n",h*2,di[h*2]);
            }
    }
}

