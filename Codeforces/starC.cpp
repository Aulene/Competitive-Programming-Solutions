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

		int u, v, x, y;

		cin >> x >> y;

		while(true)
			{
				if(x && y)
					{
						if(x == 1 && y == 1) {
							cout << "1 1" << endl;
							x = 0;
							// continue;
						}
						else if(x == 1) 
							{
								cout << 2 << " " << y - 1 << endl;
								y = 1;
								// continue;
							}
						else if(y == 1) 
							{
								cout << 1 << " " << x - 1 << endl;
								x = 1;
								// continue;
							}
						else if(x == y) 
							{
								cout << 1 << " " << x - 1 << endl;
								x = 1;
							}
						else
							{
								if(x > y) {
									cout << 1 << " " << x - y << endl;
									x -= x - y;
								}
								else {
									cout << 2 << " " << y - x << endl;
									y -= y - x;
								}
							}
					}
				else 
					{
						if(x == 0) {
							cout << 2 << " " << y << endl;
							y = 0;
							// break;
						}
						else {
							cout << 1 << " " << x << endl;
							x = 0;
							// break;
						}
					}
				cout.flush();
				
				if(x == 0 && y == 0) break;

				cin >> u >> v;

				if(u == 1) x -= v;
				else y -= v;
			}

		return 0;
	}