#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,i,j,c,d[50005],l;
bool judge(int mindis){
    i=0,j=1,c=0;
    while (j<=n+1){
        if(d[j]-d[i]>=mindis) i=j,j++;
        else c++,j++;
    }
    return c<=m;
}
inline int read(){
    char ch=getchar();
    int x=0,f=1;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*f;
}
int main(){
    scanf("%d%d%d",&l,&n,&m);
    d[0]=0,d[n+1]=l;
    for (i=1;i<=n;i++) d[i]=read();
    int le=1,ri=l,mid,ans;
    while(le<=ri){
        mid=le+ri>>1;
        if (judge(mid)) le=mid+1,ans=mid;
        else ri=mid-1;
        }
    printf("%d",ans);
    return 0;
    }


