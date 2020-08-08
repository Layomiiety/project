//acw883
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=12;
double a[N][N],b[N][N];
int n;
void gauss(){
    for(int c=0,r=0;c<n;c++,r++){
        int t=r;
        for(int i=t+1;i<n;i++){
            if(fabs(b[i][c])>fabs(b[t][c]))t=i;
            }
        for(int i=n;i>=c;i--){
            b[t][i]/=b[t][c];
            swap(b[t][i],b[r][i]);
            }
        for(int i=r+1;i<n;i++){
            for(int j=n;j>=c;j--)b[i][j]-=b[i][c]*b[r][j];
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<=n;j++)b[i][n]-=b[i][j]*b[j][n];
    }
}
int main(){
    cin>>n;
    for(int i=0;i<=n;i++)
        for(int j=0;j<n;j++)cin>>a[i][j];
    for(int i=0;i<n;i++){
        b[i][n]=0;
        for(int j=0;j<n;j++){
            b[i][n]+=a[i+1][j]*a[i+1][j]-a[i][j]*a[i][j];
            b[i][j]=2*(a[i+1][j]-a[i][j]);
            }
        }
    gauss();
    for(int i=0;i<n;i++)printf("%.3lf ",b[i][n]);
    return 0;
}
