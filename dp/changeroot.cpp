#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
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

inline void write(int x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
struct node{
    int val,cnt;
    double exp,re;
    vector<int> nex;
}g[500005];

int cn,n,u,v,root;
bool le[500005];
double ans=~0x3f;
void work(int i,int p){
    for(int j:g[i].nex){
        if(j==p)continue;
        work(j,i);
        g[i].cnt+=g[j].cnt;
        g[i].exp+=g[j].exp;
    }
    g[i].exp+=g[i].cnt*g[i].val;
    if(!g[i].cnt)le[i]=1,g[i].cnt=1,g[i].exp=g[i].val;
    return;
}
void changeroot(int i,int p){
    for(int j:g[i].nex){
        if(j==p)continue;
        if(le[j])g[j].re=g[i].re-g[i].val+(cn-2)*g[j].val;
        else g[j].re=g[i].re-g[i].val*g[j].cnt+(cn-g[j].cnt)*g[j].val;
        changeroot(j,i);
    }
}
signed main(){
    n=read();
    for(int i=1;i<n;i++)u=read(),v=read(),g[u].nex.push_back(v),g[v].nex.push_back(u);
    for(int i=1;i<=n;i++)g[i].val=read();
    for(int i=1;i<=n;i++)if(g[i].nex.size()!=1){root=i;break;}
    work(root,0);
    cn=g[root].cnt;
    g[root].re=g[root].exp;
    ans=g[root].re/cn;
    changeroot(root,0);
    for(int i=1;i<=n;i++)ans=max(ans,g[i].re/(cn-le[i]));
    printf("%.4lf",ans);
    return 0;
}

