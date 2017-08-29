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

int a[100007], b[100007], ansid = -1;
unordered_map <int, int> M, ind, vis;
vector <int> ansv[100007];

int dfs(int num)
{
	vis[num] = 1;
	ansv[ansid].pb(ind[num]);
	int idx = M[num];
	if(!vis[idx]) dfs(idx);
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, m, u, v, ans = 0;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i], b[i] = a[i];

		sort(b, b + n);

		for(i = 0; i < n; i++)
			{
				u = a[i], v = b[i];
				M[u] = v, ind[u] = i + 1;
			}

		for(i = 0; i < n; i++)
			if(!vis[a[i]])
				{
					ans++, ansid++;
					dfs(a[i]);
				}

		cout << ans << endl;
	    for(i = 0; i <= ansid; i++) 
		    {
		        cout << ansv[i].size() << " ";
		        for(j = 0; j < ansv[i].size(); j++) 
		        	cout << ansv[i][j] << " ";
		        cout << endl;
		    }

		return 0;
	}