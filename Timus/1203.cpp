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

bool cmp(pair <int, int> a, pair <int, int> b)
{
	if(a.s != b.s) return a.s < b.s;
	return a.f < b.f;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, u, v, i, j;
		int ans = 1, cur;

		cin >> n;

		for(i = 1; i <= n; i++)
			{
				cin >> u >> v;
				vs.pb(mp(u, v));
			}

		sort(vs.begin(), vs.end(), cmp);
		
		cur = vs[0].s;

		for(i = 1; i < n; i++)
			{
				// cout << vs[i].f << " " << vs[i].s << endl;

				if(vs[i].f > cur)
					{
						ans++;
						cur = vs[i].s;
					}
			}

		cout << ans << endl;
		return 0;
	}
