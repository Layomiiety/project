#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define re register
#define il inline
const int N=2e5+5;
int n,vv[N],maxx[N]={-0x3f};
void solve(){
    int res=0;
    cin>>n;
    for(int i=2;i<=n+1;i++){
        cin>>vv[i];
        maxx[i]=max(maxx[i-1],vv[i]);
        if((vv[i]<vv[i-1])&&(vv[i-1]>maxx[i-2]))res++;
        }
    if(vv[n+1]>maxx[n])res++;
    cout << res << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}