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
bool vis[100007];
int color[100007];
queue <int> q;
vector <int> ans1, ans2;

int bfs(int index)
{
	color[index] = 1;
	vis[index] = 1;

	q.p(index);

	while(!q.empty())
		{
			int u = q.front();
			q.pop();

			for(int i = 0; i < g[u].size(); i++)
				{
					int v = g[u][i];
					if(!vis[v])
						{
							vis[v] = 1;
							if(color[u] == 1) color[v] = 2;
							else color[v] = 1;
							q.p(v);
						}
					else
						{
							if(color[u] == color[v])
								{
									// cout << u << " " << v << endl;
									return 0;
								} 
						}
				}
		}

	return 1;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;
		bool ans = 1;

		cin >> n >> m;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				g[u].pb(v), g[v].pb(u);
			}

		for(i = 1; i <= n; i++)
			if(!vis[i])
				{
					if(!bfs(i)) ans = 0;
				}

		for(i = 1; i <= n; i++)
			if(color[i] == 1) ans1.pb(i);
			else ans2.pb(i);

		if(ans)
			{
				cout << ans1.size() << endl;
				for(i = 0; i < ans1.size(); i++) cout << ans1[i] << " "; cout << endl;
				cout << ans2.size() << endl;
				for(i = 0; i < ans2.size(); i++) cout << ans2[i] << " "; cout << endl;
			}
		else 
			cout << "-1\n";
		
		return 0;
	}