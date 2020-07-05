#include <bits/stdc++.h>
using namespace std;
int cen[8]={6,7,8,11,12,15,16,17}, occ[4],opp[8]={5,4,7,6,1,0,3,2},op[8][7]={
    {0,2,6,11,15,20,22},
    {1,3,8,12,17,21,23},
    {10,9,8,7,6,5,4},
    {19,18,17,16,15,14,13},
    {23,21,17,12,8,3,1},
    {22,20,15,11,6,2,0},
    {13,14,15,16,17,18,19},
    {4,5,6,7,8,9,10}
};
int q[24],p[100];
inline int f(){
    memset(occ,0,sizeof occ);
    for(int i=0;i<8;i++){
        occ[q[cen[i]]]++;
    }
    for(int i=1;i<4;i++){
        occ[0]=max(occ[0],occ[i]);
    }
    return (8-occ[0]);
}
inline void operate(int x){
    int ze=q[op[x][0]];
    for(int i=1;i<7;i++)q[op[x][i-1]]=q[op[x][i]];
    q[op[x][6]]=ze;
}
inline bool dfs(int d,int dd,int last){
    printf("%d %d %d\n",d,f(),dd);
    if(d+f()>dd)return false;
    if(!f())return true;
    for(int i=0;i<8;i++){
        if(opp[i]!=last){
            operate(i);
            p[d]=i;
            if(dfs(d+1,dd,i))return true;
            operate(opp[i]);
        }
    }
    return false;
}
int main(){
    while(cin>>q[0]&&q[0]){
        for(int i=1;i<24;i++)cin>>q[i];
        int depth=0;
        while(!dfs(0,depth,-1))depth++;
        if(depth)for(int i=1;i<depth;i++)printf("%c",p[i]+'A');
        else printf("No moves needed");
        printf("\n%d\n",q[6]);
    }
    return 0;
}