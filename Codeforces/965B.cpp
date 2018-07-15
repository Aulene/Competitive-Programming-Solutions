#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[107][107], dp[107][107];

int gaandMeiDanda(char x)
{
	if(x == '#') return 1;
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, k, u, v;
		pair < pair <int, int>, int> ans = mp(mp(1, 1), 0);
		char x;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				{
					cin >> x;
					a[i][j] = gaandMeiDanda(x);
				}

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				{	
					int ansx = 0;

					for(k = 0; k < m; k++)
						if(!a[i][j + k]) ansx++;

					if(ansx == m)
						{
							for(k = 0; k < m; k++)
								dp[i][j + k]++;
						}

					ansx = 0;

					for(k = 0; k < m; k++)
						if(!a[i + k][j]) ansx++;

					if(ansx == m)
						{
							for(k = 0; k < m; k++)
								dp[i + k][j]++;
						}
				}

		for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= n; j++)
					{
						cout << dp[i][j] << " ";
					}

				cout << endl;
			}

		for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= n; j++)
					{
						if(dp[i][j] > ans.s) {
							ans = mp(mp(i, j), dp[i][j]);
						}
					}
			}

		cout << ans.f.f << " " << ans.f.s << endl;

		return 0;
	}