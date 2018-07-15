#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[200007], prime[1000007];

int gcd(int a, int b)
{
	if(a == 0) return b;
	else return gcd(b % a, a);
}

void sieve()
{
	for(int i = 2; i < 1000007; i++) prime[i] = 1, fact[i] = 0;

	for(int i = 2; i < 1000007; i++)
		if(prime[i])
			{
				for(int j = i * i)
			}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;

		cin >> n;
		for(i = 1; i <= n; i++) cin >> a[i];

		return 0;
	}