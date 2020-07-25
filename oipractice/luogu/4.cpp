#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
#define il inline 
#define LL long long
const int N=1e6+5;
int n,q,arr[N],op,x,y,z,w,ml[N],mr[N];
vector<int>l,r;
il bool check(int a,int b,int c,int d){
    if(b==a)return true;
    memset(ml,0,sizeof ml);
    memset(mr,0,sizeof mr);
    l.clear(),r.clear();
    for(int i=a,j=c;i<=b;i++,j++){
        ml[arr[i]]++,mr[arr[j]]++;
        l.push_back(arr[i]),r.push_back(arr[j]);
    }
    l.erase(unique(l.begin(),l.end()),l.end());
    r.erase(unique(r.begin(),r.end()),r.end());
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    if(l.size()!=r.size())return false;
    int ch=l[0]-r[0];
    for(int i=0;i<l.size();i++){
        if(ml[l[i]]!=mr[r[i]])return false;
        if(l[i]-r[i]!=ch)return false;
    }
    return true;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
    while(q--){
        scanf("%d",&op);
        if(op){
            scanf("%d%d%d%d",&x,&y,&z,&w);
            if(x>z){swap(x,z),swap(y,w);}
            if(check(x,y,z,w))puts("YES");
            else puts("NO");
        }
        else {
            scanf("%d%d",&x,&y);
            arr[x]=y;
        }
    }
    return 0;
}