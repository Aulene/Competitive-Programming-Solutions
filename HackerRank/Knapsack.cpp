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

int dp[2007][2007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, k, i, j;

		cin >> t;

		while(t--)
			{
				cin >> n >> k;

				for(i = 0; i < 2007; i++)
					for(j = 0; j < 2007; j++) dp[i][j] = 0;

				for(i = 0; i < n; i++) cin >> a[i];

				
			}
		return 0;
	}