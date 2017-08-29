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
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[57];
int ans[107][157][157];
bool vis[107][157][157];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, k, ansx, l, m, N, M;

		cin >> t;

		while(t--)
			{
				for(i = 0; i < 107; i++)
					for(j = 0; j < 157; j++)
						for(k = 0; k < 157; k++)
							ans[i][j][k] = 0, vis[i][j][k] = 0;
				ansx = 0;
				memset(a, 0, sizeof a);

				cin >> n;

				for(i = 1; i <= n; i++) cin >> a[i];

				if(n < 2) ansx = 1;
				else
					{
						N = n;
						ans[2][a[1]][a[2]] = 1; 
						vis[2][a[1]][a[2]] = 1;
						m = max(a[1], a[2]);

						for(i = 2; i <= n; i++)
							{
								M = m;

								for(k = 0; k <= m; k++)
									for(j = 0; j <= m; j++)
										if(vis[i][j][k])
											{
												if((i > N && k > 0) || i == N)
													ansx = (ansx + ans[i][j][k]) % mod;		

												for(l = 0; l <= min(k, j); l++)
													{
														ans[i + 1][k - l][a[i + 1] + l] = (ans[i + 1][k - l][a[i + 1] + l] + ans[i][j][k]) % mod;
														vis[i + 1][k - l][a[i + 1] + l] = 1;
														M = max(M, a[i + 1] + l);
														if(j > 0 && k > 0) n = max(n, i + 1);
													}
											}

								m = M;	
							}
					}

				cout << ansx << endl;
			}
		return 0;
	}