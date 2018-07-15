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

vector < pair <int, int> > vs;
int a[1007];
long double d[1007][1007], dp[1007][1007];
int n;

long double dist(int x1, int y1, int x2, int y2) { return (long double) sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2)); }

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, i, j, u, v, w;

		cin >> t;

		while(t--)
			{
				vs.clear();

				ans = 0;
				
				vs.pb(mp(-1, -1));

				cin >> n;

				for(i = 0; i < n; i++)
					{
						cin >> u >> v;
						vs.pb(mp(u, v));
					}

				sort(vs.begin(), vs.end());

				for(i = 1; i <= n; i++) cin >> a[i];

				for(i = 1; i <= n; i++)
					for(j = 1; j <= n; j++)
						d[i][j] = dist(vs[i].f, vs[i].s, vs[j].f, vs[j].s);

				for(i = 1; i <= n; i++)
					{
						for(j = 1; j <= n; j++)
							{
								
							}
					}
			}
		return 0;
	}