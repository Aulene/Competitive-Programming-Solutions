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

int a[307], b[307][307];
vector < vector <int> > g(100007);
bool vis[307], used[307];

pair <int, int> dfs(int index, int value)
{
	if(vis[index]) return 0;

	vis[index] = 1;
	pair <int, int> rval;

	for(int i = 0; i < g[index].size(); i++)
		if(!used[g[index][i]])
			{
				int u = g[index][i];

				if(a[u] < value)
					{
						value = a[u];
						rval = mp(u, a[u]);
						dfs(u, value);
					}
			}

	return rval;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, x;
		string s;
		pair <int, int> ans;

		cin >> n;

		for(i = 1; i <= n; i++)
			cin >> a[i];

		for(i = 1; i <= n; i++)
			{
				cin >> s;

				for(j = 1; j <= n; j++)
					if(s[j - 1] - '0')
						g[i].pb(j);
			}

		for(i = 1; i <= n; i++)
			{
				ans = dfs(i, a[i]);


			}

		for(i = 1; i <= n; i++) cout << a[i] << " ";
		return 0;
	}