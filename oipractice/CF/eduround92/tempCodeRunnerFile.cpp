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
const int N=1005;
int T,n,k,a1,a2,b1,b2;
il void solve(){
    n=read(),k=read();
    a1=read(),a2=read(),b1=read(),b2=read();
    if(a1>b1||(a1==b1&&a2>b2)){swap(a1,b1),swap(a2,b2);}
    if(b2<=a2){
        int eve=a2-a1,ov=b2-b1,ex=eve-ov;
        if(ov*n>=k)printf("0\n");
        else if(eve*n>=k){
            int l=k-ov*n;
            printf("%d\n",l);
            }
        else {
            int ans=ex*n;
            printf("%d\n",(k-eve*n)*2+ans);
        }
    }
    else if(b1<=a2){
        int eve=b2-a1,ov=a2-b1,ex=eve-ov;
        if(ov*n>=k)printf("0\n");
        else if(eve*n>=k){
            int l=k-ov*n;
            printf("%d\n",l);
            }
        else {
            int ans=ex*n;
            printf("%d\n",(k-eve*n)*2+ans);
        }
    }
    else {
        int eve=b2-a1,ov=b1-a2,ex=2*eve-(a2+b2-a1-b1);
        if(eve*n>=k){
            printf("%d\n",k/eve*ex+k%eve+ov);
            }
        else {
            int ans=ex*n;
            printf("%d\n",(k-eve*n)*2+ans);
        }
    }
}
int main(){
    T=read();
    while(T--){
        solve();
    }
    return 0;
}