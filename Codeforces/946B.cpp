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

		int a, b, i, j, u, v;

		cin >> a >> b;

		while(true)
			{
				if(a == 0 || b == 0) break;

				if(a >= 2 * b) 
					{
						a = a % (2 * b);
						continue;
					}
				else if(b >= 2 * a)
					{
						b = b % (2 * a);
						continue;
					}
				else break;

			}

		cout << a << " " << b << endl;
		return 0;
	}