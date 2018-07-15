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

int a[107];
// pair < pair <int, int>, int > dp[107][107][7];
int dp[107][107];

// pair < pair <int, int>, int> recur(int left, int right, int p1, int p2, int p)
// {
// 	if(dp[left][right][p].s != -1) return dp[left][right][p];

// 	if(left == right) return dp[left][right][p] = mp(mp(left, left), a[left]);

// 	pair < pair <int, int>, int > ans1, ans2, ans;

// 	if(p == 1)
// 		{
// 			ans1 = recur(left + 1, right, p1 + a[left], p2, 2);
// 			ans2 = recur(left, right - 1, p1 + a[right], p2, 2);
// 		}
// 	else
// 		{
// 			ans1 = recur(left + 1, right, p1, p2 + a[left], 1);
// 			ans2 = recur(left, right - 1, p1, p2 + a[right], 1);
// 		}

// 	if(ans1.s > ans2.s) ans = ans1;
// 	else ans = ans2;

// 	return dp[left][right][p] = ans;
// }

int recur(int left, int right)
{
	if(dp[left][right] != -1) return dp[left][right];
	if(left == right) return a[left];

	int ans = max(a[left] - recur(left + 1, right), a[right] - recur(left, right - 1));
	return dp[left][right] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, k, sum = 0, x;

		cin >> n;
		for(i = 1; i <= n; i++) cin >> a[i], sum += a[i];

		for(i = 0; i < 107; i++)
			for(j = 0; j < 107; j++) dp[i][j] = -1;

		// pair < pair <int, int>, int> ans = recur(1, n, 0, 0, 1);
		// cout << ans.f.f << " " << ans.f.s << " " << ans.s << endl;
		int ans = recur(1, n);

		x = (sum + ans) / 2;
		cout << x << " " << x - ans << endl;

		return 0;
	}