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

int dp[5007];
vector <int> vs;
unordered_map <int, int> mx;
vector < pair <int, int> > ans;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v = 1;

		cin >> n;

		dp[2] = 1; j = 2;
		vs.pb(dp[2]);
		for(i = 3; i < 5007; i++, j++) dp[i] = dp[i - 1] + j, vs.pb(dp[i]), mx[dp[i]] = i;

		while(n)
			{
				vector <int> :: iterator it = upper_bound(vs.begin(), vs.end(), n);
				it--;

				u = it - vs.begin() + 1;
				// cout << u << endl;

				for(i = v; i <= v + u; i++)
					{
						if(i == v + u) ans.pb(mp(v, v + u));
						else ans.pb(mp(i, i + 1));
					}

				v += u + 1;
				n -= *it;
				if(n) ans.pb(mp(v - 1, v));
			}

		cout << v - 1 << " " << ans.size() << endl;
		for(i = 0; i < ans.size(); i++) cout << ans[i].f << " " << ans[i].s << endl;

		return 0;
	}