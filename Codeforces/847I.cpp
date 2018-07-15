#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

char grid[257][257];
int ans[257][257];
int ax[257][257];
int p2[107];
int q, n, m;

int f1[] = {+1, 0, -1, 0};
int f2[] = {0, +1, 0, -1};

int bfs(int x, int y)
{
	int fuck = (int) grid[x][y] - 'A' + 1;
	int val = fuck * q;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ax[i][j] = 1000007;

	queue < pair < pair <int, int>, int > > q;
	ax[x][y] = 1;
	q.p(mp(mp(x, y), 1));

	while(!q.empty())
		{
			pair < pair <int, int>, int > pz;
			pz = q.front();

			int u = pz.f.f, v = pz.f.s, d = pz.s;

			q.pop();

			for(int i = 0; i < 4; i++)
				{
					int x1 = u + f1[i], y1 = v + f2[i];

					if(x1 && x1 <= n && y1 && y1 <= m)
						{
							if(grid[x1][y1] != '*')
								{
									if(ax[x1][y1] > d + 1)
										{
											ax[x1][y1] = d + 1;
											q.p(mp(mp(x1, y1), d + 1));
										}
								}
						}
				}
		}


	for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				if(ax[i][j] < 100007)
					{					

						int f = p2[ax[i][j]];
						int val2 = (int) floor(val / f);
						ans[i][j] += val2;
					}
		}

	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int p, i, j, ansv = 0;

		p2[1] = 1;
		for(int i = 2; i < 107; i++) p2[i] = 2 * p2[i - 1];

		cin >> n >> m >> q >> p;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				cin >> grid[i][j];

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				if(grid[i][j] >= 'A' && grid[i][j] <= 'Z')
					bfs(i, j);

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				if(ans[i][j] > p)
					ansv++;

		cout << ansv << endl;
		
		return 0;
	}