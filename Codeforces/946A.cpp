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

		int b = 0, c = 0, u, v, n;

		cin >> n;

		for(int i = 0; i < n; i++)
			{
				cin >> u;
				if(u >= 0) b+=u;
				else c+=-u;
			}
		cout << b + c << endl;

		return 0;
	}