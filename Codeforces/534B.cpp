#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int v1, v2, t, d;
int dp[1107][1107];

int recur(int speed, int time)
{
	if(time == t) {
		if(speed == v2)
			return v2;
		return -100007;
	}

	if(dp[speed][time] != -1) 
		return dp[speed][time];

	int ans = -mod;

	for(int i = 0; i <= d; i++)
		ans = max(ans, speed + recur(speed + i, time + 1));
	for(int i = 0; i <= min(d, speed); i++)
		ans = max(ans, speed + recur(speed - i, time + 1));

	return dp[speed][time] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, u, v, ans;

		for(i = 0; i < 1107; i++)
			for(j = 0; j < 1107; j++) dp[i][j] = -1;

		cin >> v1 >> v2 >> t >> d;

		ans = recur(v1, 1);
		cout << ans << endl;
		
		return 0;
	}