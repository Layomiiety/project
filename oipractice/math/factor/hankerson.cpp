//acw200
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
typedef long long LL;
typedef pair<int,int>pii;
const int N=45000;
int pr[N>>1],cnt,ans,cc;
pii pb[10];
bool st[N];
int a0,a1,b0,b1,n;
void init(){
    for(int i=2;i<=N;i++){
        if(!st[i])pr[cnt++]=i;
        for(int j=0;j<cnt&&(LL)pr[j]*i<=N;j++){
            st[pr[j]*i]=1;
            if(!(i%pr[j]))break;
        }
    }
    return;
}
il int gcd(int a,int b){return a?gcd(b%a,a):b;}
il int lcm(int a,int b){return a/gcd(a,b)*b;}
il void dfs(int cur,int numb){
    if(cur>cc){
        //printf("%d ",numb);
        if(gcd(a0,numb)==a1&&lcm(b0,numb)==b1)ans++;
        return;
    }
    for(int i=0;i<=pb[cur].second;i++){
        dfs(cur+1,numb);
        numb*=pb[cur].first;
    }
    return;
}
int main(){
    scanf("%d",&n);
    init();
    while(n--){
        scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
        ans=0,cc=0;
        int x=b1;
        for(int i=0;i<cnt;i++){
            if(!(x%pr[i])){
                int c=1;
                x/=pr[i];
                while(!(x%pr[i])){
                    c++;
                    x/=pr[i];
                }
                pb[++cc]={pr[i],c};
            }
        }
        if(x!=1)pb[++cc]={x,1};
        //for(int i=1;i<=cc;i++)printf("%d %d\n",pb[i].first,pb[i].second);
        dfs(1,1);
        printf("%d\n",ans);
    }
    return 0;
}