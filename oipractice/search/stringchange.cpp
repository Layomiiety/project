#include <bits/stdc++.h>
using namespace std;
#define il inline
#define re register
string ac[6],bc[6];
int n;
il int extend(queue <string> &q,unordered_map <string, int> &ma,unordered_map <string, int> &mb,string a[],string b[]){
    int qs=q.size();
    for(int k=0;k<qs;k++){
        string ol=q.front();
        q.pop();
        for(int i=0;i<ol.size();i++){
            for(int j=0;j<n;j++){
                if(ol.substr(i,a[j].size())==a[j]){
                    string sta=ol.substr(0,i)+b[j]+ol.substr(i+a[j].size());
                    if(ma.count(sta))continue;
                    ma[sta]=ma[ol]+1;
                    if(mb.count(sta))return mb[sta]+ma[sta];
                    //cout<<a[j]<<" "<<ma[sta]<<sta<<endl;
                    q.push(sta);
                }
            }
        }
        return 11;
    }
}
il void bfs(string st,string en){
    unordered_map <string, int> dh,dt;
    queue <string> hq,tq;
    hq.push(st),tq.push(en);
    dh[st]=0,dt[en]=0;
    while(hq.size()&&tq.size()&&dh[hq.front()]+dt[tq.front()]<=10){
        int fd;
        if(hq.size()<tq.size())fd=extend(hq,dh,dt,ac,bc);
        else fd=extend(tq,dt,dh,bc,ac);
        if(fd<=10){printf("%d",fd);return;}
        //cout<<hq.front()<<dh[hq.front()]<<tq.front()<<dt[tq.front()]<<endl;
    }
    printf("NO ANSWER!");
    return;
}
int main(){
    string A,B;
    cin>>A>>B;
    while(cin>>ac[n]>>bc[n])n++;
    bfs(A,B);
    return 0;
}
