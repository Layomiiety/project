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
int n,l[70],cnt=0,sum=0;
bool stick[70];
il bool dfs(int cur,int cll,int ttl,int tts,int last){
    //printf("%d %d %d %d\n",cur,cll,ttl,tts);
    if(cur==tts+1)return true;
    int i=last+1;
    while(i<cnt){
        if(stick[i]){
            i++;
            continue;
            }
        if(cll+l[i]>ttl){
            while(l[i]==l[i+1]&&i<cnt)i++;
            i++;
            continue;
            }
        if(cll+l[i]==ttl){
            //printf("equal %d %d\n",l[i],cur);
            stick[i]=true;
            if(dfs(cur+1,0,ttl,tts,-1))return true;
            stick[i]=false;
            return false;
        }
        if(cll+l[i]<ttl){
            //printf("%d %d %d\n",l[i],cll,cur);
            stick[i]=true;
            if(dfs(cur,cll+l[i],ttl,tts,i))return true;
            stick[i]=false;
            if(!cll)return false;
        }
        while(l[i]==l[i+1]&&i<cnt)i++;
        i++;
    }
    return false;
}
int main(){
    cin>>n;
    memset(l,0x3f,sizeof l);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a<=50){
            l[cnt++]=a;
            sum+=a;
            }
    }
    sort(l,l+cnt,greater<int>());
    for(int i=l[0];i<=sum;i++){
        if(sum%i)continue;
        memset(stick,0,sizeof stick);
        if(dfs(1,0,i,sum/i,-1)){
            cout<<i;
            break;
            }
    }
    return 0;
}
