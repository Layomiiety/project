//acw1250
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
const int N=205,M=N*N;
int n,m,fa[M];
il int ff(int x){return x==fa[x]?x:fa[x]=ff(fa[x]);}
il int get(int x,int y){return x*n+y;}
int main(){
    cin>>n>>m;
    for(int i=n+1;i<=n*n+n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int a,b,st,en;
        char op;
        cin>>a>>b>>op;
        st=get(a,b);
        if(op=='D'){
            en=get(a+1,b);
        }
        else {
            en=get(a,b+1);
        }
        st=ff(st),en=ff(en);
        if(st==en){
                cout<<i<<endl;
                return 0;
            }
        else fa[st]=en;
    }
    puts("draw");
    return 0;
}