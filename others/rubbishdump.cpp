#include <bits/stdc++.h>
using namespace std;
#define ll long long
int d,g,e[101];
struct rub{
    int t,h,f;
}r[101];
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
bool cmp(rub r1,rub r2){
    return r1.t<r2.t;
}
int main(){
    d=read(),g=read();
    for (int i=1;i<=g;i++){
        r[i].t=read(),r[i].f=read(),r[i].h=read();
    }
    sort(r+1,r+1+g,cmp);
    e[0]=10;
    for(int i=1;i<=g;i++){
        for(int j=d;j>=0;j--){
            if(e[j]>=r[i].t){
                if(j+r[i].h>=d){
                    printf("%d",r[i].t);
                    return 0;
                }
                e[j+r[i].h]=max(e[j+r[i].h],e[j]);
                e[j]+=r[i].f;
            }
        }
    }
    printf("%d",e[0]);
    return 0;
}