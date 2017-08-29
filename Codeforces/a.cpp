#include<bits/stdc++.h>

using namespace std;

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define f first
#define s second

lli a[2007], prefix[2007], b[2007];
unordered_map <lli, lli> m;

signed main() 
{
	lli n, k, i, num, j, ans = 0;

	cin >> n >> k;
	
	prefix[0]=0;

	for(i = 1; i <= n; i++)
		{
			cin >> a[i];
			prefix[i] = prefix[i - 1] + a[i];
		}
	
	for(i = 1; i <= k; i++)
		cin >> b[i];
	
	for(i = 1; i <= k; i++)
		{
			unordered_map <lli, lli> mx;

			for(j = 1; j <= n; j++)
				{
					num = b[i] - prefix[j];

					if(mx.find(num) == mx.end())
						{
							m[num]++;
							mx[num]++;
						}
				}
		}
	
	unordered_map<lli, lli>:: iterator it;

	for(it=m.begin(); it != m.end(); it++)
		if(it->second == k)
			ans++;
	
	cout << ans << endl;
	
	return 0;
}