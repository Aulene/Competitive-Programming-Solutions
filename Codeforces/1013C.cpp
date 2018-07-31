#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair <int, int> > vs;
int a[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, n2, m, i, j, u, v, ans = 1000000000000000000;
		cin >> n;

		n2 = 2 * n;

		for(i = 0; i < n2; i++) cin >> a[i];

		sort(a, a + n2);

		// for(i = 0; i < n2; i++) cout << a[i] << " "; cout << endl;

		int p1 = 0, p2 = n - 1, p3 = n, p4 = n2 - 1;

		p1 = 0, p2 = n - 1, p3 = n, p4 = n2 - 1;

		ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);

		for(i = 1; i + n - 1 < 2 * n - 1; i++)
		    ans = min(ans, (a[i + n - 1] - a[i]) * 1LL * (a[2 * n - 1] - a[0]));

		cout << ans << endl;

		return 0;
	}