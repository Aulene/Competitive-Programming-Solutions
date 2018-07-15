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

int spath[107][107], g[107][107];
int spathsum[107];
bool vis[107];
queue < pair <int, int> > q;

void floyd(int n)
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			{
				if(i == j) spath[i][i] = 0;
				else if(g[i][j]) spath[i][j] = g[i][j];
				else spath[i][j] = mod;
			}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
				spath[j][k] = min(spath[j][k], spath[j][i] + spath[i][k]);
}

long double compute(int n, int c)
{
	q.p(mp(1, 1));
	pair <int, int> pz;
	int u, v, ans = 0, l = 0;
	long double ansx;

	while(!q.empty())
		{
			pz = q.front();
			q.pop();

			u = pz.f, v = pz.s;

			ans += spathsum[u];
			
			if(v == c) continue;

			for(int i = 1; i <= n; i++) 
				{
					if(i != u) 
						{
							
							q.p(mp(i, v + 1));
						}
				}
		}

	l = pow(n - 1, c);
	cout << ans << " " << l << endl;

	ansx = (long double) ans / (l);
	return ansx;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, u, v, w, c, i, j, k, sum;
		long double ans;

		cin >> t;

		for(k = 1; k <= t; k++)
			{
				cin >> n >> m >> c;

				for(i = 1; i <= n; i++)
					for(j = 1; j <= n; j++) g[i][j] = 0;

				for(i = 1; i <= n; i++) vis[i] = 0;

				for(i = 0; i < m; i++)
					{
						cin >> u >> v >> w;
						g[u][v] = w;
						g[v][u] = w;
					}

				floyd(n);

				for(i = 1; i <= n; i++)
					{
						sum = 0;
						for(j = 1; j <= n; j++) sum += spath[i][j];
						spathsum[i] = sum;
					}

				ans = compute(n, c);
				printf("Case %lld: %.11Lf\n", k, ans);
			}
		return 0;
	}