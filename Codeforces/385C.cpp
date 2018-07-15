#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 20000007

vector <int> primes;
int fwd[20000007], a[1000007];
// int bck[1000007];
int ans[1270617];
bool prime[MAX];

void sieve()
{
	for(int i = 2; i <= MAX; i++) prime[i] = 1;
	prime[0] = prime[1] = 0;

	int u = 1;

	for(int i = 2; i <= MAX; i++)
		if(prime[i])
			{
				fwd[i] = u;
				// bck[u] = i;
				u++;

				// cout << i << " " << fwd[i] << endl;

				primes.pb(i);

				for(int j = 2 * i; j <= MAX; j += i)
					prime[j] = 0;
			}
}

void poll(int x)
{
	for(int i = 1; i <= sqrt(x); i++)
		if(x % i == 0)
			{
				int u = x / i;

				if(i == sqrt(x))
					{
						if(prime[i]) {
							ans[fwd[i]]++;
							// cout << i << " ";
						}
					}
				else
					{
						if(prime[i]) {
							ans[fwd[i]]++;
							// cout << i << " ";
						}

						if(prime[u]) {
							ans[fwd[u]]++;
							// cout << u << " ";
						}
					}
			}

	// cout << endl;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		sieve();

		int n, m, i, j, u, v;
		int x, y;

		cin >> n;

		for(i = 1; i <= n; i++) 
			cin >> a[i];

		for(i = 1; i <= n; i++)
			{
				// cout << a[i] << endl;
				poll(a[i]);
			}

		// for(i = 0; i <= 15; i++) 
		// 	cout << i << " " << ans[i] << endl;

		for(i = 1; i < primes.size(); i++) ans[i] = ans[i] + ans[i - 1];
		
		// for(i = 0; i <= 15; i++) 
		// 	cout << ans[i] << " ";

		cin >> m;

		while(m--)
			{	
				cin >> u >> v;

				x = lower_bound(primes.begin(), primes.end(), u) - primes.begin();
				y = upper_bound(primes.begin(), primes.end(), v) - primes.begin() - 1;

				x++, y++;

				// cout << primes[x] << " " << primes[y] << endl;
				// cout << x << " " << y << endl << endl;

				cout << ans[y] - ans[x - 1] << endl;
			}
		return 0;
	}