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
#define f first
#define s second

vector <lli> g[207];
vector < pair <lli, lli> > rds;
lli r1, r2, n;


pair <lli, lli> bfs(lli u, lli r)
{
	lli dis[207];
	lli v, node, maxdis = 0, lmfao;
	memset(dis, -1, sizeof(dis));
	pair <lli, lli> ans;

	queue <lli> q;
	q.push(u);

	dis[u] = 0;

	while(!q.empty())
		{
			v = q.front();
			q.pop();

			for(vector <lli> :: iterator it = g[v].begin(); it != g[v].end(); it++)
				{
					lmfao = *it;

					if(dis[lmfao] == -1 && lmfao != r)
						{
							q.push(lmfao);
							dis[lmfao] = dis[v] + 1;
						}
				}
		}

	for(lli i = 1; i <= n; i++)
		if(max(dis[i], maxdis) == dis[i])
			{
				maxdis = dis[i];
				node = i;
			}
	ans = mp(node, maxdis);
	return ans;
}

int main()
	{
		lli u, v, i, j, ans = 0;
		lli ans1, ans2;

		cin >> n;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
				rds.pb(mp(u, v));
			}

		for(i = 0; i < rds.size(); i++)
			{
				r1 = rds[i].f;
				r2 = rds[i].s;
				
				pair <lli, lli> node1 = bfs(r1, r2), node2 = bfs(r2, r1);
				pair <lli, lli> ans1 = bfs(node1.f, r2), ans2 = bfs(node2.f, r1);

				ans = max(ans, ans1.s * ans2.s);
			}

		cout << ans << endl;

		return 0;
	}