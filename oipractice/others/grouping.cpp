#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,rating,co;
map<int,int>m;
typedef map<int,int>::iterator it;
inline int read(){
    register char ch=getchar();
    register int x=0, f=1;
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*f;
}
int main(){
    n=read();
    for(int i=0;i<n;i++){
        rating=read();
        m[rating]++;
    }
    int minn=n;
    while(!m.empty()){
        it i=m.begin(),j=m.begin();
        (*i).second--;
        co=1;
        j++;
        while(j!=m.end()&&(*j).first==(*i).first+1&&(*j).second>(*i).second)i++,(*j).second--,j++,co++;
        minn=min(minn,co);
        i=m.begin();
        while(i!=m.end()&&(*i).second==0)m.erase((*i++).first);   
    }
    printf("%d",minn);
    return 0;
}