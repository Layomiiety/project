#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int T;
string inv(string a)//由于是字符串，建议自己写一个非运算
{
    string res = "";
    for (char c : a) {
        if (c == '0') res += '1';
        else if ((int)res.length() > 0) res += '0';//注意不要前缀0
    }
    if((int)res.length() == 0) return "0";//特判一下
    return res;
}
int work(string s, string e, int len)//len代表当前建好e的部分的长度
{
    int res = 0;
    while (res <= 200 && s != e)//多加个停止条件总不会错
	{
        if (len < (int)e.length() && s[0] == '1')//特判掉s是0的情况，因为怎么左移都没用
		{  
			if(s.back() == '0')
			{
				if(len?e[len-1]:'0' == e[len])//如果和前一位相同，注意特判是第一位的情况
				{
					s += '0';
            		res++, len++;
					continue;
				}
			}
			else if(len?e[len-1]:'0' != e[len])//最后一位是1，加0相当于把两个连续01串隔开
			{
					s += '0';
            		res++, len++;
					continue;
			}
        }
        s = inv(s);//否则进行否操作
        res++;
    }
    if (s == e) return res;
    else return inf;
}
int main() {
    scanf("%d",&T);
    for (int ca = 1; ca <= T; ca++) {
        string s,e;
        cin>>s>>e;
        printf("Case #%d: ", ca);
		int res = inf;
    	for (int i = max(0,(int)s.length()-(int)e.length()); i <= (int)s.length(); i++)//枚举后缀长度
		{
        	int len = (int)s.length()-i;
        	string ss = s.substr(i, len);
        	string ee = e.substr(0, len);
        	if(ss == ee||inv(ss) == ee)res = min(res, work(s, e, len));//找到可能的公共前（后）缀
    	}
        if (res == inf) puts("IMPOSSIBLE");
        else printf("%d\n",res);
    }
}
