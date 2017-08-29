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

int n, a[107], dp[107][7];

int recur(int index, int prev) // prev = 0 -> rest, prev = 1 -> contest, prev = 2 -> gym
{
	if(index > n) return 0;
	if(dp[index][prev] != -1) return dp[index][prev];

	int ans;	

	if(prev == 0)
		{
			if(a[index] == 0)
				ans = recur(index + 1, 0);
			else if(a[index] == 1)
				ans = max(1 + recur(index + 1, 2), recur(index + 1, 0));
			else if(a[index] == 2)
				ans = max(1 + recur(index + 1, 1), recur(index + 1, 0));
			else
				{
					ans = max(1 + recur(index + 1, 1), recur(index + 1, 0));
					ans = max(ans, 1 + recur(index + 1, 2));
				}
		}
	else if(prev == 1)
		{
			if(a[index] == 0 || a[index] == 2)
				ans = recur(index + 1, 0);
			else if(a[index] == 1)
				ans = max(1 + recur(index + 1, 2), recur(index + 1, 0));
			else
				ans = max(1 + recur(index + 1, 2), recur(index + 1, 0));
		}
	else if(prev == 2)
		{
			if(a[index] == 0 || a[index] == 1)
				ans = recur(index + 1, 0);
			else if(a[index] == 2)
				ans = max(1 + recur(index + 1, 1), recur(index + 1, 0));
			else
				ans = max(1 + recur(index + 1, 1), recur(index + 1, 0));
		}

	return dp[index][prev] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 0; i < 107; i++) for(int j = 0; j < 7; j++) dp[i][j] = -1;
		int ans = recur(1, 0);
		cout << n - ans << endl;
		return 0;
	}