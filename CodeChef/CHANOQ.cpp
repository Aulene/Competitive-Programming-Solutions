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

int a[100007], num[100007], pref[100007];
vector < pair <int, int> > vs;

void clr()
{
	for(int i = 0; i < 100007; i++)
		{
			num[i] = 0;
			pref[i] = 0;
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, m, q, u, v, ans;

		cin >> t;

		while(t--)
			{
				cin >> n;

				for(i = 0; i < n; i++)
					{
						cin >> u >> v;
						vs.pb(mp(u, v));
					}

				cin >> q;

				while(q--)
					{
						clr();
						ans = 0;

						cin >> m;
						for(i = 0; i < m; i++)
							cin >> a[i], num[a[i]]++;

						// for(i = 0; i <= 5; i++) cout << num[i] << " ";
						// 	cout << endl;						

						for(i = 0; i < 100007; i++) pref[i] = pref[i - 1] + num[i];

						// for(i = 0; i <= 5; i++) cout << pref[i] << " ";
						// 	cout << endl;

						for(i = 0; i < vs.size(); i++)
							{
								u = vs[i].f, v = vs[i].s;
								// cout << v << " " << u << " " << pref[v] - pref[u - 1] << endl;
 								if((pref[v] - pref[u - 1]) % 2 == 1) ans++;
							}

						cout << ans << endl;
					}

				vs.clear();
			}
		return 0;
	}