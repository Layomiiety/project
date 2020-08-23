#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
#define LL long long
LL a,b,c,d,ans;
int main(){
    cin>>a>>b>>c>>d;
    if(a==b){
        if(a==0)ans=0;
        else ans=min(2*d,c);
    }
    else {
        if(a==0||b==0){
            ans=d;
        }
        else {
            ans=min(c+d,2*d);
        }
    }
    cout<<ans;
    return 0;
}
