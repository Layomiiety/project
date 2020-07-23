//acw237
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
#define il inline 
#define LL long long
const int M=1e6+6,N=2*M;
unordered_map<int,int> mm;
int fa[N],n,t,q[M][2],cnt;
il int ff(int x){return x==fa[x]?x:fa[x]=ff(fa[x]);}
il bool solve(){
    scanf("%d",&n);
    for(int i=1;i<N;i++)fa[i]=i;
    mm.clear();
    cnt=0;
    int cc=0;
    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(!mm.count(a))mm[a]=++cnt;
        if(!mm.count(b))mm[b]=++cnt;
        if(c)fa[ff(mm[a])]=ff(mm[b]);
        else{
            q[cc][0]=mm[a],q[cc++][1]=mm[b];
            }        
        }
    for(int i=0;i<cc;i++){
        int a=ff(q[i][0]),b=ff(q[i][1]);
        if(a==b)return false;
    }
    return true;
}
int main(){
    scanf("%d",&t);
    while(t--){
       if(solve())puts("YES");
       else puts("NO");
       }
    return 0;
}