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
inline void write(int a)    
{
    if(a>9)
        write(a/10);
    putchar(a%10+'0');
}
const int mxn=1e5+5;
int head[mxn],dis[mxn],n,m,cnt,s;
bool vis[mxn];
struct edge{
    int to,next,val;
}e[mxn<<1];
typedef pair<int,int>pi;
priority_queue<pi,vector<pi>,greater<pi> > q;
il void add(int i,int j, int v){
    e[++cnt].to=j;
    e[cnt].val=v;
    e[cnt].next=head[i];
    head[i]=cnt;
}
il void dijkstra(){
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        pi np=q.top();
        q.pop();
        if(vis[np.second])continue;
        vis[np.second]=true;
        for(int i=head[np.second];i;i=e[i].next){
            if(!vis[e[i].to]&&dis[e[i].to]>e[i].val+np.first){
                dis[e[i].to]=e[i].val+np.first;
                q.push(make_pair(dis[e[i].to],e[i].to));
            }
        }
    }
}
int main(){
    n=read(),m=read(),s=read();
    for(re int i=1,x,y,z;i<=m;i++){
        x=read(),y=read(),z=read();
        add(x,y,z);
    }
    dijkstra();
    for(re int i=1;i<=n;i++){
        write(dis[i]);
        printf(" ");
    }
    return 0;
}