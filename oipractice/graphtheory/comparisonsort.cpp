#include <bits/stdc++.h>
using namespace std;
char st[5];
int adj[26][26],n,m,x,y,cnt[26],a[1000],b[1000];
string getstr(){
    string res;
    for(int i=0;i<n;i++)res+=('A'+cnt[i]);
    return res;
}
string solve(){
    memset(adj,0,sizeof adj);
    for(int i=1;i<=m;i++){
        cin>>st;
        a[i]=st[0]-'A',b[i]=st[2]-'A';
    }
    for(int i=1;i<=m;i++){
        x=a[i],y=b[i];
        if(adj[y][x]) return "Inconsistency found after "+to_string(i)+" relations.";
        adj[x][y]=1;
        //printf("%d %d %d\n",x,y,adj[x][y]);
        for(int j=0;j<n;j++){
            if(adj[j][x]){
                if(adj[y][j]) return "Inconsistency found after "+to_string(i)+" relations.";
                else adj[j][y]=1; 
            }
            if(adj[y][j]){
                if(adj[j][x]) return "Inconsistency found after "+to_string(i)+" relations.";
                else adj[x][j]=1;
            }
        }
        int cc=0;
        for(int i=0;i<n;i++){
            int ccc=0;
            for(int j=0;j<n;j++)if(adj[j][i]){ccc++;cc++;}
            cnt[ccc]=i;
        }
        if(cc==n*(n-1)/2)return "Sorted sequence determined after "+to_string(i)+" relations: "+getstr()+"."; 
    }
    return "Sorted sequence cannot be determined.";
}
int main(){
    while(cin>>n>>m,n||m){
        cout<<solve()<<"\n";
    }
    return 0;
}