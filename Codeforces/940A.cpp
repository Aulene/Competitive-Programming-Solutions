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

int a[107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, d, ans = 10007;

		cin >> n >> d;
		for(i = 0; i < n; i++) cin >> a[i];

		sort(a, a + n);

		for(i = 0; i <= n - 1; i++)
			for(j = n - 1; j >= i; j--)
				if(a[j] - a[i] <= d)
					{
						// cout << i << " " << j << " " << n - j + i - 1 << endl;
						ans = min(ans, n - j + i - 1);
					}

		cout << ans << endl;
		return 0;
	}