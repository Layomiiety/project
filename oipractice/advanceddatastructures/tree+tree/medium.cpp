//acw2476
#include <bits/stdc++.h>
using namespace std;
const int N=5e4+5, M=N<<2, inf=1e9;
int n,m,root[M];
struct splay{
    int s[2],p,id,v,size;
    void pushup(){size=tr[s[0]].size+tr[s[1]].size+1;}
    void rotate(){
        int y=p,z=tr[p].p,q=tr[z].s[1]==p,e=tr[y].s[1]==id;
        tr[z].s[q]=id,p=z;
        tr[y].p=id,s[e^1]=y;
        tr[s[e^1]].p=y,tr[y].s[e]=s[e^1];
        tr[y].pushup(),pushup();
    }
    void splay(int k){
        while(p!=k){
            int y=p,z=tr[y].p;
            if(z!=k){
                if((tr[y].s[0]==id)==(tr[z].s[0]==y))tr[y].rotate();
                else rotate();
            }
            rotate();
        }
        if(!k)root[id]=id;
    }
    void modify()
    int get_rank()
    int get_k()
    int get_prev()
    int get_nex()
}tr[M]