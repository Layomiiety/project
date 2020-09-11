#include <bits/stdc++.h>
using namespace std;
const int N=1005,M=20005;
int n,m,v,w,s;
int f[2][M],q[M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&v,&w,&s);
        int cur=i%2,pre=1-cur;
        for(int j=0;j<v;j++){
            int hh=0,tt=-1;
            for(int k=j;k<=m;k+=v){
                int nv=f[pre][k]-(k-j)/v*w;
                if(q[hh]<k-s*v)hh++;
                while(hh<=tt&&f[pre][q[tt]]-(q[tt]-j)/v*w<=nv)tt--;
                q[++tt]=k;
                f[cur][k]=f[pre][q[hh]]+(k-q[hh])/v*w;
            }
        }
    }
    printf("%d",f[n%2][m]);
    return 0;
}