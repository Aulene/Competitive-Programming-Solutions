#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int phi[1000007];


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		for (int i = 1; i <= 1000000; ++i) {
		  phi[i] += i;
		  for (int j = 2 * i; j <= 1000000; j += i) {
		    phi[j] -= phi[i];
		  }
		}

		int t, n;

		cin >> t;

		while(t--) {
			cin >> n;
			cout << phi[n] << endl;
		}
		return 0;
	}