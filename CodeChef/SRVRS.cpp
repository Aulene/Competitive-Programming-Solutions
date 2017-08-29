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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int cpus, x, y;
pair <int, int> cpu[500007];
vector < pair< int, int> > ans;
signed main()
	{
		int n, q, i, j;
		int u, v, l = 0;

		cin >> n >> q;
		cin >> x >> y >> cpus;

		for(i = 0; i < cpus; i++)
			{
				cin >> cpu[i].f;
				cpu[i].s = i;
			}

		sort(cpu, cpu + cpus);

		for (i = 0; i < q; ++i)
			{
				ans.pb(mp(1, cpu[l].s + 1));
				l++;
			}
		// cout << "end" << endl;
		
		for(i = 0; i < q; i++)
			cout << ans[i].f << " " << ans[i].s << endl;

		return 0;
	}