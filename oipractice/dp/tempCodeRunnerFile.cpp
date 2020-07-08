#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
const double ep=1e-6;
struct pi{
    double x,y;
}pig[20];
int T,n,m,ans,cnt,nc;
struct para{
    double a,b;
    ull hit;
}par[160],np[160];
il bool cp(para i,para j){
    return i.a==j.a?i.b<j.b:i.a<j.a;
}
il bool cmp(double i,double j){
    if (fabs(i-j)<ep)return true;
    else return false;
}
il void dfs(int num, ull sta){
    if(sta+1==1<<n){
        ans=min(ans,num);
        return;
    }
    int x=0;
    for(re int i=0;i<n;i++){
        if(!(sta&1<<i)){
            x=i;
            break;
        }
    }
    for(re int i=1;i<=nc;i++){
        if(np[i].hit&1<<x)dfs(num+1,sta|np[i].hit);
        }
    return;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)scanf("%lf%lf",&pig[i].x,&pig[i].y);
        cnt=nc=0;
        for(int i=0;i+1<n;i++){
            for(int j=i+1;j<n;j++){
                double x1=pig[i].x,x2=pig[j].x,y1=pig[i].y,y2=pig[j].y;
                if(cmp(x1,x2))continue;
                double na=(y1/x1-y2/x2)/(x1-x2);
                if(na<0)continue;
                par[++cnt].a=na;
                par[cnt].b=y1/x1-na*x1;
                par[cnt].hit=(1<<i)|(1<<j);
            }
        }
        sort(par+1,par+cnt+1,cp);
        for(int i=1;i<=cnt;i++){
            if(cmp(par[i].a,par[i-1].a)&&cmp(par[i].b,par[i-1].b))np[nc].hit=np[nc].hit|par[i].hit;
            else np[++nc]=par[i];
        }
        for(int i=1;i<=cnt;i++)printf("%d %d %d\n",par[i].a,par[i].b,par[i].hit);
        ans=200;
        dfs(0,0);
        printf("%d\n",ans);
    }
}
