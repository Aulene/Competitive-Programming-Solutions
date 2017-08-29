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

vector < pair < pair <int, int> ,  pair <int, int> > > v;

bool intersect(pair < pair <int, int> ,  pair <int, int> > a, pair < pair <int, int> ,  pair <int, int> > b)
{
	if(b.f.f >= a.s.f && b.f.f <= a.f.f) return 1;
	else if(b.s.f >= a.s.f && b.s.f <= a.f.f) return 1;
	else if(b.f.s >= a.s.s && b.f.s <= a.f.s) return 1;
	else if(b.s.s >= a.s.s && b.s.s <= a.f.s) return 1;
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, x, y, ans = 1;
		pair < pair <int, int> ,  pair <int, int> > prev;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> x >> y;
				v.pb(mp(mp(x, y), mp(x - y, x)));
			}

		sort(v.begin(), v.end());

		prev = v[0];

		for(i = 1; i < n; i++)
			{
				if(intersect(prev, v[i]))
					continue;
				else
					{
						ans++;
						prev = v[i];
					}
			}
		cout << ans << endl;

		return 0;
	}