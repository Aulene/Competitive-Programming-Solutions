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

vector <int> primes;
bool vis[1000007];
vector < pair < pair <int, int>, int> > ans;

void sieve()
{
	for(int i = 2; i < 1000007; i++) vis[i] = 1;

	for(int i = 2; i < 1000007; i++)
		if(vis[i])
			{
				primes.pb(i);
				for(int j = i + i; j < 1000007; j += i) vis[j] = 0;
			}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		sieve();

		int n, m, i, j, k, u, v, w, x, edges = 0, sum;
		vector<int> :: iterator it;

		cin >> n >> m;

		for(int i = 1; i <= n - 1; i++)
			{
				if(i == n - 1)
					{
						it = upper_bound(primes.begin(), primes.end(), n - 2);
						x = *it;
						sum = x;
						ans.pb(mp(mp(i, i + 1), x - n + 2));
					}
				else ans.pb(mp(mp(i, i + 1), 1));
			}

		edges = n - 1;

		if(edges < m) ans.pb(mp(mp(1, n), sum));
		edges++;

		while(true)
			{
				if(edges >= m) break;

				for(j = 1; j <= n; j++)
					{
						for(k = j + 2; k <= n; k++)
							{
								if(j == 1 && k == n) continue;
								
								if(edges >= m) break;
								ans.pb(mp(mp(j, k), sum));
								edges++;
							}
					}
			}

		cout << sum << " " << sum << endl;
		for(i = 0; i < ans.size(); i++)
			cout << ans[i].f.f << " " << ans[i].f.s << " " << ans[i].s << endl;

		return 0;
	}