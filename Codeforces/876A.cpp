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

int g[7][7];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, a, b, c, ans = 0, u;

		cin >> n;

		cin >> a >> b >> c;

		g[1][2] = g[2][1] = a;
		g[1][3] = g[3][1] = b;
		g[2][3] = g[3][2] = c;

		int idx = 1;

		n--;

		while(n)
			{
				int ansx = INT_MAX;

				for(int i = 1; i <= 3; i++)
					if(i != idx)
						{
							if(ansx > g[i][idx])
								{
									ansx = g[i][idx];
									u = i;
								}
						}

				n--;
				idx = u;
				ans += ansx;

				// cout << ansx << " " << u << endl;
			}

		cout << ans << endl;
		return 0;
	}