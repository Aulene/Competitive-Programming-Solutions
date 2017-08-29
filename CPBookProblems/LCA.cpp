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

vector < vector <int> > g(100007);
pair <int, int> always[200007]; bool vis[100007];
int l = 0;

int dfs(int index, int depth)
{
	// cout << index << " ";
	if(vis[index]) return 0;

	vis[index] = 1;
	always[l++] = mp(index, depth);

	for(int i = 0; i < g[index].size(); i++)
		{
			dfs(g[index][i], depth + 1);
			// cout << index << " " << g[index][i] << endl;
			always[l++] = mp(index, depth);
		}

	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v, q;

		cin >> t;

		while(t--)
			{
				for(i = 0; i < 100007; i++) vis[i] = 0;

				cin >> n;

				for(i = 1; i <= n; i++)
					{
						cin >> u;
						for(i = 0; i < u; i++)
							cin >> v, g[u].pb(v);
					}

				dfs(1, 1);

				cin >> q;

				while(q--)
					{
						
					}
			}


		return 0;
	}