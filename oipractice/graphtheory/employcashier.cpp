//acw393
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N=25,M=2000;
int t,n,a[N],b,h[N],nex[M],to[M],w[M],cnt=1,cc[25],s[25],num[25];
bool st[25];
inline void add(int a,int b,int c){w[cnt]=c,to[cnt]=b,nex[cnt]=h[a],h[a]=cnt++;}
inline void build(int c)
{
    memset(h, 0, sizeof h);
    cnt = 1;
    add(0, 24, c), add(24, 0, -c);
    for (int i = 1; i <= 7; i ++ ) add(i + 16, i, a[i] - c);
    for (int i = 8; i <= 24; i ++ ) add(i - 8, i, a[i]);
    for (int i = 1; i <= 24; i ++ )
    {
        add(i, i - 1, -num[i]);
        add(i - 1, i, 0);
    }
}
bool spfa(int s24){
    build(s24);
    memset(s,-0x3f,sizeof s);
    memset(cc,0,sizeof cc);
    s[0]=0;
    queue<int> q;
    memset(st,0,sizeof st);
    q.push(0);
    while(!q.empty()){
        int hh=q.front();
        q.pop();
        st[hh]=false;
        for(int i=h[hh];i;i=nex[i]){
            int j=to[i];
            if(s[j]<s[hh]+w[i]){
                cc[j]=cc[hh]+1;
                if(cc[j]>=25)return false;
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
    cin>>t;
    while(t--){
        memset(num,0,sizeof num);
        for(int i=1;i<=24;i++)cin>>a[i];;
        cin>>n;
        for(int i=1;i<=n;i++){cin>>b;num[b+1]++;}
        int ll=0,rr=n+1;
        while(ll<rr){
            int mid=(ll+rr)>>1;
            if(spfa(mid))rr=mid;
            else ll=mid+1;
        }
        if(rr!=n+1)printf("%d\n",rr);
        else puts("No Solution");
    }
    return 0;
} 