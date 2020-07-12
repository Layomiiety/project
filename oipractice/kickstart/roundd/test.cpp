#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
#define re register
#define il inline
using namespace std;
const int N=2e5+5;
int T,n,k,cur;
int solve(){
    int res=0;
    bool st=false;
    scanf("%d%d",&n,&k);
    int ss=k-1;
    for(int i=1;i<=n;i++){
        scanf("%d",&cur);
        if(cur==k)st=true;
        else if(st){
            if(cur==ss){
                ss--;
                if(ss==0){res++;st=0;ss=k-1;}
            }
            else {
                st=0;
                ss=k-1;
            }
        }
        //cout<<cur<<" "<<ss<<" "<<st<<"\n";
    }
    return res;
}
int main(){
    cin>>T;
    for (int t=1;t<=T;t++){
        int rr=solve();
        cout<<"Case #"<<t<<": "<<rr<<"\n";
    }
}