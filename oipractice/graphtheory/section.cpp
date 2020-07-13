#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N=5e4+5,M=3*N;
int n,a,b,c,s[N],h[N],nex[M],to[M],w[M],cnt=1,maxx=0;
inline void add(int a,int b,int c){w[cnt]=c,to[cnt]=b,nex[cnt]=h[a],h[a]=cnt++;}
void spfa(){
    memset(s,-0x3f,sizeof s);
    s[0]=0;
    queue<int> q;
    bool st[N];
    q.push(0);
    while(!q.empty()){
        int hh=q.front();
        q.pop();
        st[hh]=false;
        for(int i=h[hh];i;i=nex[i]){
            int j=to[i];
            if(s[j]<s[hh]+w[i]){
                s[j]=s[hh]+w[i];
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
                
            }
        }    
    }
    return;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b+1,c);
        maxx=max(maxx,b+1);
    }
    for(int i=0;i<=maxx;i++){
        add(i,i+1,0);
        add(i+1,i,-1);
    }
    spfa();
    printf("%d",s[maxx]);
    return 0;
} 