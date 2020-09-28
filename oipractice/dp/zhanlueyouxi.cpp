//acw323
#include <bits/stdc++.h>
using namespace std;
const int N=1505;
int f[N][2],n,s[N][12],p[N];
inline void dfs(int x){
    for(int i=1;i<=s[x][0];i++){
        int son=s[x][i];
        dfs(son);
        f[x][0]+=f[son][1];
        f[x][1]+=min(f[son][0],f[son][1]);
    }
    f[x][1]++;
}
int main(){
    while(cin>>n){
        memset(f,0,sizeof f);
        for(int i=0;i<n;i++)p[i]=-1;
        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d:(%d)",&a,&b);
            s[a][0]=b;
            for(int j=1;j<=s[a][0];j++){
                scanf("%d",&s[a][j]);
                p[s[a][j]]=a;
            }
        }
        for(int i=0;i<n;i++){
            if(p[i]==-1){
                dfs(i);
                printf("%d\n",min(f[i][0],f[i][1]));
                break;
            }
        }
    }
    return 0;
}