#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
const int N=1005,M=3e4+5;
int n,a,b,c,h[N],nex[M],to[M],w[M],cnt=1,cc[N],md,ml;
ll s[N];
inline void add(int a,int b,int c){w[cnt]=c,to[cnt]=b,nex[cnt]=h[a],h[a]=cnt++;}
bool spfa(){
    memset(s,0x3f,sizeof s);
    s[1]=0;
    queue<int> q;
    bool st[N];
    for(int i=0;i<=n;i++)q.push(i);
    while(!q.empty()){
        int hh=q.front();
        q.pop();
        st[hh]=false;
        for(int i=h[hh];i;i=nex[i]){
            int j=to[i];
            if(s[j]>s[hh]+w[i]){
                cc[j]=cc[hh]+1;
                if(cc[j]>=n)return false;
                s[j]=s[hh]+w[i];
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
                
            }
        }    
    }
    return true;
}
int main(){
    cin>>n>>ml>>md;
    for(int i=1;i<n;i++){
        add(i+1,i,0);
    }
    for(int i=0;i<ml;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(a>b)swap(a,b);
        add(a,b,c);
    }
    for(int i=0;i<md;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(a>b)swap(a,b);
        add(b,a,-c);
    }
    if(!spfa())printf("-1");
    else if(s[n]>0x3f3f3f3f/2)printf("-2");
    else printf("%lld",s[n]);
    return 0;
} 