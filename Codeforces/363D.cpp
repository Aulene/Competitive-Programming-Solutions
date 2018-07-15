#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007], b[100007];
int n, m, ax;

pair <int, int> run(int val)
{
	int ans = 0, j = 0, budget = ax, pm = 0;

	// cout << "fuck " << val << endl;

	for(int i = n - 1 - val; i < n; i++)
		{
			int u = budget + a[i];
			
			int diff = u - b[j];

			// cout << u << " " << diff << endl;

			if(diff >= 0) {
				// cout << "hanji\n";

				if(budget >= b[j]) {
					budget -= b[j];
					ans++;
				}
				else {
					pm += abs(budget - b[j]);
					// cout << "ugh\n";
					int fuck = a[i] - b[j];
					budget = 0;
					ans++;
				}
			}
			else {
				break;
			}

			j++;
		}

	// cout << val << " " << ans << endl;

	if(ans >= val) return mp(1, pm);
	return mp(0, 0);
}

pair <int, int> bsearch()
{
	int low = 0, high = n - 1, mid;
	pair <int, int> ans = mp(0, 0);

	while(low <= high)
		{
			mid = (low + high) / 2;
			pair <int, int> fx = run(mid);

			if(fx.f) {
				ans = fx;
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, u, v;

		cin >> n >> m >> ax;

		for(i = 0; i < n; i++) cin >> a[i];
		for(i = 0; i < m; i++) cin >> b[i];

		sort(a, a + n);
		sort(b, b + m);

		pair <int, int> ans = bsearch();

		cout << ans.f + 1 << " " << ans.s << endl;

		return 0;
	}