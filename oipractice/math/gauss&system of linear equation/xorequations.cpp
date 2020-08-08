//acw884
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=105;
int a[N][N];
int n;
int gauss(){
    int r=0;
    for(int c=0;c<n;c++){
        int t=r;
        for(int i=t;i<n;i++){
            if(a[i][c]){
                t=i;
                break;
            }
        }
        if(!a[t][c])continue;
        for(int i=c;i<=n;i++)swap(a[t][i],a[r][i]);
        for(int i=r+1;i<n;i++){
            if(!a[i][c])continue;
            for(int j=n;j>=c;j--)a[i][j]^=a[r][j];
        }
        r++;
    }
    if(r<n){
        for(int i=r;i<n;i++){
            if(a[i][n])return 0;
            }
        return 2;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++)a[i][n]^=a[i][j]*a[j][n];
    }
    return 1;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++)cin>>a[i][j];
    int t=gauss();
    if(t==1){for(int i=0;i<n;i++)printf("%d\n",a[i][n]);}
    else if(t==2)puts("Multiple sets of solutions");
    else puts("No solution");
    return 0;
}
