//acw1144
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int>pii;
const int N=1e3+5,M=2e6;
int n,m,x1,x2,y1,y2,res=0;
pii fa[N][N];
struct edge{
    int n,m,w;
}e[M];
inline pii ff(pii x){return x==fa[x.first][x.second]?x:fa[x.first][x.second]=ff(fa[x.first][x.second]);}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)fa[i][j]={i,j};
    }
    while(cin>>x1>>y1>>x2>>y2){
        pii n1=ff({x1,y1}),n2=ff({x2,y2});
        if(n1!=n2)fa[n1.first][n1.second]=n2;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<=n;j++){
            pii n1=ff({i,j}),n2=ff({i+1,j});
            if(n1!=n2){fa[n1.first][n1.second]=n2,res++;}
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<n;j++){
            pii n1=ff({i,j}),n2=ff({i,j+1});
            if(n1!=n2){fa[n1.first][n1.second]=n2,res+=2;}
        }
    }
    printf("%d",res);
    return 0;
} 