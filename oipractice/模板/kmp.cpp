//acw831
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char p[100005],s[1000005];
int n,m,nex[100005];
int main(){
    cin>>n>>p+1>>m>>s+1;
    for(int i=2;i<=n;i++){
        int j=nex[i-1];
        while(j&&p[i]!=p[j+1])j=nex[j];
        if(p[i]==p[j+1])j++;
        nex[i]=j;
    }
    for(int i=1,j=0;i<=m;i++){
        while(j&&s[i]!=p[j+1])j=nex[j];
        if(s[i]==p[j+1])j++;
        if(j==n){
            printf("%d ",i-n);
            j=nex[j];
        }
    }
    return 0;
}