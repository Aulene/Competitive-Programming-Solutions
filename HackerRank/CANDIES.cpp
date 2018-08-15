#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007], dp[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, ans = 0;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++)
			if(a[i + 1] > a[i]) a[i] = a[i - 1] + a[i];
		for(i = n - 1; i >= 1; i--) 
			if(a[i + 1] < a[i]) a[i] = a[i ]
		return 0;
	}