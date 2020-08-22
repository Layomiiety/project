//acw106
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int p,m,cc;
int main(){
    scanf("%d",&p);
    while(p--){
        scanf("%d%d",&cc,&m);
        int cnt=0;
        printf("%d %d\n",cc,(m+1)/2);
        priority_queue<int> up;
        priority_queue<int,vector<int>,greater<int>> down;
        for(int i=1;i<=m;i++){
            int x;
            scanf("%d",&x);
            if(down.empty()||x>=down.top())down.push(x);
            else up.push(x);
            if(down.size()>up.size()+1){up.push(down.top()),down.pop();}
            else if(down.size()<up.size()){down.push(up.top()),up.pop();}
            if((++cnt)%2)printf("%d ",down.top());
            if(cnt==20){puts(""),cnt=0;}
        }
        puts("");
    }
    return 0;
}