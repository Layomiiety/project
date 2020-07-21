//p1772
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
const int N=25,M=420;
int dist[N][N],h[N],nex[M],to[M],w[M],cnt=1;
bool ava[105][N];
int n,m,k,e,d;
il void add(int a,int b,int c){to[cnt]=b,w[cnt]=c,nex[cnt]=h[a],h[a]=cnt++;}
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&e);
    for(int i=1;i<=e;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c),add(b,a,c);
    }
    cin>>d;
    for(int i=1;i<=d;i++){
        int p,a,b;
        scanf("%d%d%d",&p,&a,&b);
        
    }
}