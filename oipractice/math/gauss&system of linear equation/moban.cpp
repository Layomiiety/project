//acw883
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps=1e-8;
const int N=105;
double a[N][N];
int n;
int gauss(){
    int r=0;
    for(int c=0;c<n;c++){
        int t=r;
        for(int i=r+1;i<n;i++){
            if(fabs(a[i][c])>fabs(a[t][c]))t=i;
        }
        if(fabs(a[t][c])<eps)continue;
        for(int i=n;i>=c;i--){
            a[t][i]/=a[t][c];
            swap(a[t][i],a[r][i]);
            }
        for(int i=r+1;i<n;i++){
            if(fabs(a[i][c])<eps)continue;
            for(int j=n;j>=c;j--)a[i][j]-=a[r][j]*a[i][c];
        }
        r++;
    }
    if(r<n){
        for(int i=r;i<n;i++){
            if(fabs(a[i][n]>eps))return 0;
        }
        return 2;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<=n;j++){
            a[i][n]-=a[j][n]*a[i][j];
        }
    }
    return 1;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n+1;j++)
            cin>>a[i][j];
    int ans=gauss();
    if(ans==1){
        for(int i=0;i<n;i++)printf("%.2lf\n",a[i][n]);
    }
    else if(ans==2)puts("Infinite group solutions");
    else puts("No solution");
    return 0;
}