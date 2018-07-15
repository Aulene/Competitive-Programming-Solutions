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

		int n, m, k, i, j, u, v;
		int a, b, c, x, y;

		cin >> n >> m >> k;

		if(k < n) 
			{
				cout << 1 + k << " " << 1 << endl;
				return 0;
			}
		if(k == n) {
			cout << n << " 2" << endl;
			return 0; 
		}

		u = k - n;
		a = u / (m - 1);
		b = u % (m - 1);

		if((a & 1) == 0)
			{
				if(!b) y = 2;
				else y = 2 + b;
			}
		else
			{
				if(!b) y = m;
				else y = m - b;
			}

		cout << n - a << " " << y << endl;
		

		return 0;
	}