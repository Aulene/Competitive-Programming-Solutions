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

		int t, n, i, j, u, v, ans;

		cin >> t;

		while(t--)
			{
				cin >> n;

				for(i = 0; i < n; i++)
					{
						cin >> u >> v;
						vs.pb(mp(u, v));
					}

				sort(vs.begin(), vs.end(), cmp);

				// for(i = 0; i < vs.size(); i++)
				// 	cout << vs[i].f << " " << vs[i].s << endl;

				ans = 0, v = 0;

				for(i = 0; i < vs.size(); i++)
					{
						if(v <= vs[i].f)
							{
								ans++;
								v = vs[i].s;
							}
					}

				cout << ans << endl;
				vs.clear();
			}

		return 0;
	}