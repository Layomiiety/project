//acw214
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define il inline
double f[16][16][16][16][5][5];
int a,b,c,d;
il double dp(int A,int B,int C,int D,int cl,int CL){
    if(f[A][B][C][D][cl][CL])return f[A][B][C][D][cl][CL];
    if(A+(cl==1)+(CL==1)>=a&&B+(cl==2)+(CL==2)>=b
     &&C+(cl==3)+(CL==3)>=c&&D+(cl==4)+(CL==4)>=d) return f[A][B][C][D][cl][CL]=0;
    int sum=2+A+B+C+D-(!CL)-(!cl);
    if(sum<0)return f[A][B][C][D][cl][CL]=1e8;
    double res=1,m1=1e8,m2=1e8;
    if(A<13)res+=(13-A)/(double)(54-sum)*dp(A+1,B,C,D,cl,CL);
    if(B<13)res+=(13-B)/(double)(54-sum)*dp(A,B+1,C,D,cl,CL);
    if(C<13)res+=(13-C)/(double)(54-sum)*dp(A,B,C+1,D,cl,CL);
    if(D<13)res+=(13-D)/(double)(54-sum)*dp(A,B,C,D+1,cl,CL);
    if(!cl){
        for(int i=1;i<=4;i++)m1=min(m1,dp(A,B,C,D,i,CL)/(double)(54-sum));
        res+=m1;
    }
    if(!CL){
        for(int i=1;i<=4;i++)m2=min(m2,dp(A,B,C,D,cl,i)/(double)(54-sum));
        res+=m2;
    }
    return f[A][B][C][D][cl][CL]=res;
}
int main(){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    double ans=dp(0,0,0,0,0,0);
    if(ans>54)puts("-1.000");
    else printf("%.3lf",ans);
}
