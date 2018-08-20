#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int check(int x, int n, int k) 
{
	int u = k - x;
	if(u <= n && u != x) return 1;
	return 0;
}

int bsearch(int n, int k, int top)
{
	int low = 1, high = top, ans = 0, mid;

	while(low <= high)
		{
			mid = (low + high) / 2;

			// cout << mid << " " << check(mid, n, k) << endl;

			if(check(mid, n, k)) {
				ans = top - mid + 1;
				high = mid - 1;
			}
			else low = mid + 1;
		}
	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, k, i, j, u, v;

		cin >> n >> k;
		u = min(n, k / 2);
		v = bsearch(n, k, u);

		if(k % 2 == 0)
			{
				i = k / 2;
				if(i <= u && v) v--;
			}

		cout << v << endl;

		return 0;
	}