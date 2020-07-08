#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans=0;
const int maxn=5e5+3;
int m[maxn],n[maxn],N;
void mergesort(int s,int e){
    if(s==e) return;
    int mid=s+e>>1;
    mergesort(s,mid);
    mergesort(mid+1,e);
    int i=s,j=mid+1,k=s;
    while(i<=mid&&j<=e){
        if (m[i]<=m[j]) n[k++]=m[i++];
        else n[k++]=m[j++], ans+=mid+1-i; 
    }
    while(i<=mid) n[k++]=m[i++];
    while(j<=e) n[k++]=m[j++];
    for (i=s;i<=e;i++) m[i]=n[i];
}
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
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) m[i]=read();
    mergesort(1,N);
    printf("%lld",ans);
    return 0;
}