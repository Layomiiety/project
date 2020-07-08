#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
inline int read(){
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
inline void write(ull a)    
{
    if(a>9)
        write(a/10);
    putchar(a%10+'0');
}
int n,k,cnt,sta[95],king[95];
ull f[2][95][85],ans=0;
int main(){
    n=read(),k=read();
    if(n==1){
        printf("%d",k);
        return 0;
    }
    if(k>(n*n+1)/2){
        printf("0");
        return 0;
    }
    for(int i=0;i<1<<n;i++){
        if(!(i&i<<1)){
            sta[++cnt]=i;
            for(int j=i;j;j>>=1)king[cnt]+=j&1;
            f[1][cnt][king[cnt]]=1;
            //printf("%d %d %d\n",cnt,i,king[cnt]);
        }
    }
    for(int i=2;i<=n;i++){
        memset(f[i&1],0,sizeof(f[i&1]));
        for(re int j=1;j<=cnt;j++){
            for(re int m=1;m<=cnt;m++){
                if(sta[m]&sta[j]||sta[m]&(sta[j]<<1)||sta[m]<<1&sta[j])continue;
                for(re int x=king[j];x<=k-king[m];x++){
                    f[i&1][m][x+king[m]]+=f[!(i&1)][j][x];
                    //printf("%d %d %d %d %d\n",j,m,x,f[i&1][m][x+king[m]],king[m]);
                }
            }
        }
    }
    for(re int i=1;i<=cnt;i++)ans+=f[n&1][i][k];
    write(ans);
    return 0;
}