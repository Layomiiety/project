//acw247
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
#define il inline 
#define LL long long
const int N=1e4+5;
int n,tc=0;
double x11,x22,y11,y22;
vector<double> yy;
struct scl{
    double x,y1,y2;
    int w;
    bool operator <(const scl &s)const{
        return x<s.x;
    }
}sc[N<<1];
struct sect{
    int l,r,cnt;
    double leng;
}sec[N<<3];
il int find(double x){
    return lower_bound(yy.begin(),yy.end(),x)-yy.begin();
}
il void pushup(int u){
    if(sec[u].cnt)sec[u].leng=yy[sec[u].r+1]-yy[sec[u].l];
    else if(sec[u].l!=sec[u].r)sec[u].leng=sec[u<<1].leng+sec[u<<1|1].leng;
    else sec[u].leng=0;
}
il void build(int u,int l,int r){
    sec[u]={l,r,0,0};
    if(l!=r){
        int mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
    }
}
il void modify(int u,int l,int r,int w){
    if(sec[u].l>=l&&sec[u].r<=r)sec[u].cnt+=w;
    else{
        int mid=sec[u].l+sec[u].r >>1;
        if(l<=mid)modify(u<<1,l,r,w);
        if(r>mid)modify(u<<1|1,l,r,w);
        }
    pushup(u);
}
int main(){
    while(scanf("%d",&n),n){
        printf("Test case #%d\n",++tc);
        yy.clear();
        for(int i=0,j=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&x11,&y11,&x22,&y22);
            sc[j++]={x11,y11,y22,1};
            sc[j++]={x22,y11,y22,-1};
            yy.push_back(y11);
            yy.push_back(y22);
        }
        sort(yy.begin(),yy.end());
        yy.erase(unique(yy.begin(),yy.end()),yy.end());
        sort(sc,sc+2*n);
        build(1,0,yy.size()-2);
        double res=0;
        for(int i=0;i<2*n;i++){
            int l=find(sc[i].y1),r=find(sc[i].y2)-1;
            if(i)res+=(sc[i].x-sc[i-1].x)*sec[1].leng;
            modify(1,l,r,sc[i].w);
        }
        printf("Total explored area: %.2lf\n\n",res);
    }
    return 0;
}