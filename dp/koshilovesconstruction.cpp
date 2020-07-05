#include <bits/stdc++.h>
using namespace std;
#define ll long long
int x,t,n;
inline bool prime(int n){
    for(int i=2;i<=sqrt(n);i++)if(n%i==0) return false;
    return true;
}
inline int read() {
    char ch=getchar();
    int x=0,f=1;
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
int main(){
    x=read(),t=read();
    if (x==1){
        while(t--){
            n=read();
            if(n==1){
                printf("2 1\n");
                continue;
            }
            if(n&1)printf("0\n");
            else{
                printf("2 ");
                for(int j=1;j<=n;j++){
                    if(j&1)printf("%d ",n+1-j);
                    else printf("%d ",j-1);
                }
                printf("\n");
            }
        }
    }
    else {
        while(t--){
            n=read();
            if(n==4){
                printf("2 1 3 2 4\n");
                continue;
                }
            if(n==1){
                printf("2 1\n");
                continue;
            }
            if(prime(n)){
                printf("2 1 ");
                for(int i=2;i<n;i++){
                    ll j=n-2,ans=1,base=i-1;
                    while(j>0){
		                if(j&1)ans=ans*base%n;
                        base=base*base%n;
		                j>>=1;
	                    }
                    ans=ans*i%n;
                    printf("%d ",ans);
                    }
                printf("%d\n",n);    
                }
            else printf("0\n"); 
            }
        }
    return 0;
}