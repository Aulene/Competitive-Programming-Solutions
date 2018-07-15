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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, q, i, j, k, x;
		int ans, d1, d2, diff, cs = 1;
		vector <int> :: iterator it;

		while(cin >> n)
			{
				printf("Case %d:\n", cs++);
				vs.clear();

				for(i = 0; i < n; i++)
					{
						cin >> x;
						vs.pb(x);
					}
				
				cin >> q;

				for(i = 1; i <= q; i++)
					{
						cin >> x;

						diff = 100000007;

						for(j = 0; j < n; j++)
							{
								d1 = vs[j];

								for(k = 0; k < n; k++)
									if(j != k)
										{
											d2 = vs[k];
											if(abs(x - d1 - d2) < diff)
												{
													ans = d1 + d2;
													diff = abs(x - d1 - d2);
												}

										}
								
							}

						printf("Closest sum to %d is %d.\n", x, ans);
					}
				
			}
		return 0;
	}