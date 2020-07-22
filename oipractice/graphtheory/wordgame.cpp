//acw1185
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
const int N=30,M=1010;
int din[N],dout[N],cnt;
int t,n,g[N][N];
char ww[M];
il void dfs(int x){
    for(int i=0;i<26;i++){
        if(!g[x][i])continue;
        cnt++;
        g[x][i]--;
        dfs(i);
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        memset(din,0,sizeof din);
        memset(dout,0,sizeof dout);
        memset(g,0,sizeof g);
        cnt=0;
        for(int i=0;i<n;i++){
            cin>>ww;
            int l=strlen(ww);
            int e=ww[l-1]-'a',s=ww[0]-'a';
            din[e]++,dout[s]++;
            g[s][e]++;
        }
        int st=0,en=0;
        bool ss=true;
        for(int i=0;i<26;i++){
            if(din[i]!=dout[i]){
                if(din[i]==dout[i]+1){
                    if(en){ss=false;break;}
                    en=i;
                }
                else if(din[i]==dout[i]-1){
                    if(st){ss=false;break;}
                    st=i;
                }
                else {ss=false;break;}
            }
        }
        if(ss){
            while(!dout[st])st++;
            dfs(st);
            }
        if(cnt==n)puts("Ordering is possible.");
        else puts("The door cannot be opened.");
    }
    return 0;
}