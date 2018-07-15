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

int a[57];
int dp[57][57];
int n;

int recur(int index, int d)
{
	if(index == n) return 0;
	if(dp[index][d] != -1) return dp[index][d];

	int ans = 0;

	if(d == 1) ans = max(a[index] + recur(index + 1, 2), recur(index + 1, 1));
	else ans = min(a[index] + recur(index + 1, 2), recur(index + 1, 1));
	return dp[index][d] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, u, v, sum = 0, ans;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i], sum += a[i];
		for(i = 0; i < 57; i++)
			for(j = 0; j < 57; j++) dp[i][j] = -1;

		// sort(a, a + n);

		ans = recur(0, 1);

		cout << sum - ans << " " << ans << endl;

		return 0;
	}