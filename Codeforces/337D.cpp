/*
Sample Input

6 2 3
1 2
1 5
2 3
3 4
4 5
5 6

3
*/

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

vector <int> g(100007);
int a[100007];
bool marked[100007], pos[100007];
int d;

int dfs(int index, int parent, int distance)
{
	if(marked[index])
		{
			
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n >> m >> d;

		for(i = 1; i <= m; i++)
			{
				cin >> u;
				marked[u] = 1;
			}

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}


		return 0;
	}