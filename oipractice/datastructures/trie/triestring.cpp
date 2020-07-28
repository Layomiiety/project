//acw835
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define il inline
#define LL long long
using namespace std;
const int N=1e5+5;
int son[N][26],idx,cnt[N],n;
char op[2],str[N];
il void insert(){
    int p=0;
    for(int i=0;str[i];i++){
        int x=str[i]-'a';
        if(!son[p][x])son[p][x]=++idx;
        p=son[p][x];
        }
    cnt[p]++;
}
il int query(){
    int p=0;
    for(int i=0;str[i];i++){
        int x=str[i]-'a';
        if(!son[p][x])return 0;
        p=son[p][x];
    }
    return cnt[p];
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%s%s",op,str);
        if(op[0]=='I')insert();
        else printf("%d\n",query());
    }
    return 0;
}