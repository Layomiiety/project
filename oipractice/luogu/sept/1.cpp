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
const int N=1e7+10;
int cnt[28];
int main(){
    char s[N];
    cin>>s;
    int i=0;
    while(s[i]){
        int x=s[i]-'a';
        cnt[x]++;
        i++;
    }
    int ans=0;
    for(i=0;i<28;i++){
        ans=max(ans,cnt[i]);
    }
    printf("%d",ans);
    return 0;
}