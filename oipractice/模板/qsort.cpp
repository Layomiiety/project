#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arr array
int n,l,r,a[100010];
void qsort(int l,int r){
    int mid=a[(l+r)/2];
    int i=l,j=r;
    do{
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if (i<=j) {
            swap(a[i],a[j]);
            i++;
            j--;
        	}
        }while(i<=j);
    if (l<j) qsort(l,j);
    if (i<r) qsort(i,r);
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(0,n-1);
    for (int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
