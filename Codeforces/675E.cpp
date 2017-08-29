#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair

int a[100007];
int dp[100007];

signed main()
	{
		int n, i, j, ans = 0;

		cin >> n;

		for(i = 0; i < 100007; i++)
			dp[i] = 0;
		dp[n - 1] = 0;

		for(i = 0; i < n - 1; i++)
			cin >> a[i];

		for(i = 1; i < n - 1; i++)
			{
				int maxIndex = 0, maxv = 0;
				for(j = i + 1; j < n - 1; j++)
					{
						if(maxv < a[j])
							{
								maxv = a[j];
								maxIndex = j;
							}
					}

				dp[i] = dp[maxIndex] - (a[i] - maxIndex) + n - i - 1;
				ans += dp[i];
			}

		for(i = 0; i < n; i++)
			cout << dp[i] << " ";
		cout << endl;
		cout << ans << endl;

		return 0;
	}