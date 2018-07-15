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

bool h[100007], prime[100007];

int p2(int n) { return n * n; }

int ret(int n)
{
	int ans = 0;
	while(n)
		{
			int x = n % 10;
			n /= 10;
			ans += p2(x);
		}
	return ans;
}

bool happy()
{
	int n, x;

	h[1] = 1;

	for(int i = 2; i <= 10000; i++)
		{
			set <int> s;

			n = i;

			while(!s.count(n))
				{
					s.insert(n);
					n = ret(n);
					if(n < i) { h[i] = h[n]; break; } 
					// cout << i << " " << n << endl;
				}
		}

	return 0;
}

int sieve()
{
	for(int i = 2; i < 100007; i++) prime[i] = 1;
	for(int i = 2; i < 100007; i++)
		if(prime[i])
			for(int j = i * i; j < 100007; j += i) prime[j] = 0;
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, i, j, u, v;

		happy();
		sieve();

		cin >> t;

		while(t--)
			{
				cin >> u >> v;
				if(h[v] && prime[v]) cout << u << " " << v << " YES\n";
				else cout << u << " " << v << " NO\n";
			}
		return 0;
	}