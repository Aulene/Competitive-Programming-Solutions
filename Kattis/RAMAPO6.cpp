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

int ans[107][17];
vector < vector <int> > g(107);

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, s, t, u, v, i, j, k, ansx = 0;

		cin >> n >> m >> s >> t;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		ans[s][0] = 1;

		for(i = 0; i < t; i++)
			{
				for(j = 0; j < n; j++)
					for(k = 0; k < g[j].size(); k++)
						ans[g[j][k]][i + 1] += ans[j][i];
			}

		for(i = 0; i < n; i++)
			ansx += ans[i][t];

		cout << ansx << endl;

		return 0;
	}
