//acw243
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
int main(){
    vector <int> l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(5);
    l.push_back(3);
    l.push_back(3);
    sort(l.begin(),l.end());
    l.erase(unique(l,l+5),l+5);
    printf("%d %d %d",l[0],l[1],l[2]);
}