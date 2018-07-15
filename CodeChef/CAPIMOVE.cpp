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

int a[50007];
vector < vector <int> > g(100007);
vector < pair <int, int> > vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v, w;

		cin >> t;

		while(t--)
			{
				cin >> n;

				for(i = 1; i <= n; i++) cin >> a[i], vs.pb(mp(a[i], i));

				for(i = 0; i < n - 1; i++)
					{
						cin >> u >> v;
						g[u].pb(v); g[v].pb(u);
					}

				sort(vs.begin(), vs.end());
			}
		return 0;
	}