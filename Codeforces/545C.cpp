#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int x[100007], h[100007];

bool intersect(int x1, int y1, int x2, int y2)
{
	if(x2 <= x1 && x1 <= y2) return 0;
	if(x2 <= y1 && y1 <= y2) return 0;
	if(x1 <= x2 && x2 <= y1) return 0;
	if(x1 <= y2 && y2 <= y1) return 0;
	return 1;	
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, l, r, el, er, ans = 1;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> x[i] >> h[i];
		el = x[1] - h[1], er = x[1];

		for(i = 2; i <= n; i++)
			{
				// cout << endl;
				// cout << i << " " << el << " " << er << endl;

				l = x[i] - h[i], r = x[i];

				// cout << l << " " << r << endl;

				if(intersect(l, r, el, er)) {
					ans++;
					el = l;
					er = r;

					// cout << i << " " << el << " " << er << endl;
					continue;
				}

				l = x[i], r = x[i] + h[i];

				if(intersect(l, r, x[i + 1], x[i + 1])) {
					ans++;
					el = l;
					er = r;

					// cout << i << " " << el << " " << er << endl;
					continue;
				}

				el = min(x[i], el);
				er = max(x[i], er);
			}

		cout << ans << endl;

		return 0;
	}