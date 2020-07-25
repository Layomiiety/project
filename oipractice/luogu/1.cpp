#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
#define il inline 
#define LL long long
const int N=1e5+5;
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    int x=floor(pow(n,(double)(double(1)/m)));
    printf("%d\n",x);
    return 0;
}