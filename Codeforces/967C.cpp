#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> sx, ex;
int mod = 10000000000000;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, elevators, stairs, speed, ans;
		int i, j, u, v, q, x1, y1, x2, y2;
		vector <int> :: iterator it;

		cin >> n >> m >> elevators >> stairs >> speed;

		for(i = 0; i < stairs; i++) cin >> u, sx.pb(u);
		for(i = 0; i < elevators; i++) cin >> u, ex.pb(u);

		// cout << sx.size() << " " << ex.size() << endl;

 		cin >> q;

		while(q--)
			{
				ans = mod;
				cin >> x1 >> y1 >> x2 >> y2;

				if(x1 == x2) {
					ans = abs(y2 - y1);
					cout << ans << endl;
					continue;
				}
				// best elevator
				
				v = mod;
				
				if(ex.size()) 
					{
						it = upper_bound(ex.begin(), ex.end(), y1);

						if(it != ex.end()) {
							u = *it;
							// cout << "fuck " << u << " " << v << " " << abs(y1 - u) + abs(y2 - u) << endl;
							v = min(v, abs(y1 - u) + abs(y2 - u));
						}

						it--;

						u = *it;
						
						// cout << "fuck " << u << " " << v << " " << abs(y1 - u) + abs(y2 - u) << endl;
						v = min(v, abs(y1 - u) + abs(y2 - u));

						it = upper_bound(ex.begin(), ex.end(), y2);

						if(it != ex.end()) {
							u = *it;	
							// cout << "fuck " << u << " " << v << " " << abs(y1 - u) + abs(y2 - u) << endl;
							v = min(v, abs(y1 - u) + abs(y2 - u));
						}

						it--;

						u = *it;
						
						// cout << "fuck " << u << " " << v << " " << abs(y1 - u) + abs(y2 - u) << endl;
						v = min(v, abs(y1 - u) + abs(y2 - u));
						long double ugh = (long double) abs(x2 - x1) / speed;
						int fuck = ceil(ugh);
						// cout << ugh << endl; 
						// cout << v << " " << fuck << endl;
						ans = min(ans, v + fuck);
					}
					

				// cout << "Elevator: " << ans << endl;
				// best stairs
				
				v = mod;
				
				if(sx.size())
					{
						it = upper_bound(sx.begin(), sx.end(), y1);

						if(it != sx.end()) {
							u = *it;
							v = min(v, abs(y1 - u) + abs(y2 - u));
						}

						it--;
						u = *it;
						v = min(v, abs(y1 - u) + abs(y2 - u));
					
						it = upper_bound(sx.begin(), sx.end(), y2);

						if(it != sx.end()) {
							u = *it;
							v = min(v, abs(y1 - u) + abs(y2 - u));
						}

						it--;

						u = *it;
						v = min(v, abs(y1 - u) + abs(y2 - u));
						ans = min(ans, v + abs(x2 - x1));
					}

				// cout << "Stairs: " << v + abs(x2 - x1) << endl;
				cout << ans << endl;
			}
		return 0;
	}