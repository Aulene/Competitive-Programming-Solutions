#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

int bala[17], bahu[17];
int n, ans, games;

int recur1(int selector, int mask, int wins) // 1-1, 2-2, 3-3
{
	if(selector == 3)
		{
			int u = 0;
			for(int i = 0; i < 3 * n; i++)
				if(!(mask & (1 << i))) u += bahu[i];

			if(u > bala[3]) wins++;
			if(wins >= 2) ans++;
			games++;
			
			return 0;
		}

	int nmask, u;

	for(int i = 0; i < 3 * n; i++)
		if(!(mask & (1 << i))) 
			{
				for(int j = i + 1; j < 3 * n; j++)
					if(!(mask & (1 << j))) 
						{
							for(int k = j + 1; k < 3 * n; k++)
								if(!(mask & (1 << k)))
									{
										u = bahu[i] + bahu[j] + bahu[k];

										nmask = mask;
										nmask = nmask | (1 << i);
										nmask = nmask | (1 << j);
										nmask = nmask | (1 << k);
										bitset<32> c(nmask);

										if(selector == 1)
											{ 
												if(u > bala[1]) 
													{
														cout << c << endl;
														cout << selector << " " << u << " " << bala[1] << endl;
														recur1(2, nmask, wins + 1);
													}
												else if(u == bala[1])
													{ recur1(2, nmask, wins); }
											}
										else if(selector == 2)
											{
												if(u > bala[2]) 
													{
														cout << c << endl;
														cout << selector << " " << u << " " << bala[2] << endl; 
														recur1(3, nmask, wins + 1); 
													}
												else if(u == bala[2])
													{ recur1(3, nmask, wins); }
											}
									}
						}
			}

	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t, T, i, j, k, u, v; 
		long double ansv;

		cin >> t;

		for(T = 1; T <= t; T++)
			{
				ans = games = 0;
				memset(bala, sizeof(bala), 0);

				cin >> n;

				for(i = 0; i < 3 * n; i++) cin >> bahu[i];
					
				for(j = 1; j <= 3; j++)
					for(i = 0; i < n; i++) cin >> u, bala[j] += u;

				recur1(1, 0, 0);

				cout << ans << " " << games << endl;

				ansv = (long double) ans / games;
				cout << fixed << showpoint << setprecision(9) << "Case #" << T << ": " << ansv << endl;
			}

		return 0;
	}