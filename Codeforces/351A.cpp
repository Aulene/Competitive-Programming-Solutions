#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define double long double
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

double a[4007];
double dp[4007][2007];
int n;

double recur(int idx, int low)
{
	if(idx > n) {
		if(low != n / 2) return mod;
		else return 0;
	}

	double ans1, ans2, ans;

	ans1 = recur(idx + 1, low + 1) + abs(floor(a[idx]) - a[idx]);
	ans2 = recur(idx + 1, low) + abs(ceil(a[idx]) - a[idx]);
	ans = min(ans1, ans2);

	return dp[idx][low] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, u, v;
		double ans;

		cin >> n;

		n = 2 * n;

		for(i = 1; i <= n; i++) cin >> a[i];

		ans = recur(1, 0);

		cout << setprecision(3) << ans << endl;
		return 0;
	}