#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
const int maxn=1e6+5;
char a[maxn],b[maxn];
int bor[maxn],sa,sb,cur=0;
int main(){
    scanf("%s",&a);
    scanf("%s",&b);
    sa=strlen(a);
    sb=strlen(b);
    for(re int i=1;i<sb;i++)bor[i+1]=(a[i]==a[bor[i]])?bor[i]+1:0;
    for(re int i=0;i<sa;i++){
        while(cur&&a[i]!=b[cur])cur=bor[cur];
        cur+=(a[i]==b[cur])?1:0;
        if(cur==sb)printf("%d\n",i+2-sb);
    }
    for(int i=1;i<=sb;i++)printf("%d ",bor[i]);
}