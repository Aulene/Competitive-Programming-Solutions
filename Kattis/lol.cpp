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

unordered_map <int, int> m;
unordered_map <int, vector <int> > m2;
int a[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, k, i, j;

		cin >> t;

		while(t--)
			{
				bool ans = 1;

				cin >> n >> k;

				for(i = 1; i <= n; i++)
					cin >> a[i], m[a[i]] = i, m2[a[i]].pb(i);

				for(i = 1; i <= n; i++)
					{
						int f = k - a[i];

						for(j = 0; j < m2[f].size(); j++)
							if(m2[f][j] > i)
								{
									// cout << i << " " << f << " " << m2[f][j] << endl;
									// if(a[i] + a[j] == k)
									// 	{
											int x = i, y = m2[f][j];
			 
											while(x <= y)
												{
													if(a[x] + a[y] != k) ans = 0;
			 
													if(a[x] + a[y] == k)
														if(a[x] > a[y]) ans = 0;
			 										
			 										if(!ans) break;

													x++, y--;
												}
										// }
								}

						if(!ans) break;
					}

				if(ans) cout << "GOOD\n";
				else cout << "BAD\n";

				m.clear();
				m2.clear();
			}

		return 0;
	}