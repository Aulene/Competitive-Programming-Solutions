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

#define smy				ios::sync_with_stdio(false);	cin.tie(NULL);
#define T()				int tc;	cin>>tc; while(tc--)
#define pb				push_back
#define mk				make_pair
#define ll 				long long
#define all(c)			(c).begin(), (c).end()
#define tr(c, i)		for( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define F				first
#define S				second
#define MOD				1000000007
#define INF				2147483647
#define INFL			9023372036854775807LL
#define gcd(a,b) 		__gcd(a,b)
#define count_1(n)    	__builtin_popcountll(n)

ll modexp(ll x, ll y)
{
	ll res = 1;
	x = x%MOD;
	
	while(y > 0)
	{
		if(y&1)
			res = (res*x)%MOD;
			
		y = y>>1;
		x = (x*x)%MOD;
	}
	
	return res;
}

int main()
{
	smy
	T()
	{
		int n;	cin>>n;
		ll a[n];
		ll sum = 0;
		ll res = 1;

		for(int i=0; i<n; i++)
		{
			cin>>a[i];
				sum = (sum + a[i])%MOD;
				res = (res * a[i])%MOD;
		}
		cout<<sum << " " << res<<endl;
		
		sum = (sum * (n-1))%MOD;
		res = (res * (n-1))%MOD;
		
		cout<<sum << " " << res<<endl;
		
		ll ans = (sum + res)%MOD;
		if(ans < 0)
			ans += MOD;
			
		cout<<ans<<endl;
	}
	return 0;
}
