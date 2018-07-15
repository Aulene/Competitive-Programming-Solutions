#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007], p[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, sum = 0, ans = INT_MAX;

		cin >> n >> m;

		for(i = 1; i <= n - 1; i++) cin >> a[i], sum += a[i], p[i] += p[i - 1] + a[i];

		for(i = m; i <= n; i++)	{
			sum -= p[i - m];
			sum += p[i];
			ans = min(ans, sum);
		}	

		cout << ans << endl;


		return 0;
	}