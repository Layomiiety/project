//acw321
#include <bits/stdc++.h>
using namespace std;
int pre[9][9],f[9][9][9][9][15],n,sum;
inline int area(int lx,int ly,int rx,int ry){
    int res=pre[rx][ry]+pre[lx][ly]-pre[lx][ry]-pre[rx][ly];
    return res*res;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            int x;
            scanf("%d",&x);
            sum+=x;
            pre[i][j]=pre[i-1][j]+pre[i][j-1]+x-pre[i-1][j-1];
        }
    }
    memset(f,0x3f,sizeof f);
    for(int lx=0;lx<=7;lx++)
        for(int ly=0;ly<=7;ly++)
            for(int rx=lx+1;rx<=8;rx++)
                for(int ry=ly+1;ry<=8;ry++)
                   f[lx][ly][rx][ry][0]=area(lx,ly,rx,ry);
    for(int op=1;op<=n;op++){
        for(int lx=0;lx<=7;lx++){
            for(int ly=0;ly<=7;ly++){
                for(int rx=lx+1;rx<=8;rx++){
                    for(int ry=ly+1;ry<=8;ry++){
                        int val=f[lx][ly][rx][ry][op];
                        for(int i=lx+1;i<rx;i++){
                            val=min(f[lx][ly][i][ry][op-1]+f[i][ly][rx][ry][0],val);
                            val=min(f[lx][ly][i][ry][0]+f[i][ly][rx][ry][op-1],val);
                        }
                        for(int i=ly+1;i<ry;i++){
                            val=min(f[lx][ly][rx][i][op-1]+f[lx][i][rx][ry][0],val);
                            val=min(f[lx][ly][rx][i][0]+f[lx][i][rx][ry][op-1],val);
                        }
                        f[lx][ly][rx][ry][op]=val;
                        printf("%d %d %d %d %d %d\n",lx,ly,rx,ry,op,val);
                    }
                }
            }
        }
    }
    double fir=f[0][0][8][8][n]/(1.0*n),sec=1.0*sum/n;
    sec*=sec;
    double ans=sqrt(fir-sec);
    printf("%.3lf %.3lf %.3lf",ans,fir,sec);
    return 0;
}