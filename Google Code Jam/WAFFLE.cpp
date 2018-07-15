#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int ax[17][17], dp[17][17];

int build(int x, int y)
{
	if(x == 0 || y == 0)
		return 0;

	if(dp[x][y] != -1)
		return dp[x][y];

	int ans = ax[x][y] + build(x - 1, y) + build(x, y - 1) - build(x - 1, y - 1);
	return dp[x][y] = ans;
}

int calc(int x1, int y1, int x2, int y2)
{
	int ans = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, T = 1, n, m, h, v, i, j, tot;
		int a, b, c, d;					
		bool ans;		
		char x;

		cin >> t;

		while(T <= t)
			{
				tot = 0;
				ans = 1;

				for(i = 1; i < 17; i++)
					for(j = 1; j < 17; j++) ax[i][j] = dp[i][j] = -1;

				cin >> n >> m >> h >> v;

				for(i = 1; i <= n; i++)
					for(j = 1; j <= m; j++) 
						{
							cin >> x;
							if(x == '@') ax[i][j] = 1, tot++;
							else ax[i][j] = 0;
						}

				int col = tot / (v + 1), row = tot / (h + 1);

				for(i = 1; i <= n; i++)
					{
						int f = 0;

						for(j = 1; j <= m; j++) f += ax[i][j];

						if(f != row) ans = 0;
					}

				for(i = 1; i <= m; i++)
					{
						int f = 0;

						for(j = 1; j <= n; j++) f += ax[j][i];

						if(f != col) ans = 0;
					}
				

				if(ans) cout << "Case #" << T << ": POSSIBLE" << endl;
				else cout << "Case #" << T << ": IMPOSSIBLE" << endl;
				
				T++;
			}

		return 0;
	}