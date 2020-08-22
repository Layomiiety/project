//acw105
#include <bits/stdc++.h>
using namespace std;
const int N=100005;
#define ll long long 
int row[N],col[N],n,m,t;
ll s[N],c[N];
ll q(int a[],int x){
    if(t%x)return -1;
    int p=t/x;
    for(int i=1;i<=x;i++){
        s[i]=s[i-1]+(ll)a[i];
        c[i]=s[i-1]-(i-1)*p;
        //printf("%lld %lld\n",s[i],c[i]);
    }
    c[1]=0;
    sort(c+1,c+x+1);
    ll mid=c[(x+1)/2];
    ll res=0;
    for(int i=1;i<=x;i++)res+=abs(c[i]-mid);
    return res;
}
int main(){
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<t;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        row[x]++,col[y]++;
    }
    ll r=q(row,n),c=q(col,m);
    if(r==-1&&c==-1)puts("impossible");
    else if(c==-1)printf("row %lld",r);
    else if(r==-1)printf("column %lld",c);
    else printf("both %lld",r+c);
    return 0;
}