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

vector <int> g[100007], roots;

int dfs(int u, int level)
{
	vector <int> :: iterator it;
	int ans = level;

	for(it = g[u].begin(); it != g[u].end(); it++)
		ans = max(ans, dfs(*it, level + 1));
	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, u, ans = 0;
		vector <int> :: iterator it;

		cin >> n;

		for(i = 1; i <= n; i++)
			{
				cin >> u;

				if(u == -1)
					roots.pb(i);
				else
					g[u].pb(i);
			}

		for(it = roots.begin(); it != roots.end(); it++)
			ans = max(ans, dfs(*it, 1));

		cout << ans << endl;

		return 0;
	}