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
const int N=8005,M=20000;
int st[N],n,h[N],to[M],nex[M],cnt,match[N];
il void add(int a,int b){to[cnt]=b,nex[cnt]=h[a],h[a]=cnt++;}
il bool find(int x){
    for(int i=h[x];~i;i=nex[i]){
        int j=to[i];
        if(st[j])continue;
        st[j]=true;
        if(!match[j]||find(match[j])){
            match[j]=x;
            return true;
        }
    }
    return false;
}
int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n*2;i++){
        int s1,s2;
        cin>>s1>>s2;
        add(i,2*(n+s1));
        add(i,2*(n+s2));
        add(i,2*(n+s2)+1);
        add(i,2*(n+s1)+1);
        }
    int ans=0;
    for(int i=1;i<=2*n;i++){
        memset(st,0,sizeof st);
        if(find(i))ans++;
    }
    cout<<ans;
    return 0;
}