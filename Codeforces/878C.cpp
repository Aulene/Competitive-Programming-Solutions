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

vector <int> orx, andx, xorx;
vector < pair <char, int> > ans, vs;
int pos[7];
vector < pair <int, char> > order;
int orans, andans, xorans;

void compute()
{
	int u, i;

	if(orx.size())
		{
			orans = orx[0];
			for(i = 1; i < orx.size(); i++) orans = orans | orx[i];
		}		

	if(andx.size())
		{
			andans = andx[0];
			for(i = 1; i < andx.size(); i++) andans = andans & andx[i];
		}

	if(xorx.size())
		{
			xorans = xorx[0];
			for(i = 1; i < xorx.size(); i++) xorans = xorans ^ xorx[i];
		}

	sort(order.begin(), order.end());

	for(i = 0; i < order.size(); i++)
	// for(i = order.size() - 1; i >= 0; i--)
		{
			if(order[i].s == '|' && orans)
				ans.pb(mp('|', orans));
			
			if(order[i].s == '&' && andans)
				ans.pb(mp('&', andans));

			if(order[i].s == '^' && xorans)
				ans.pb(mp('^', xorans));
				
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, u, v, i, j, x, y;
		char c;

		cin >> n;

		for(i = 0; i < 7; i++) pos[i] = 777777;

		// 0 or, 1 and, 2 xor

		for(i = 0; i < n; i++)
			{
				cin >> c >> u;

				// if(c == '|') orx.pb(u), pos[0] = min(pos[0], i);
				// else if(c == '&') andx.pb(u), pos[1] = min(pos[1], i);
				// else xorx.pb(u), pos[2] = min(pos[2], i);

				if(c == '|') orx.pb(u), pos[0]++;
				else if(c == '&') andx.pb(u), pos[1]++;
				else xorx.pb(u), pos[2]++;

				vs.pb(mp(c, u));
			}

		order.pb(mp(pos[0], '|'));
		order.pb(mp(pos[1], '&'));
		order.pb(mp(pos[2], '^'));
		
		compute();

		cout << ans.size() << endl;
		for(i = 0; i < ans.size(); i++)
			cout << ans[i].f << " " << ans[i].s << endl;

		for(i = 0; i < 1024; i++)
			{
				u = i, v = i;

				for(j = 0; j < vs.size(); j++)
					if(vs[j].f == '|') u = u | vs[j].s;
					else if(vs[j].f == '^') u = u ^ vs[j].s;
					else u = u & vs[j].s;

				for(j = 0; j < ans.size(); j++)
					if(ans[j].f == '|') v = v | ans[j].s;
					else if(ans[j].f == '^') v = v ^ ans[j].s;
					else v = v & ans[j].s;
				
				if(u != v) cout << i << " " << u << " " << v << endl;
			}

		return 0;
	}