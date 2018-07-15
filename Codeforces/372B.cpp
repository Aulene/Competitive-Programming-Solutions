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

int a[47][47], rects[47][47], dp[47][47];
vector < pair <int, int> > vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, k, l, u, v, q;
		char x;

		cin >> n >> m >> q;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				{
					cin >> x;
					
					if(x == '1') a[i][j] = 1;
					else a[i][j] = 0;
				}

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++) rects[i][j] = a[i][j] + rects[i][j - 1] + rects[i - 1][j] - rects[i - 1][j - 1];

		for(i = 1; i <= n; i++)
			for(j = 1; j <= m; j++)
				for(k = i; k <= n; k++)
					for(l = j; l <= m; l++)
						{
							if(rects[k][l] - rects[i][j] == 0)
								vs.pb(k, l);	
						}

		return 0;
	}