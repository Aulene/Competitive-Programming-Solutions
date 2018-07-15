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

vector < pair <int, int> > vs, ans;
vector <int> primes;
bool prime[100007];
int primeDist[100007], a[100007], pos[100007];

void sieve()
{
	for(int i = 1; i < 100007; i++) prime[i] = 1;

	for(int i = 2; i < 100007; i++)
		if(prime[i])
			{
				primes.pb(i);
				for(int j = i * i; j < 100007; j += i) prime[j] = 0;
			}
}

void swapyswapswap(int u, int v)
{
	int x = a[u], y = a[v];
	a[v] = x, pos[x] = v;
	a[u] = y, pos[y] = u;
	ans.pb(mp(u, v));
}

int swapper(int initial, int final)
{
	cout << "OPEN " << initial << " " << final << endl;
	int u, v;

	u = initial;

	while(u < final)
		{
			v = primeDist[abs(final - u + 1)];
			swapyswapswap(u, u + v - 1);
			cout << u << " " << u + v - 1 << endl;
			u += v - 1;
		}

	cout << "CLOSE\n";
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;

		sieve();

		for(int i = 1; i < 100007; i++)
			{
				if(prime[i]) primeDist[i] = i;
				else primeDist[i] = primeDist[i - 1];
			}

		cin >> n;

		for(i = 1; i <= n; i++)
			{
				cin >> a[i];
				pos[a[i]] = i;
			}
 
		for(i = 1; i <= n; i++)
			{
				cout << pos[a[i]] << " " << i << endl;
				
				if(pos[i] != i)
					swapper(pos[i], i);
			}

		cout << ans.size() << endl;
		for(i = 0; i < ans.size(); i++) cout << ans[i].f << " " << ans[i].s << endl;

		return 0;
	}