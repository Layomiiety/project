#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
const double ep=1e-8;
int T,n,m,f[1<<18],sta[20][20];
double cx[20],cy[20];
il int cmp(double i,double j){
    if (fabs(i-j)<ep)return 0;
    return i>j?1:-1;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&cx[i],&cy[i]);
            }
        if(n==1){
            printf("1\n");
            continue;
        }
        memset(sta,0,sizeof(sta));
        memset(f,0x3f,sizeof(f));
        f[0]=0;
        for(int i=0;i<n;i++){
            sta[i][i]=1<<i;
            for(int j=0;j<n;j++){
                double x1=cx[i],x2=cx[j],y1=cy[i],y2=cy[j];
                if(!cmp(x1,x2))continue;
                double na=(y1/x1-y2/x2)/(x1-x2);
                if(cmp(na,0)>=0)continue;
                double nb=y1/x1-na*x1;
                int st=0;
                for(int k=0;k<n;k++){
                    if(!cmp(na*cx[k]*cx[k]+nb*cx[k],cy[k]))st+=1<<k;
                }
                sta[i][j]=st;
            }
        }
        for(int i=0;i+1<1<<n;i++){
            int np=0;
            for(int j=0;j<n;j++){
                if(!(i>>j&1)){
                    np=j;
                    break;
                    }
            }
            for(int j=0;j<n;j++){
                f[i|sta[np][j]]=min(f[i|sta[np][j]],f[i]+1);
            }
        }
        printf("%d\n",f[(1<<n)-1]);
    }
    return 0;
}
