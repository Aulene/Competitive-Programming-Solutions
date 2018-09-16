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
#define N 100007

int a[N], dp[N];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v, ans = 0, sum;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i < n; i++)
			dp[i] = abs(a[i] - a[i + 1]);
		// for(i = 1; i < n; i++) cout << dp[i] << " "; cout << endl;
		
		i = 1, sum = 0;

		while(i < n)
			{
				if(i % 2 == 1) sum += dp[i];
				else sum -= dp[i];
				ans = max(ans, sum);
				sum = max(sum, 0LL);
				i++;
			}

		i = 2, sum = 0;

		while(i < n)
			{
				if(i % 2 == 0) sum += dp[i];
				else sum -= dp[i];
				ans = max(ans, sum);
				sum = max(sum, 0LL);
				i++;
			}

		cout << ans << endl;
		return 0;
	}