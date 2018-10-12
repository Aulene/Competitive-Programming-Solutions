#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int >

int bs(int L, int v)
{
	int low = 1, mid, high = L, ans = 0;

	while(low <= high) {
		mid = (low + high) / 2;
		int u = v * mid;

		if(u <= L) {
			ans = mid;
			low = mid + 1; 
		}
		else high = mid - 1;
	}

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
        cout.tie(NULL);

        int n, m, i, j, u, v;
		int t, L, l, r;

		cin >> t;

		while(t--) {
			cin >> L >> v >> l >> r;

			int tot = bs(L, v);
			u = bs(l - 1, v);
			j = bs(r, v);

			// cout << tot << " " << u << " " << j << endl;

			j = j - u;
			int ans = tot - j;

			cout << ans << endl;

		}

		return 0;   
	}