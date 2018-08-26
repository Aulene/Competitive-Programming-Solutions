#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

vi vs;
int a[200007], dp[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, i, j, u, v, ans = 0;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i], vs.pb(a[i]);

		ans = 1;
		for(i = 1; i < n; i++)
			{
				if(a[i] <= 2 * a[i - 1]) 
					dp[i] = 1 + max(dp[i - 1], 1LL);
				ans = max(ans, dp[i]);
			}

		cout << ans << endl;
		return 0;
	}