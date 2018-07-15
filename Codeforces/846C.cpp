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

int a[5007], pref[5007], dp[5007][5007], dp2[5007][5007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i];
		pref[0] = a[0];
		for(i = 1; i < n; i++) pref[i] = pref[i - 1] + a[i];

		for(i = 0; i < n; i++)
			{
				int ans = LLONG_MIN;

				for(j = i + 1; j < n; j++)
					{ 
						int x = (pref[j - 1] - pref[i]) + (pref[])
					}
			}
		return 0;
	}