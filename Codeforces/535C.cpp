#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int l, t, m, a, b;

int check(int r)
{
	int v = a + (r - 1) * b;

	if(v > t) return 0;

	int sum = a * (r - l + 1);
	sum = sum + b * (((r * (r - 1)) / 2) - (((l - 1) * (l - 2)) / 2));

	if(sum > t * m) return 0;

	return 1; 
}

int binarySearch()
{
	int low = l, high = 1000000, mid, ans = -1;

	while(low <= high)
		{
			mid = (low + high) / 2;

			if(check(mid)) {
				ans = mid;
				low = mid + 1;
			}
			else high = mid - 1;

			// cout << low << " " << high << " " << ans << endl;
		}

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;

		cin >> a >> b >> n;

		while(n--)
			{
				cin >> l >> t >> m;
				cout << binarySearch() << endl;
			}

		return 0;
	}