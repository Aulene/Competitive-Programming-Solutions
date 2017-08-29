#include<iostream>
#include<fstream>
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
#define p push
#define pb push_back
#define mp make_pair

string s, s1;
lli n, N;

string counter(lli x)
{
	string ans="";
	while(x)
		{
			ans.pb(x%10 + '0');
			x/=10;
		}
	reverse(ans.begin(), ans.end());
	return ans;
}

lli countdig(lli x)
{
	lli ans=0;
	while(x)
		{
			ans++;
			x/=10;
		}
	return ans;
}

lli recur(lli pos,lli pot)
{
	lli i, a=0;

	if(pos >= s.size()) 
		return 0;
	
	string rem=s.substr(pos, N), ans="";
	
	while(rem[rem.size()-1]=='0')
		rem.pop_back();

	reverse(rem.begin(), rem.end());

	//cout<<rem<<endl;
	
	if(rem.size() < s1.size()) 
		ans=rem;
	else if(rem>s1)
		ans=rem.substr(1, rem.size());
	else 
		ans=rem;
	//cout<<ans<<endl;

	for(i=0; i<ans.size(); i++)
		{
			a*=10;
			a+=ans[i]-'0';
		}

	return a*pot+recur(pos+ans.size(), pot*n);
}

int main()
{
	cin >> n >> s;
	reverse(s.begin(), s.end());
	N=countdig(n);
	s1=counter(n);
	cout << recur(0,1) << endl;

	return 0;
}
