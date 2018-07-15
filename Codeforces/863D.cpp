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

vector < pair < pair <int, int>, int> > qs;
int a[200007];

int shift(int l, int r, int pos)
{
	if(pos == l) return r;
	else return pos - 1;
}

int reverse(int l, int r, int pos)
{
	return r - (pos - l);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, q, m, i, j, u, v, w, ans;

		cin >> n >> q >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= q; i++)
			{
				cin >> u >> v >> w;
				qs.pb(mp(mp(u, v), w));
			}

		reverse(qs.begin(), qs.end());

		for(i = 1; i <= m; i++)
			{
				cin >> w;
				
				ans = w;

				for(j = 0; j < q; j++)
					{
						int l = qs[j].f.s, r = qs[j].s;

						if(qs[j].f.s == 1)
							{
								if(ans > l && ans <= r) ans--;
								else if(ans == l) ans = r;
							}
						else if(l <= ans && ans <= r) ans = r - (ans - l);

					}
				cout << ans << " " << a[ans] << endl;
			}
		return 0;
	}