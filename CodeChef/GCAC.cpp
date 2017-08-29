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

int a[1007], hired[1007];

vector < pair <int, int> > companies;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, i, j, u, v, left, tot, jobless;
		pair <int, int> msal, c;
		pair <int, int> lol = mp(-1, -1);

		string s;

		cin >> t;

		while(t--)
			{
				companies.clear();
				memset(hired, 0, sizeof hired);

				cin >> n >> m;

				left = m, tot = 0, jobless = 0;

				for(i = 1; i <= n; i++) cin >> a[i]; companies.pb(mp(0, 0));
				for(i = 0; i < m; i++) cin >> u >> v, companies.pb(mp(u, v));

				for(i = 1; i <= n; i++)
					{
						msal = mp(-1, -1);
						cin >> s;
						
						for(j = 0; j < m; j++)
							if(s[j] == '1')
								{
									c = companies[j + 1];
									if(hired[j] < c.s)
										{
											if(c.f > msal.f)
												{
													msal.f = c.f;
													msal.s = j;
												}
										}
								}

						if(msal == lol)
							jobless++;
						else if(msal.f >= a[i])
							{
								if(hired[msal.s] == 0)
									left--;

								hired[msal.s]++;
								tot += msal.f;
							}
						else
							jobless++;
					}

				cout << n - jobless << " " << tot << " " << left << endl;
 			}
		return 0;
	}