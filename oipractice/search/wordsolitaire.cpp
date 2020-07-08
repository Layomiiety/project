#include <bits/stdc++.h>
using namespace std;
#define il inline
#define re register
int n,d[21][21],ans,use[21];
char st;
string word[21];
il void dfs(string dra,int last){
    use[last]++;
    ans=max(ans,(int)dra.size());
    for(int i=1;i<=n;i++){
        if(d[last][i]&&use[i]<2)dfs(dra+word[i].substr(d[last][i]),i);
    }
    use[last]--;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)cin>>word[i];
    cin>>st;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<min(word[i].size(),word[j].size());k++){
                    if(word[i].substr(word[i].size()-k)==word[j].substr(0,k)){
                        d[i][j]=k;
                        break;
                    }
                }
            }
        }
    for(int i=i;i<=n;i++){
        if(word[i][0]==st)dfs(word[i],i);
    }
    printf("%d",ans);
    return 0;
}
