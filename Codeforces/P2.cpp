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

int t1[3007], t2[3007];
unordered_map <string, bool> m1, m2;
vector <string> vs1, vs2;
vector < vector <int> > g1(3007), g2(3007);

void dfs(int idx, int parent, string s)
{
	for(int i = 0; i < g1[idx].size(); i++)
		{
			int u = g1[idx][i];

			if(u != parent)
				{
					string s1 = s;
					s1 += t1[u];

					if(m1[s1] == 0)
						{
							m1[s1] = 1;
							vs1.pb(s1);
						}

					dfs(u, idx, s1);
				}
		}
}

void dfs2(int idx, int parent, string s)
{
	for(int i = 0; i < g2[idx].size(); i++)
		{
			int u = g2[idx][i];

			if(u != parent)
				{
					string s1 = s;
					s1 += t1[u];

					if(m1[s1] == 0)
						{
							m2[s1] = 1;
							vs2.pb(s1);
						}

					dfs2(u, idx, s1);
				}
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;
		string ans = "";

		cin >> n;

		for(i = 1; i <= n; i++) cin >> t1[i];
		for(i = 1; i <= n; i++) cin >> t2[i];

		for(i = 1; i < n; i++)
				{
					cin >> u >> v;
					g1[u].pb(v);
					g1[v].pb(u);
				}
		
		for(i = 1; i < n; i++)
				{
					cin >> u >> v;
					g2[u].pb(v);
					g2[v].pb(u);
				}

		for(i = 1; i <= n; i++)
			dfs(i, 0, ""), dfs2(i, 0, "");
		
		for(i = 0; i < vs1.size(); i++)
			for(j = 0; j < vs2.size(); j++)
				if(vs1[i] == vs2[j])
					if(ans.size() < vs1[i].size()) ans = vs1[i];
		
		cout << ans << endl;

		return 0;
	}