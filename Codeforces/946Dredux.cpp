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

int n, m, k, pref[507];
string s[507];
int dp[507][507][507][2];

int recur(int i, int j, int thisK, int bs)
{
	if(dp[i][j][thisK][bs] != -1) return dp[i][j][thisK][bs];

	if(i >= n) return dp[i][j][thisK][bs] = 0;

	if(j > pref[i]) return dp[i][j][thisK][bs] = recur(i + 1, 0, thisK, 0);

	int ans;

	if(s[i][j] == '0')
		{
			if(bs == 0)
				{
					if(j != m - 1) ans = recur(i, j + 1, thisK, 0);
					else ans = recur(i + 1, 0, thisK, 0);
				}
			else
				{
					if(j != m - 1) ans = 1 + recur(i, j + 1, thisK, 1);
					else ans = 1 + recur(i + 1, 0, thisK, 0);
				}
		}
	else
		{
			if(bs == 1)
				{
					if(j != m - 1)
						ans = 1 + recur(i, j + 1, thisK, 1); 
					else
						ans = 1 + recur(i + 1, 0, thisK, 0);

					if(thisK >= (pref[i] + 1 - j))
						ans = min(ans, recur(i + 1, 0, thisK - (pref[i] + 1 - j), 0));
				}
			else
				{
					if(j != m - 1) ans = 1 + recur(i, j + 1, thisK, 1);
					else ans = 1 + recur(i + 1, 0, thisK, 0);
					if(thisK > 0)
						{
							if(j != m - 1) ans = min(ans, recur(i, j + 1, thisK - 1,0));
							else ans = min(ans, recur(i + 1, 0, thisK - 1,0));
						}
				}
		}

	return dp[i][j][thisK][bs] = ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i, j, ans;

	memset(dp, -1, sizeof(dp));
	memset(pref, 0, sizeof(pref));

	cin >> n >> m >> k;

	for(i = 0; i < n; i++)
		cin >> s[i];

	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			if(s[i][j] == '1')
				pref[i] = max(pref[i], j);

	ans = recur(0, 0, k, 0);
	cout << ans << endl;
	
	return 0;
}