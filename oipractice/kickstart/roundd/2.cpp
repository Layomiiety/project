#include <iostream>
#include <algorithm>
#define ll long long
#define re register
#define il inline
using namespace std;
const int N=1e4+5;
int T,k,kk[N],cc,pre;
il int solve(){
    int cur=0,pre=0,res=0;
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>cc;
        if(cc>pre){
            if(cur>=0){
                cur++;
                if(cur>4){
                    res++;
                    cur=0;
                }
            }
            else cur=1;
        }
        else if(cur<pre){
            if(cur<=0){
                cur--;
                if(cur<-4){
                    res++;
                    cur=0;
                }
            }
            else cur=-1;
        }
        pre=cc;
        //cout<<cur<<"\n";
    }
    return res;
}
int main(){
    cin>>T;
    for (int t=1;t<=T;t++){
        int rr=solve();
        cout<<"Case #"<<t<<": "<<rr<<"\n";
    }
    return 0;
}