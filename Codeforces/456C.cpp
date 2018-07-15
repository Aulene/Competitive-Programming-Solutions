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

int a[100007], dp[100007], num[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, ans;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i], num[a[i]]++;

		dp[1] = num[1];

		for(i = 2; i <= 100000; i++)
			{
				dp[i] = max(num[i] * i + dp[i - 2], dp[i - 1]);
			}

		cout << dp[100000] << endl;

		return 0;
	}