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

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int i, j, n;
	string s;

	cin >> s;
	n = s.size();

	vector < vector <int> > dp(n, vector <int> (n, 0));
	vector <int> ans(n);

	for(i = 0; i < n; i++)
		dp[i][i] = 1;

	for(i = 0; i < n; i++)
		for(j = 0; j < i; j++)
			{
				if(s[i] == s[j])
					{
						if(i - j == 1) dp[i][j] = 1;
						else if(dp[i - 1][j + 1]) dp[i][j] = 1;
					}
			}

	for(i = 1; i <= n; i++)
		{
			for(j = 0; j < n; j++)
				if(j - i + 1 >= 0)
					{
						if(dp[j][j - i + 1])
							{
								if(j - 2 * i + 1 >= 0)
									if(dp[j][j - 2 * i + 1]) dp[j][j - 2 * i + 1] = dp[j][j - i + 1] + 1;
								if(j - 2 * i >= 0)
									if(dp[j][j - 2 * i]) dp[j][j - 2 * i] = dp[j][j - i + 1] + 1;
							}
					}
		}

	for(i = 0; i < dp.size(); i++)
		for(j = 0; j < dp[i].size(); j++)
		    if(dp[i][j]) ans[dp[i][j] - 1]++;

	for(i = ans.size() - 1; i >= 0; i--)
		if(i < n - 1)
			ans[i] += ans[i + 1];

	for(i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
