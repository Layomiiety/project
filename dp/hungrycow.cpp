#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=3e6+5;
int n,dp[maxn];
ll lb=maxn,rb=0,x,y;
vector<int>pos[maxn];
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
    n=read();
    for(int i=0;i<n;i++){
        x=read(),y=read();
        rb=max(rb,y),lb=min(lb,x);
        pos[y].push_back(y-x+1);
    }
    for(ll i=lb;i<=rb;i++){
        dp[i]=dp[i-1];
        for(int j=0;j<pos[i].size();j++){
            dp[i]=max(dp[i],dp[i-pos[i][j]]+pos[i][j]);
        }
    }
    printf("%d",dp[rb]);
    return 0;
}