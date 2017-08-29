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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int n, m, pies[3007];
vector <int> M;
int dp[3007][2][107][107];

int recur(int cur, int prev, int l, int r)
{
	if(dp[cur][prev][l][r] != -1) return dp[cur][prev][l][r];
	int ans = dp[cur][prev][l][r];

	if(cur == n + 1)
		{
			if(l > r) ans = 0;
			else if(prev) ans = recur(cur, 0, l + 1, r);
			else ans = recur(cur, 1, l, r - 1) + M[r];
		}
	else if(prev)
		{
			ans = recur(cur + 1, 0, l, r);
			if(l <= r) ans = max(ans, recur(cur, 0, l + 1, r));
		}
	else
		{
			ans = max(recur(cur + 1, 1, l, r) + pies[cur], recur(cur + 1, 0, l, r));
			if(l <= r) ans = max(ans, recur(cur, 1, l, r - 1) + M[r]);
		}

	return dp[cur][prev][l][r] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, u, v;

		cin >> n;
		for(i = 1; i <= n; i++) cin >> pies[i];

		cin >> m;
		memset(dp, -1, sizeof dp);
		
		for(i = 1; i <= m; i++)
			cin >> u, M.pb(u); M.pb(-10000007);	
		
		sort(M.begin(), M.end());
		u = recur(1, 0, 1, m);
		cout << u << endl;
		return 0;
	}