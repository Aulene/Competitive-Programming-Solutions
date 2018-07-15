#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < vector <int> > g(7);
int ans[100007];

void bfs()
{
	queue < pair < pair <int, int>, int> > q;
	q.p(mp(mp(1, 0), 0));

	while(!q.empty())
		{
			pair < pair <int, int>, int> pz = q.front();
			q.pop();

			int u = pz.f.f, v = pz.f.s, w = pz.s;

			// cout << u << endl;

			for(int i = 0; i < g[u].size(); i++)
				{
					// cout << g[u][i] << " ";
					
					int fuck = v + g[u][i];

					// cout << fuck << " " << w << endl;

					if((ans[fuck] == -1 || ans[fuck] > w + 1) && fuck <= 10000)
						{
							ans[fuck] = w + 1;
							q.p(mp(mp(g[u][i], fuck), w + 1));
						}
				}
		}

}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, i, j, u, v;

		for(int i = 0; i < 100007; i++) ans[i] = -1;

		for(i = 1; i <= 6; i++) {
			if(i != 1 && i != 6) g[1].pb(i), g[6].pb(i);
		}

		for(i = 1; i <= 6; i++) {
			if(i != 2 && i != 5) g[2].pb(i), g[5].pb(i);
		}
		
		for(i = 1; i <= 6; i++) {
			if(i != 3 && i != 4) g[3].pb(i), g[4].pb(i);
		}

		cin >> t;

		bfs();

		while(t--) 
			{
				cin >> n;
				cout << ans[n] << endl;
			}
		return 0;
	}