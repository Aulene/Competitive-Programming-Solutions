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
int vis[30007];
int n;

int dfs(int index, int dd)
{
	for(int i = 0; i < n; i++)
		if(index != i)
			{
				if(abs(vs[index].f - vs[i].f) + abs(vs[index].s - vs[i].s) >= dd && !vis[i])
					{
						vis[i] = 1;
						dfs(i, dd);
					}
			}

	return 0;
}

int check(int dd)
{
	int anshere = 1, i, j;

	for(j = 0; j <= n; j++)
		vis[j] = 0;

	dfs(0, dd);

	for(j = 0; j < n; j++)
		anshere = min(anshere, vis[j]);
	
	return anshere;
}

int binarysearch(int dd)
{
	int low = 1, high = dd, mid, ans;

	while(low <= high)
		{
			mid = (low + high) / 2;

			if(check(mid))
				{
					ans = mid;
					low = mid + 1;
				}
			else
				{
					high = mid - 1;
				}
		}

	return ans;
}
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, i, j, u, v, ans, d;

		cin >> t;

		while(t--)
			{
				vs.clear();
				d = 0;
				cin >> n;

				for(i = 0; i < n; i++)
					{
						cin >> u >> v;
						vs.pb(mp(u, v));
					}

				for(i = 0; i < n; i++)
					for(j = 0; j < n; j++)
						d = max(d, abs(vs[i].f - vs[j].f) + abs(vs[i].s - vs[j].s));

				ans = binarysearch(d);
				cout << ans << endl;
			}

		return 0;
	}