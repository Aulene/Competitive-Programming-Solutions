#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[2007][2007], dr[2007][2007], dl[2007][2007], dp[2007][2007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, k, u, v, sum = 0;
		int ans = 0;
		int oddRowEvenCol = 0, oddRowOddCol = 0, evenRowOddCol = 0, evenRowEvenCol = 0;
		pair <int, int> p1, p2, p3, p4;
		pair < pair <int, int>, pair <int, int> > ansx = mp(mp(1, 1), mp(1, 2));

		cin >> n;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++) cin >> a[i][j];

		for(i = 0; i < 2007; i++)
			for(j = 0; j < 2007; j++)
				dl[i][j] = dr[i][j] = dp[i][j] = -1;
		
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				if(dr[i][j] == -1)
					{
						if(dr[i - 1][j - 1] != -1) {
							dr[i][j] = dr[i - 1][j - 1];
							continue;
						}

						sum = 0;

						for(k = 0; (((1 <= i + k) && (i + k <= n)) && ((1 <= j + k) && (j + k <= n))); k++)
							sum += a[i + k][j + k];
						dr[i][j] = sum;
					}

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				if(dl[i][j] == -1)
					{
						if(dl[i - 1][j + 1] != -1) {
							dl[i][j] = dl[i - 1][j + 1];
							continue;
						}

						sum = 0;

						for(k = 0; (((1 <= i + k) && (i + k <= n)) && ((1 <= j - k) && (j - k <= n))); k++)
							sum += a[i + k][j - k];
						dl[i][j] = sum;
					}


		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++) dp[i][j] = dr[i][j] + dl[i][j] - a[i][j];
		
		// oddRowEvenCol, oddRowOddCol, evenRowOddCol, evenRowEvenCol;
		
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				{
					// FUCK THIS
						
					if(i % 2 == 1 && j % 2 == 0) {
						if(dp[i][j] > oddRowEvenCol) {
							oddRowEvenCol = dp[i][j];
							p1 = mp(i, j);
						}
					}
					
					if(i % 2 == 1 && j % 2 == 1) {
						if(dp[i][j] > oddRowOddCol) {
							oddRowOddCol = dp[i][j];
							p2 = mp(i, j);
						}
					}

					if(i % 2 == 0 && j % 2 == 1) {
						if(dp[i][j] > evenRowOddCol) {
							evenRowOddCol = dp[i][j];
							p3 = mp(i, j);
						}
					}

					if(i % 2 == 0 && j % 2 == 0) {
						if(dp[i][j] > evenRowEvenCol) {
							evenRowEvenCol = dp[i][j];
							p4 = mp(i, j);
						}
					}
				}

		// oddRowEvenCol, oddRowOddCol, evenRowOddCol, evenRowEvenCol;

		// 1 -> 2, 4
		// 2 -> 1, 3
		// 3 -> 2, 4
		// 4 -> 1, 3
		
		if(ans < oddRowEvenCol + evenRowEvenCol) {
			ans = oddRowEvenCol + oddRowOddCol;
			ansx = mp(p1, p2);
		}
		
		if(ans < oddRowEvenCol + evenRowEvenCol) {
			ans = oddRowEvenCol + evenRowEvenCol;
			ansx = mp(p1, p4);
		}
		
		if(ans < oddRowOddCol + evenRowOddCol) {
			ans = oddRowOddCol + evenRowOddCol;
			ansx = mp(p2, p3);
		}

		if(ans < evenRowOddCol + evenRowEvenCol) {
			ans = evenRowEvenCol + evenRowOddCol;
			ansx = mp(p3, p4);
		}

		cout << ans << endl;
		cout << ansx.f.f << " " << ansx.f.s << " " << ansx.s.f << " " << ansx.s.s << endl;

		return 0;
	}