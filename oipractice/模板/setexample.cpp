#include<bits/stdc++.h>
using namespace std;
int n, m;
set<int>s;
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&m);
        s.insert(m);
    }
    int size=s.size();
    printf("%d\n",size);
    for (int i=0;i<size;i++){
        printf("%d ",*s.begin());
        s.erase(s.begin());
    }
    return 0;
}
