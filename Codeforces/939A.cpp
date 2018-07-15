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

int a[5007], dp[5007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i;
		bool ans = 0;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i], dp[a[i]]++;

		for(i = 1; i <= n; i++)
			{
				int x = i, b = a[i], c = a[a[i]], d = a[c];
				if(x == d && b != a[b] && c != a[c]) ans = 1;
			}

		if(ans) cout << "YES\n";
		else cout << "NO\n";
		return 0;
	}