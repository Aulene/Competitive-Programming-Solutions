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

vector < pair < pair <int, int>, pair <int, int> > > v;

bool cmp(pair < pair <int, int>, pair <int, int> > a, pair < pair <int, int>, pair <int, int> > b)
{
	if(a.s != b.s)
		{
			if(a.s.f != b.s.f)
				return a.s.f < b.s.f;
			return a.s.s < b.s.s;
		}
	else
		{
			if(a.f.f != b.f.f)
				return a.f.f < b.f.f;
			return a.f.s < b.f.s;
		}
}

bool intersect(pair < pair <int, int>, pair <int, int> > a, pair < pair <int, int>, pair <int, int> > b)
{
	if(b.f > a.f || b.s < a.s)
		return 1;
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, u1, v1, u2, v2;
		int ans = 0, inthere = 0;
		vector < pair < pair <int, int>, pair <int, int> > > :: iterator it, it2;
		pair < pair <int, int>, pair <int, int> > a, b;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> u1 >> v1 >> u2 >> v2;
				v.pb(mp(mp(u1, v1), mp(u2, v2)));
			}

		sort(v.begin(), v.end(), cmp);

		// for(it = v.begin(); it != v.end(); it++)
		// 	{
		// 		a = *it;
		// 		cout << a.f.f << " " << a.f.s << " " << a.s.f << " " << a.s.s << endl;
		// 	}

		for(i = 0; i < n - 1; i++)
			{
				a = v[i], b = v[i + 1];

				// cout << "OPEN" << endl;
				// cout << a.f.f << " " << a.f.s << " " << a.s.f << " " << a.s.s << endl;
				// cout << b.f.f << " " << b.f.s << " " << b.s.f << " " << b.s.s << endl;
				// cout << "CLOSE" << endl;

				if(intersect(a, b))
					inthere++;
				else
					inthere = 0;
				// cout << inthere << endl;

				ans = max(ans, inthere);
			}

		cout << ans << endl;	

		return 0;
	}