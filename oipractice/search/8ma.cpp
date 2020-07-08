#include <bits/stdc++.h>
using namespace std;
#define il inline
#define re register
typedef pair<int,int> pii;
typedef pair<int,string> pis;
string ini,ch,endd="12345678x";
unordered_map <string,int> dis;
unordered_map <string,pair<char,string>> pre;
il int f(string xx){
    int su=0;
    for(int i=0;i<9;i++)
        if(xx[i]!='x'){
            int xi=xx[i]-'1';
            su+=abs(i/3-xi/3)+abs(i%3-xi%3);
        }
    return su;
}

il string bfs(){
    priority_queue<pis,vector<pis>,greater<pis> >q;
    int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
    char dc[4]={'l','u','r','d'};
    q.push({f(ini),ini});
    while(!q.empty()){
        pis ne=q.top();
        q.pop();
        string sta=ne.second,ori=sta;
        if(sta==endd)break;
        int px,step=dis[sta];
        //cout<<step<<sta<<ne.first<<endl;
        for(int i=0;i<9;i++){
            if(sta[i]=='x'){px=i;break;}
        }
        int xx=px/3,yy=px%3;
        for(int i=0;i<=3;i++){
            int nx=xx+dx[i],ny=yy+dy[i];
            if(nx<0||nx>2||ny<0||ny>2)continue;
            int nxx=3*nx+ny;
            swap(sta[nxx],sta[px]);
            if(!dis.count(sta)||dis[sta]>step+1){
                dis[sta]=step+1;
                pre[sta]={dc[i],ori};
                q.push({f(sta)+dis[sta],sta});
            }
            sta=ori;
        }
    }
    string res,en=endd;
    while(en!=ini){
        res+=pre[en].first;
        en=pre[en].second;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    char s;
    while(cin>>s){
        if(s!='x')ch+=s;
        ini+=s;
        }
    int rp;
    for(int i=0;i<7;i++){
        for(int j=i+1;j<8;j++){if(ch[i]>ch[j])rp++;}
    }
    if(rp&1){puts("unsolvable");return 0;}
    cout<<bfs();
    return 0;
}