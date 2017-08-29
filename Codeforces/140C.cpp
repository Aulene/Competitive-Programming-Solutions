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

vector < pair < pair <int, int>, int> > ans;
bool taken[100007];
unordered_map <int, int> locs;
int a[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, k;
		int x, y, z;

		cin >> n;
		for(i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);

		for(i = n - 1; i >= 0; i--)
			if(!taken[i])
				{
					x = a[i];

					j = i - 1;
					while((taken[j] || a[i] == a[j]) && j >= 0) j--;

					if(taken[j] || j < 0) break;
					y = a[j], taken[j] = 1;

					while((taken[j] || y == a[j]) && j >= 0) j--;

					if(taken[j] || j < 0) break;
					z = a[j], taken[j] = 1;

					if(x != y && y != z && x != z)
						ans.pb(mp(mp(x, y), z));
				}

			cout << ans.size() << endl;
			for(i = 0; i < ans.size(); i++) cout << ans[i].f.f << " " << ans[i].f.s << " " << ans[i].s << endl;
		return 0;
	}