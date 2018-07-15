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

vector <int> h;
vector < pair <int, int> > vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, tw = 0, hx, w;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> u >> v;
				vs.pb(mp(u, v));
				h.pb(v);
				tw += u;
			}

		sort(h.begin(), h.end(), greater <int>());

		for(i = 0; i < n; i++)
			{
				w = tw - vs[i].f;

				if(h[0] == vs[i].s)
					hx = h[1];
				else hx = h[0];

				cout << hx * w << " ";
			}

		return 0;
	}