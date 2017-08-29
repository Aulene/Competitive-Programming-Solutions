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

map <int, bool> M[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;
		bool ans = 0;

		cin >> n >> m;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				M[u][v] = M[v][u] = 1;
			}

		for(i = 1; i <= n; i++)
			if(M[1][i] && M[i][n])
				ans = 1;

		if(ans) cout << "POSSIBLE\n";
		else cout << "IMPOSSIBLE\n";
		return 0;
	}