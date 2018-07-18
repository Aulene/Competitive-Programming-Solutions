#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

const int MAX = 10000007;

int prime[MAX];

void sieve()
{
	for(int i = 2; i < MAX; i++) prime[i] = 1;

	for(int i = 2; i < MAX; i++)
		if(prime[i])
			for(int j = i * i; j < MAX; j += i) 
				prime[j] = 0;

	for(int i = 2; i < MAX; i++) prime[i] = prime[i] + prime[i - 1];
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		ifstream cin ("c.in");
		
		sieve();

		int u, v;

		// for(int i = 2; i < 10000007; i++) cout << i << " " << prime[i] << endl;

		while(cin >> u >> v) {
			cout << prime[v] - prime[u - 1] << endl;
		}
		return 0;
	}