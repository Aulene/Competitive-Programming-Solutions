#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int bs(int n, int m)
{
	if(m == 0) return n;
	return ceil((double) n / (m + 1));
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;

		while(true)
			{
				cin >> n >> m;
				if(n == -1 && m == -1) break;

				u = max(n, m);
				v = min(n, m);
				cout << bs(u, v) << endl;
			}
		return 0;
	}