#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
inline int read() {
    char ch=getchar();
    register int x=0;
    int f=1;
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
const int N=2e5+5;
int t,n,arr[N],cur;
il bool check(int x){
    int l=x+1,r=n,pre=0;
    while(l<=r){
        if(pre>max(arr[l],arr[r]))return false;
        if(pre<=min(arr[l],arr[r])){
            pre=min(arr[l],arr[r]);
            if(arr[l]<=arr[r])l++;
            else r--;
        }
        else if(pre<=arr[l]){
            pre=arr[l];
            l++;
        }
        else {
            pre=arr[r];
            r--;
        }
    }
    return true;
}
int main(){
    t=read();
    while(t--){
        n=read();
        int l=0,r=n;
        for(int i=1;i<=n;i++)arr[i]=read();
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid))r=mid;
            else l=mid+1;
        }
        printf("%d\n",r);
    }
    return 0;
}