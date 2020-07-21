//p1120
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
#define il inline 
#define LL long long
int n,l[70],cnt,sum,stick[70];
il bool dfs(int cur,int stk,int ttl,int tts){
    if(cur==cnt)return true;
    for(int i=1;i<=stk;i++){
        if(stick[i]+l[cur]>ttl)return false;
        stick[i]+=l[cur];
        if(dfs(cur+1,stk,ttl,tts))return true;
        stick[i]-=l[cur];
        }
    if(stk==tts)return false;
    stick[stk+1]=l[cur];
    if(dfs(cur+1,stk+1,ttl,tts))return true;
    stick[stk+1]=0;
    return false;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a<=50){
            l[cnt++]=a;
            sum+=a;
            }
    }
    sort(l,l+cnt);
    for(int i=l[cnt-1];i<=sum;i++){
        if(sum%i)continue;
        memset(stick,0,sizeof stick);
        if(dfs(0,1,i,sum/i)){
            cout<<i;
            break;
            }
    }
    return 0;
}
