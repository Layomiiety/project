#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
const ull mod=87178291199;
const ull base=67;
char s[2000];
ull a[10010];
int n,cnt=1;
ull hashe(char c[]){
    int ln=strlen(c);
    ull ans=0;
    for(re int i=0;i<ln;i++)ans=(ans+(ull)c[i])*base%mod;
    return ans;
}
int main(){
    scanf("%d",&n);
    for(re int i=1;i<=n;i++){
        scanf("%s",&s);
        a[i]=hashe(s);
        //printf("%lld\n",a[i]);
        }
    sort(a+1,a+n+1);
    for(re int i=2;i<=n;i++)if(a[i]!=a[i-1])cnt++;
    printf("%d",cnt);
    return 0;
}