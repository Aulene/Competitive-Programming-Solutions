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

int a[200007], b[200007], ans[200007];
vector < pair <int, int> > vis;

bool cmp(pair <int, int> a, pair <int, int> b)
{
	if(a.f != b.f) return a.f < b.f;
	else return a.s > b.s;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n, greater <int>());

		for(i = 0; i < n; i++) 
			{
				cin >> b[i];
				vis.pb(mp(b[i], i));
			}

		sort(vis.begin(), vis.end(), cmp);

		for(i = 0; i < n; i++)
			{
				// cout << a[i] << " " << vis[i].f << " " << vis[i].s << endl;
				ans[vis[i].s] = a[i];
			}

		for(i = 0; i < n; i++) cout << ans[i] << " ";
		return 0;
	}