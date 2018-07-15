#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair

lli a[1000007];
bool visited[1000007];
vector <lli> g[1000007];

lli dfs(lli index, lli parent)
{
	if(visited[index])
		return 0;

	visited[index] = 1;

	lli ans = 0, v;
	vector <lli> :: iterator it;

	if(parent != -1)
		{
			for(it = g[index].begin(); it != g[index].end(); it++)
				{
					v = *it;
					if(v != parent)
						ans += dfs(v, index);
				}

			return ans + a[index];
		}
	else	
		{
			for(it = g[index].begin(); it != g[index].end(); it++)
				{
					v = *it;
					if(v != parent)
						ans = max(dfs(v, index), ans);
				}

			return ans;
		}
}

int main()
	{
		int n, i, u, v;
		lli x, ansMax = INT_MAX, ans;

		cin >> n;

		for(i = 0; i < n; i++)
			cin >> a[i];

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		for(i = 0; i < n; i++)
				{
					memset(visited, 0, sizeof(visited));
					x = dfs(i, -1);
					//cout << x << endl;

					if(x < ansMax)
						{
							ansMax = x;
							ans = i;
						}
				}

		cout << ans << endl;
		return 0;
	}