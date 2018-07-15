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

int k, dp[507][57];

int recur(int s, int n)
{
	if(n == k)
		{
			if(s == 0) return 1;
			else return 0;
		}

	if(dp[s][n] != -1) return dp[s][n];

	int ans = 0;
	
	for(int i = 0; i <= 9; i++)
		if(s - i >= 0) 
			ans += recur(s - i, n + 1);

	return dp[s][n] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, s, i, j, ans = 0;

		cin >> s;
		k = 9;

		for(i = 0; i < 507; i++)
			for(j = 0; j < 57; j++) dp[i][j] = -1;

		ans = recur(s, 0);
		if(s == 1) ans++;

		cout << ans << endl;

		return 0;
	}