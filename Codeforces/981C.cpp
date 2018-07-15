#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < vector <int> > g(100007);
vector < pair <int, int> > vs;
bool ans = 1;
int num = 0, ass = 1;

void check(int idx, int p)
{
	if(g[idx].size() > 2)
		{      
			num++;
			ass = idx;
		}

	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i] != p)
			check(g[idx][i], idx);
}

void dfs(int idx, int p)
{
	if(g[idx].size() == 1)
		{
			if(g[idx][0] == p)
				{
					vs.pb(mp(ass, idx));
					return;
				}
		}

	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i] != p)
			dfs(g[idx][i], idx);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;

		cin >> n;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		check(1, 0);

		if(num >= 2) ans = 0;

		if(!ans) cout << "No\n";
		else
			{
				dfs(ass, 0);
				cout << "Yes" << endl << vs.size() << endl;
				for(int i = 0; i < vs.size(); i++) cout << vs[i].f << " " << vs[i].s << endl;
			}

		return 0;
	}