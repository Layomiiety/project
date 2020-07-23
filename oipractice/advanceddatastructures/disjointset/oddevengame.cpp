//acw239
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
#define il inline 
#define LL long long
unordered_map<int,int> mm;
const int N=20005;
int n,m,fa[N],d[N],cc=0;
il int ff(int x){
    if(x==fa[x])return x;
    int root=ff(fa[x]);
    d[x]^=d[fa[x]];
    fa[x]=root;
    return root;
}
int main(){
    cin>>n;
    cin>>m;
    for(int i=1;i<=2*m;i++)fa[i]=i;
    int res=m;
    for(int i=1;i<=m;i++){
        int l,r;
        char ss[6];
        cin>>l>>r>>ss;
        l-=1;
        if(!mm.count(l))mm[l]=++cc;
        if(!mm.count(r))mm[r]=++cc;
        l=mm[l],r=mm[r];
        int al=ff(l),ar=ff(r);
        if(ss[0]=='e'){
            if(al==ar){
                if(d[l]^d[r]){
                    res=i-1;
                    break;
                }
            }
            else {
                fa[al]=ar;
                d[al]=d[l]^d[r];
            }
        }
        else {
            if(al==ar){
                if(~d[l]^d[r]){
                    res=i-1;
                    break;
                }
            }
            else{
                fa[al]=ar;
                d[al]=~d[l]^d[r];
            }
        }
        //printf("%d %d %d %d %d %d\n",al,ar,l,r,d[l],d[r]);
    }
    printf("%d",res);
    return 0;
} 