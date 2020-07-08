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
    scanf("%s%s",a+1,b+1);
    sa=strlen(a+1);
    sb=strlen(b+1);
    for(re int i=2,j=0;i<=sb;i++){
        while(j&&b[j+1]!=b[i])j=bor[j];
        if(b[j+1]==b[i])j++;
        bor[i]=j;
        }
    for(re int i=1,j=0;i<=sa;i++){
        while(j&&b[j+1]!=a[i])j=bor[j];
        if(b[j+1]==a[i])j++;
        if(j==sb){
            printf("%d\n",i-sb+1);
            j=bor[j];
            }
    }
    for(int i=1;i<=sb;i++)printf("%d ",bor[i]);
    return 0;
}