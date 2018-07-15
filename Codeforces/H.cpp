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

		int t, n, a, b, c, d, i, j;
		double x, y;

		cin >> t;

		while(t--) 
			{
				cin >> a >> b >> c >> d;
			
				x = (double) b * log(a);
				y = (double) d * log(c);

				if(x < y) cout << "<" << endl;
				else cout << ">" << endl;
			}
		return 0;
	}