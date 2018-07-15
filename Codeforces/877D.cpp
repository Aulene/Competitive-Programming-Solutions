#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

char a[1007][1007];
int dp[1007][1007];
bool vis[1007][1007];

int n, m, k;
queue < pair <int, int> > q;

int bfs(int x1, int y1, int x2, int y2)
{
	int i, j;

	q.p(mp(x1, y1));
	dp[x1][y1] = 0;

	while(!q.empty())
		{
			pair <int, int> pz;

			pz = q.front();
			q.pop();

			int u = pz.f, v = pz.s;

			if(vis[u][v]) continue;
			vis[u][v] = 1;

			for(i = u - 1; i >= max(1LL, u - k); i--)
				if(a[i][v] == '.')
					{
						if(dp[i][v] > dp[u][v] + 1)
							{
								// cout << i << " " << v << " " << dp[u][v] << endl;
								dp[i][v] = dp[u][v] + 1;
								q.p(mp(i, v));
							}
					}
				else { break; }

			for(i = u + 1; i <= min(u + k, n); i++)
				if(a[i][v] == '.')
					{
						if(dp[i][v] > dp[u][v] + 1)
							{
								// cout << i << " " << v << " " << dp[u][v] << endl;
								dp[i][v] = dp[u][v] + 1;
								q.p(mp(i, v));
							}
					}
				else { break; }

			for(i = v - 1; i >= max(1LL, v - k); i--)
				if(a[u][i] == '.')
					{
						if(dp[u][i] > dp[u][v] + 1)
							{
								// cout << u << " " << i << " " << dp[u][v] << endl;
								dp[u][i] = dp[u][v] + 1;
								q.p(mp(u, i));
							}
					}
				else { break; }

			for(i = v + 1; i <= min(v + k, m); i++)
				if(a[u][i] == '.')
					{
						if(dp[u][i] > dp[u][v] + 1)
							{
								// cout << u << " " << i << " " << dp[u][v] << endl;
								dp[u][i] = dp[u][v] + 1;
								q.p(mp(u, i));
							}
					}
				else { break; }
		}

	return dp[x2][y2];
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j;
		int x1, x2, y1, y2;
		string s;

		cin >> n >> m >> k;

		for(i = 0; i < 1007; i++)
			for(j = 0; j < 1007; j++) dp[i][j] = 1000007;

		for(i = 1; i <= n; i++)
			{
				cin >> s;
				for(j = 0; j < s.size(); j++) a[i][j + 1] = s[j]; 
			}

		cin >> x1 >> y1 >> x2 >> y2;
		int ans = bfs(x1, y1, x2, y2);

		if(ans >= 1000007) ans = -1;

		// for(i = 1; i <= n; i++)
		// 	{
		// 		for(j = 1; j <= m; j++)
		// 			cout << dp[i][j] << " ";
		// 		cout << endl;
		// 	}
		cout << ans << endl;

		return 0;
	}