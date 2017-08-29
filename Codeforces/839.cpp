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

vector < vector <int> > g(200007);

double dfs(int index, int parent)
{
	double sum = 0; int c = 0;

	for(int i = 0; i < g[index].size(); i++)
		if(g[index][i] != parent)
			sum += dfs(g[index][i], index) + 1, c++;

	if(c) sum /= c;
	return sum;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, u, v, i, j, sum = 0;
		cin >> n;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		printf("%0.91f", dfs(1, 0));
		return 0;
	}