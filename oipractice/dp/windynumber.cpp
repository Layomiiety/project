#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
inline ll read() {
    char ch=getchar();
    register ll x=0;
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
inline void write(ull a)    
{
    if(a>9)
        write(a/10);
    putchar(a%10+'0');
}
int num[15];
ull f[15][10][2][2];
il ull dp(bool eq,bool zero,int dep,int pre){
    if(!dep)return (ull)1;
    if(f[dep][pre][eq][zero])return f[dep][pre][eq][zero];
    int r=eq?num[dep]:9;
    ull ans=0;
    for(int i=0;i<=r;i++){
        if(zero||abs(i-pre)>1){
            ans+=dp(eq&&(i==r),zero&&(i==0),dep-1,i);
            //printf("%d %d %d\n",ans,pre,dep);
            }
        }
    return f[dep][pre][eq][zero]=ans;
}
il ull windy(ull x){
    memset(f,0,sizeof(f));
    num[0]=0;
    for(;x;x/=10)num[++num[0]]=x%10;
    return dp(true,true,num[0],0);
} 
int main(){
    ull a=read(),b=read();
    write(windy(b)-windy(a-1));
    return 0;
}