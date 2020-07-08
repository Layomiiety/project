#include <bits/stdc++.h>
using namespace std;
#define ll long long
int m,t,rd=0,sd=0;
ll s;
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
    m=read(),s=read(),t=read();
    for(int i=1;i<=t;i++){
        rd+=17;
        if(m>=10)m-=10,sd+=60;
        else m+=4;
        rd=max(sd,rd);
        if (rd>=s){printf("Yes\n%d",i);return 0;}
    }
    printf("No\n%d",rd);
    return 0;
}