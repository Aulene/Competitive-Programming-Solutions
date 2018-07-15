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

vector < pair < pair <int, int>, int> > vs;
int ans[100007];

bool cmp(pair < pair <int, int>, int> a, pair < pair <int, int>, int> b) { return a.f.s < b.f.s; }

int findConf(int index)
{
	for(int i = index - 1; i >= 0; i--)
		if(vs[i].f.s <= vs[index].f.f)
			return i;
	return -1;
}

int recur(int n)
{
	ans[0] = vs[0].s;

	for(int i = 1; i < n; i++)
		{
			int u = vs[i].s;
			int j = findConf(i);

			if(j != -1) u += ans[j];

			ans[i] = max(u, ans[i - 1]);
		}

	return ans[n - 1];
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v, w;

		cin >> t;

		while(t--)
			{
				cin >> n;

				for(i = 0; i < n; i++)
					{
						cin >> u >> v >> w;
						v += u;
						vs.pb(mp(mp(u, v), w));
					}

				sort(vs.begin(), vs.end(), cmp);
				cout << recur(n) << endl;
				vs.clear();
			}

		return 0;
	}