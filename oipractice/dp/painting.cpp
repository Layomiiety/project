#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,t,v[51][51][2505],red[51][51],blue[51][51],tot[51][2505];
char cur[51];
inline int read() {
    char ch=getchar();
    int x=0,f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main(){
    n=read(),m=read(),t=read();
    for(int i=1;i<=n;i++){
        cin>>cur;
        for(int j=1;j<=m;j++){
            red[i][j]=red[i][j-1],blue[i][j]=blue[i][j-1];
            if(cur[j-1]=='0')red[i][j]++;
            else blue[i][j]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=t;k++){
                v[i][j][k]=v[i][j][k-1];
                for(int l=k-1;l<j;l++){
                    v[i][j][k]=max(v[i][j][k],v[i][l][k-1]+max(red[i][j]-red[i][l],blue[i][j]-blue[i][l]));
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++)
            for(int k=0;k<=min(m,j);k++){
                tot[i][j]=max(tot[i][j],tot[i-1][j-k]+v[i][m][k]);
            }
    }
    printf("%d",tot[n][t]);
    return 0;
}
