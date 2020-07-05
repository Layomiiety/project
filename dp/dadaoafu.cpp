#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
inline int read() {
    char ch=getchar();
    register int x=0;
    int f=1;
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
int n,a[100005],dp[2][3];
int main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    dp[0][1]=dp[0][0]=-0x3f3f3f3f;
    dp[0][2]=0;
    for(int i=1;i<=n;i++){
        int I=i%2,J=(i-1)%2;
        dp[I][0]=max(dp[J][0],dp[J][2]-a[i]);
        dp[I][2]=max(dp[J][1],dp[J][2]);
        dp[I][1]=dp[J][0]+a[i];
        }
    printf("%d",max(dp[n%2][1],dp[n%2][2]));
    return 0;
}
