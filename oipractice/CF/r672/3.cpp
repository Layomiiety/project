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
const int N=3e5+5;
int T,n,q,a[N];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>q;
        ll m0=0,m1=0;
        int x;
        scanf("%d",&x);
        m1=(ll)x;
        if(n==1)m0=(ll)x;
        else {
            for(int i=2;i<=n;i++){
                ll y,z;
                scanf("%d",&x);
                y=max(m1,m0+x);
                z=max(m0,m1-x);
                m0=z,m1=y;
            }
        }
        printf("%lld\n",max(m0,m1));
    }
    return 0;
}