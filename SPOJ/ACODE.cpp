#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define lli long long int
#define mod 1000000007
#define pb push_back

lli dp[5007];

int recur(int index, int val, string s)
{
	//cout << index << " " << val << " " << s << endl;

	if(val<1 || val>26)
		return 0;

	if(index<0)
		return 0;

	if(index==0 || index==1)
		return 1;

	if(dp[index]!=-1)
		return dp[index];

	int ans1=0, ans2=0, ans;
	int len=s.size();
	int val1, val2;

	string s1, s2;

	s1=s.substr(0, len-1);
	val1=s[len-1]-'0';

	s2=s.substr(0, len-2);
	val2=(s[len-2]-'0')*10+s[len-1]-'0';

	ans1=recur(index-1, val1, s1);

	if(s[len-2]-'0'!=0)
		ans2=recur(index-2, val2, s2);
	
	ans=ans1+ans2;

	return dp[index]=ans;
}

int main()
	{
		string s;
		int ans, len, i;

		while(cin >> s)
			{
				if(s[0]=='0')
					break;

				for(i=0; i<5007; i++)
					dp[i]=-1;

				len=s.size();
				ans=recur(len, 1, s);
				cout << ans << endl;
			}

		return 0;
	}