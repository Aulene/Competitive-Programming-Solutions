#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, i, j;

		cin >> n >> k;

		while(k--)
			{
				if(n % 10) n--;
				else n /= 10;
			}

		cout << n << endl;

		return 0;
	}