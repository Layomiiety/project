#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
#define LL long long
int num[505];
int main(){
    LL k,x;
    cin>>k>>x;
    num[k]=1;
    for(int i=0;x;x/=10){
        num[i++]+=x%10;
    }
    int st=505;
    while(!num[st])st--;
    for(int i=st;i>=0;i--)cout<<num[i];
    return 0;
}
