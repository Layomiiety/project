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
const int maxn=2e5+5;
int t,n;
char ss[60];
string go="abacaba";
il bool check(){
    int cur=0,en=7,last=0,pos=0,cnt=0;
        while(last<n){
            if(ss[pos]==go[cur]){
                cur++;
                pos++;
                if(cur==en){
                    cnt++;
                    if(cnt>1)return false;
                    cur=0;
                    last++;
                    pos=last;
                }
            }
            else {
                pos=++last;
                cur=0;
            }
        }
        if(cnt==1){
            for(int i=0;i<n;i++){
                if(ss[i]=='?')ss[i]='z';
            }
            return true;
        }
        cur=6,last=n-1,pos=n-1;
        while(last){
            if(ss[pos]==go[cur]||ss[pos]=='?'){
                cur--;
                pos--;
                if(cur<0){
                    for(int i=n-1;i>=0;i--){
                        if(ss[i]=='?'){
                            if(i<=last&&i>pos)ss[i]=go[i-pos-1];
                            else ss[i]='z';
                        }
                    }
                    return true;
                }
            }
            else {
                pos=--last;
                cur=6;
            }
        }
        return false;
}
int main(){
    t=read();
    while(t--){
        n=read();
        cin>>ss;
        if(check()){
            puts("Yes");
            cout<<ss<<"\n";
        }
        else puts("No");
    }
    return 0;
    }