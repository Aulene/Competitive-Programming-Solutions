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

int a[27][27];
int dp[27][1050007];
int n;

int recur(int idx, int mask)
{
	if(idx > n) 
		return 1;

	if(dp[idx][mask] != -1) 
		return dp[idx][mask];

	int mx, ans = 0;

	for(int i = 1; i <= n; i++)
		if(a[idx][i]) 
			{
				if(!(mask & (1 << i)))
					{
						mx = mask;
						mx = mx | (1 << i);
						ans += recur(idx + 1, mx);
					}
			}

	return dp[idx][mask] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t, m, i, j, u, v;

		cin >> t;

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				for(k = 0; k < n; k++)
					for(l = 0; l < n; l++)
						if(a[i] + b[j] + c[k] + d[l] == 0) ans++;
	
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				E[n * i + j] = C[i] + D[j];

		while(t--)
			{
				cin >> n;

				for(i = 0; i < 27; i++)
					for(j = 0; j < 1050007; j++) dp[i][j] = -1;

				for(i = 1; i <= n; i++)
					for(j = 1; j <= n; j++) cin >> a[i][j];

				cout << recur(1, 0) << endl;
			}

		return 0;
	}