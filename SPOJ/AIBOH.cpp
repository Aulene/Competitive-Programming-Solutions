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

bool dp[6107][6107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, i, j, ans;
		string s1, s2;

		cin >> t;

		while(t--)
			{
				cin >> s1;
				n = s1.size();

				s2 = s1;
				reverse(s2.begin(), s2.end());
				// cout << s1 << " " << s2 << endl;

				for(i = 0; i <= n; i++) dp[i][i] = 1;

				for(i = 0; i <= n; i++)
					for(j = 0; j <= n; j++)
						if(i == 0 || j == 0) dp[i][j] = 0;
						else if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
						else dp[i][j] = 0;

				for(i = 0; i <= n; i++)
					{
						for(j = 0; j <= n; j++) cout << dp[i][j] << " "; cout << endl;
					}
				ans = dp[n][n];
				cout << n - ans << endl;
			}
		return 0;
	}