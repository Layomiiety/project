//acw1165
#include <bits/stdc++.h>
using namespace std;
const int N=700,M=1e5;
int h[M],nex[M],to[M],w[M],cnt=1,n,cc[N];
double dist[N];
char stt[1010];
bool st[N];
inline void add(int a,int b,int c){to[cnt]=b,w[cnt]=c,nex[cnt]=h[a],h[a]=cnt++;}
inline bool spfa(double x){
    memset(cc,0,sizeof cc);
    memset(dist,0,sizeof dist);
    queue <int> q;
    for(int i=0;i<26*26;i++){st[i]=true,q.push(i);}
    int c=0;
    while(!q.empty()){
        int hh=q.front();
        q.pop();
        st[hh]=false;
        for(int i=h[hh];i;i=nex[i]){
            int j=to[i];
            if(dist[j]<dist[hh]+w[i]-x){
                dist[j]=dist[hh]+w[i]-x;
                cc[j]=cc[hh]+1;
                if(++c>2*n)return true;
                if(cc[j]>=N)return true;
                if(!st[j]){
                    st[j]=true;
                    q.push(j);
                }
            }
        }
    }
    return false;
}
int main(){
    while(cin>>n&&n){
        cnt=1;
        memset(h,0,sizeof h);
        for(int i=0;i<n;i++){
            scanf("%s",stt);
            int l=strlen(stt);
            if(l>=2){
                int ll=(stt[0]-'a')*26+stt[1]-'a',rr=(stt[l-2]-'a')*26+stt[l-1]-'a';
                add(ll,rr,l);
            }
        }
        if(!spfa(0)){
            puts("No solution");
            continue;
        }
        double le=0,ri=1000;
        while(ri-le>1e-4){
            double mid=(le+ri)/2;
            if(spfa(mid))le=mid;
            else ri=mid;
        }
        printf("%lf\n",le);
    }
}