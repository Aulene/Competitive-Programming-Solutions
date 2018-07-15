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

vector < pair < pair <int, int>, pair <int, int> > > vs;
int dp[107][2027]; // max value for first i items in j seconds

bool cmp(pair < pair <int, int>, pair <int, int> > a, pair < pair <int, int>, pair <int, int> > b)
{
	if(a.s.f == b.s.f)
		return a.s.s < b.s.s;
	return a.s.f < b.s.f;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, w;

		cin >> n;

		for(i = 0; i < 107; i++)
			for(j = 0; j < 2027; j++) dp[i][j] = -1;

		for(i = 0; i < n; i++)
			{
				cin >> u >> v >> w;
				vs.pb(mp(mp(1, u), mp(v, w)));
			}

		sort(vs.begin(), vs.end(), cmp);

		for(i = 0; i < n; i++)
			{
				for(j = 1; j <= 2007; j++)
					{
					x}
			}

		return 0;
	}