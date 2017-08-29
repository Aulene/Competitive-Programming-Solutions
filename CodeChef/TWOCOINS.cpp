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

vector < vector <int> > g;
int dp[100007][2][2][2]; // dp[node][color][parent][parent's parent]

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v;

		cin >> t;

		while(t--)
			{
				cin >> n;

				for(i = 0; i < n - 1; i++)
					cin >> u >> v, g[u].pb(v), g[v].pb(u);

			}	

		return 0;
	}