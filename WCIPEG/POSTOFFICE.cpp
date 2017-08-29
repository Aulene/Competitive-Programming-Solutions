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

int a[307], cost[307][307], cost2[307];
pair <int, int> dp[307][307];
vector <int> ansv;
int ans = 30000007, ind;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, k, l, sum;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			cin >> a[i];
		
		for(i = 0; i < 307; i++)
			for(j = 0; j < 307; j++)
				{
					dp[i][j].f = 1000000007;
					cost[i][j] = -1;
				}

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				if(cost[i][j] == -1)
					{
						sum = 0;

						for(k = i + 1; k < j; k++)
							sum += min(abs(a[i] - a[k]), abs(a[j] - a[k]));

						cost[i][j] = cost[j][i] = sum;
					}

		for(i = 1; i <= n; i++)
				{
					sum = 0;

					for(k = i + 1; k <= n; k++)
						sum += abs(a[i] - a[k]);

					cost2[i] = sum;
				}
		
		if(m != 1)	
			{
				for(i = 1; i <= m; i++)
					{
						for(j = 1; j <= n; j++)
							{
								if(i == 1)
									{
										sum = 0;
										
										for(k = 1; k < j; k++)
											sum += abs(a[k] - a[j]);

										dp[i][j].f = sum;
										dp[i][j].s = k;
									}
								else if(i != m)
									{
										for(k = 1; k < j; k++)
											{
												sum = dp[i - 1][k].f + cost[j][k];

												if(dp[i][j].f > sum)
													{
														// dp[i][j] = min(dp[i][j], sum);
														dp[i][j].f = sum;
														dp[i][j].s = k;
		 											}
											}
									}
								else if(i == m)
									{
										for(k = 1; k < j; k++)
											{
												sum = dp[i - 1][k].f + cost[j][k] + cost2[j];

												if(dp[i][j].f > sum)
													{
														dp[i][j].f = sum;
														dp[i][j].s = k;
		 											}
											}									
									}
							}
					}

				for(i = 1; i <= n; i++)
					if(ans > dp[m][i].f)
						{
							ans = dp[m][i].f;
							ind = i;
						}

				// cout << ind << endl;

				while(m >= 1)
					{
						ansv.pb(ind);
						ind = dp[m][ind].s;
						m--;
					}

				sort(ansv.begin(), ansv.end());

				cout << ans << endl;
				for(vector <int> :: iterator it = ansv.begin(); it != ansv.end(); it++)
					cout << a[*it] << " ";
				cout << endl;
			}
		else
			{
				for(i = 1; i <= n; i++)
					{
						sum = 0;

						for(j = 1; j <= n; j++)
							sum += abs(a[i] - a[j]);

						if(ans >= sum)
							{
								ans = sum;
								ind = i;
							}
					}
				cout << ans << endl << a[ind] << endl;
			}

		return 0;
	}