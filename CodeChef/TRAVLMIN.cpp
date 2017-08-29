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

bool intersect(pair <int, int> a, pair <int, int> b)
{
	if(b.f <= a.s)
		return 1;
	return 0;
}

bool cmp(pair <int, int> a, pair <int, int> b)
{
	if(a.s == b.s)
		return a.f < b.f;
	return a.s < b.s;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, d, i, j, u, v, ans = 1;
		pair <int, int> prev;
		cin >> n >> d;

		for(i = 0; i < n; i++)
			{
				cin >> u >> v;
				vs.pb(mp(u, v));
			}

		sort(vs.begin(), vs.end(), cmp);

		// for(i = 0; i < n; i++)
		// 	cout << vs[i].f << " " << vs[i].s << endl;

		prev = vs[0];

		for(i = 1; i < n; i++)
			{
				if(!intersect(prev, vs[i]))
					{
						prev = vs[i];
						ans++;
					}

				// cout << prev.f << " " << prev.s << endl;
			}

		cout << ans << endl;
		return 0;
	}