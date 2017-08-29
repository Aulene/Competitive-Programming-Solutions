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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, k, a, b, c, mid, ans;

		cin >> t;

		while(t--)
			{
				cin >> n >> a >> b;

				mid = n / 2;

				if(n % 2 == 0)
					{
						c = max(a, b) - min(a, b);
						if(c == mid)
							ans = 0;
						else
							ans = c - 1;
					}
				else
					{
						ans = max(a, b) - min(a, b) - 1;
					}

				if(ans != 0 && ans >= mid)
					ans = n - ans - 2;
				cout << ans << endl;
			}
		return 0;
	}