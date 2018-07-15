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

int x[7], a[100007], dp[100007][7];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, p, q, r, i;;

		cin >> n >> p >> q >> r;

		for(i = 0; i < n; i++) cin >> a[i];

		for(i = 0; i < n; i++) 
			{
				dp[i][0] = p * a[i];
				if(i) dp[i][0] = max(dp[i - 1][0], dp[i][0]);
				
				dp[i][1] = q * a[i] + dp[i][0];
				if(i) dp[i][1] = max(dp[i - 1][1], dp[i][1]);

				dp[i][2] = r * a[i] + dp[i][1];
				if(i) dp[i][2] = max(dp[i - 1][2], dp[i][2]);
			}

		cout << dp[n - 1][2] << endl;
		
		return 0;
	}