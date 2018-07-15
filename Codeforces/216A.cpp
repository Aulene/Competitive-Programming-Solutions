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

		int a, b, c;
		cin >> a >> b >> c;

		cout << 2 * (c * (c + 1) / 2 - ((a - 1) * (a) / 2)) << endl;

		return 0;
	}