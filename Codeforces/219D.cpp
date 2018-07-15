#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int red[200007], d[200007];
vector < vector < pair <int, int> > > vs(200007);
vector <int> ans;
int redEntire;

int dfs(int idx, int p, int dist, int rp)
{
	d[idx] = dist;
	red[idx] = rp;

	int ans = 0, u, v;
	pair <int, int> pz;

	for(int i = 0; i < vs[idx].size(); i++)
		{
			pz = vs[idx][i];
			u = pz.f, v = pz.s;

			if(u != p)
				{
					if(v == 1)
						{
							redEntire++;
							ans++;
							dfs(u, idx, dist + 1, rp + 1);
						}
					else
						dfs(u, idx, dist + 1, rp);
				}
		}

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ansx = mod;

		cin >> n;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				vs[u].pb(mp(v, 0));
				vs[v].pb(mp(u, 1));
			}

		dfs(1, 0, 0, 0);

		for(i = 1; i <= n; i++)
			{
				// cout << i << " " << red[i] << endl;

				// cout << i << " " << redEntire - 2 * red[i] + d[i] << endl;
				ansx = min(ansx, redEntire - 2 * red[i] + d[i]);
			}

		cout << ansx << endl;
		for(i = 1; i <= n; i++)
			if(redEntire - 2 * red[i] + d[i] == ansx)
				cout << i << " ";
		cout << endl;	

		return 0;
	}