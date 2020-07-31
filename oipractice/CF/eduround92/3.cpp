#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <cmath>
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
const int N=2e5+5;
int T;
char s[N];
int cnt[10],ss[N],fo[10];
il void solve(){
    memset(cnt,0,sizeof cnt);
    scanf("%s",s);
    int l=strlen(s);
    for(int i=0;i<l;i++){
        ss[i]=s[i]-'0';
        if(!cnt[ss[i]])fo[ss[i]]=i;
        cnt[ss[i]]++;
    }
    int ans=0;
    for(int i=0;i<10;i++)ans=max(cnt[i],ans);
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(2*min(cnt[i],cnt[j])<ans)continue;
            int cur,pp=1,st;
            if(fo[i]>fo[j]){st=fo[j],cur=i;}
            else {st=fo[i],cur=j;}
            while(st<l){
                if(ss[st]==cur){
                    pp++;
                    cur=cur==i?j:i;
                    }
                st++;
            }
            ans=max(ans,2*(pp/2));
        }
    }
    printf("%d\n",l-ans);
}
int main(){
    T=read();
    while(T--){
        solve();
    }
    return 0;
}