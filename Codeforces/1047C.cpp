#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
// #define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define N 15000005

int a[300007], sp[N], vals[N], more[N], morenum[N];

void sieve()
{
	for(int i = 2; i < N; i += 2) sp[i] = 2;

	for(long long int i = 3; i < N; i += 2)
		if(!sp[i])
			{
				sp[i] = i;
				for(long long int j = i * i; j < N; j += i)
					if(sp[j] == 0) sp[j] = i;
			}
}

void factorize(int x)
{
	while(x > 1)
		{
			int div = sp[x], ct = 0;

			while(sp[x] == div && x > 1)
				{
					ct++;
					x /= div;
				}

			vals[div]++;

			if(ct < morenum[div] || morenum[div] == -1) {
				morenum[div] = ct;
				more[div] = 1;
			}
			else if(ct == morenum[div]) more[div]++;

		}

	// cout << endl;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		memset(morenum, -1, sizeof(morenum));

		sieve();

		int n, m, i, j, u, v, fthese = 0, blurb, ans = INT_MAX;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> a[i];
				if(a[i] == 0 || a[i] == 1) fthese++;
			}

		if(fthese == n) {
			cout << -1 << endl;
			return 0;
		}

		blurb = a[0];
		for(i = 1; i < n; i++) blurb = gcd(blurb, a[i]);

		for(i = 0; i < n; i++)
			if(a[i] != 0 && a[i] != 1)
				factorize(a[i]);
	
		for(i = 2; i <= 15000000; i++)
			{
				if(vals[i] != n)
					ans = min(ans, (n - vals[i]));
				else ans = min(ans, more[i]);
			}

		if(ans >= n) ans = -1;

		cout << ans << endl;

		return 0;
	}