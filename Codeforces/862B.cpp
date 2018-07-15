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
int color[100007];
bool vis[100007];
queue <int> q;
int b = 0, w = 0, ans = 0;

int isBipartite()
{
	vis[1] = 1;
	int vs; w = 1, b = 0;
	color[1] = 1;
	q.p(1);


	while(!q.empty())
		{
			int u = q.front();
	        q.pop();

	        for(int i = 0; i < g[u].size(); i++)
		        {
		            int v = g[u][i];
		            if(!vis[v])
			            {
			                q.push(v);
			                color[v] = 1 - color[u];
			                vis[v] = 1;
			            }
		        }
		}

	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, u, v, i, j, ans = 0;

		cin >> n;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		isBipartite();

		w = 0, b = 0;

		for(i = 1; i <= n; i++)
			{
				if(color[i]) b++;
				else w++;
			}

		cout << b * w - (n - 1);

		return 0;
	}