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

vector <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, K, i, j, k, u, v;

		cin >> t;

		while(t--)
			{
				vs.clear();
				
				int ans = 0;

				cin >> K;

				for(i = 0; i < 12; i++) cin >> u, vs.pb(u);	

				for(i = 1; i < 11; i++)
					{
						for(j = i; j < 11; j++)
							{
								u = 10000000007;

								for(k = i; k <= j; k++) u = min(u, vs[k]);
								if(u > vs[i - 1] && u > vs[j + 1]) ans++;
							}
					}

				cout << K << " " << ans << endl;
			}
		return 0;
	}