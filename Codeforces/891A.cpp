#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[2007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ones = 0;
		bool ansx = 0;

		cin >> n;

		for(i = 1; i <= n; i++) {
			cin >> a[i];
			if(a[i] == 1) ones++;
		}


		return 0;
	}