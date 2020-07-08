#include <bits/stdc++.h>
using namespace std;
struct student{
    int num,mark;
};
int n,m;
student s[5000];
bool compare(student a, student b){
    if (a.mark!=b.mark) return a.mark>b.mark;
    else return a.num<b.num;
}
int main(){
    scanf("%d%d",&n,&m);
    m=floor(m*1.5);
    for(int i=0;i<n;i++){
        scanf("%d%d",&s[i].num,&s[i].mark);
        }
    sort(s,s+n,compare);
    int ma=s[m-1].mark;
    int x=m;
    while(s[x].mark==ma)x++;
    printf("%d %d\n",s[x-1].mark,x);
    for(int i=0;i<x;i++)printf("%d %d\n",s[i].num,s[i].mark);
    return 0;
}

