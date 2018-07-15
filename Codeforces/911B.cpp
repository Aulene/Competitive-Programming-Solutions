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

// #define int long long int
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

		int n, a, b, i, j, ans = 0;

		cin >> n >> a >> b;

		for(i = 1; i < n; i++)
			{
				int x = a / i, y = b / (n - i);
				// cout << x << " " << y << endl;
				ans = max(ans, min(x, y));
			}

		cout << ans << endl;

		return 0;
	}