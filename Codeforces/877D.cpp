#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[1007][1007], dp[1007][1007];
int n, m, k;

void bfs(int x, int y)
{
	pair <int, int> pz;
	queue < pair <int, int> > q;

	dp[x][y] = 0;
	q.p(mp(x, y));

	while(!q.empty())
		{
			pz = q.front();
			q.pop();

			int x = pz.f, y = pz.s, s = dp[x][y] + 1;

			for(int i = 1; i <= k; i++)
				{
					if(x + i <= n && a[x + i][y])
						{
							if(dp[x + i][y] > s) {
								dp[x + i][y] = s;
								q.p(mp(x + i, y));
							}
						}
					else break;
				}

			for(int i = 1; i <= k; i++)
				{
					if(x - i >= 1 && a[x - i][y])
						{
							if(dp[x - i][y] > s) {
								dp[x - i][y] = s;
								q.p(mp(x - i, y));
							}
						}
					else break;
				}
			
			for(int i = 1; i <= k; i++)
				{
					if(y - i >= 1 && a[x][y - i])
						{
							if(dp[x][y - i] > s) {
								dp[x][y - i] = s;
								q.p(mp(x, y - i));
							}
						}
					else break;
				}

			for(int i = 1; i <= k; i++)
				{
					if(y + i <= m && a[x][y + i])
						{
							if(dp[x][y + i] > s) {
								dp[x][y + i] = s;
								q.p(mp(x, y + i));
							}
						}
					else break;
				}
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, u, v;
		int x1, x2, y1, y2, ans = -1;
		char x;

		cin >> n >> m >> k;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) dp[i][j] = INT_MAX;

 		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				{
					cin >> x;
					if(x == '.') {
						a[i][j] = 1;
					}
				}

		cin >> x1 >> y1 >> x2 >> y2;

		// for(i = 1; i <= n; i++)
		// 	{ for(j = 1; j <= m; j++) cout << a[i][j] << " "; cout << endl; }

		bfs(x1, y1);

		// for(i = 1; i <= n; i++)
		// 	{ for(j = 1; j <= m; j++) cout << dp[i][j] << " "; cout << endl; }

		ans = dp[x2][y2];
		if(ans == INT_MAX) ans = -1;

		cout << ans << endl;

		return 0;
	}