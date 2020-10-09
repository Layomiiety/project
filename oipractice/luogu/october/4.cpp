#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define il inline
const int N=2e6+5;
int n;
int main(){
    scanf("%d",&n);
    if(n==3){
        printf("3\n2 1 2\n2 1 3\n2 2 3");
    }
    else if(n%3){
        printf("%d\n",n-1);
        int m=(n-1)/2;
        for(int i=1;i<m;i++){
            printf("2 %d %d\n",i,m+i);
            printf("2 %d %d\n",i,m+i+1);
        }
        printf("2 %d %d\n",m,m*2);
        printf("2 %d %d\n",m,m+1);
        printf("%d ",m);
        for(int i=m+1;i<=2*m;i++)printf("%d ",i);
    }
    else{
        printf("%d\n",n);
        int m=n/2;
        for(int i=1;i<m;i++){
            printf("2 %d %d\n",i,m+i);
            printf("2 %d %d\n",i,m+i+1);
        }
        printf("2 %d %d\n",m,m*2);
        printf("%d ",m);
        for(int i=m+1;i<=2*m;i++)printf("%d ",i); 
    }
}