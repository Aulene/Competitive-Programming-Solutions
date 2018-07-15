#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, q, i, j, u, speed, cnt;
		int stairs, elevators;
		int dist1, dist2, dist3, dist4, fuck, fuck2, ass, ass2, ans;
		int x1, x2, y1, y2;

		cin >> n >> m;
		cin >> stairs >> elevators >> speed;

		vector <int> sx(stairs);
		
		for(i = 0; i < stairs; i++)
			cin >> sx[i];

		vector <int> ex(elevators);
		for (i = 0; i < elevators; i++)
			cin >> ex[i];
		
		cin >> q;

		while(q--)
			{
				cin >> x1 >> y1 >> x2 >> y2;

				if(x1 == x2) {
					cout << abs(y1 - y2) << endl;
					continue;
				}
				
				swap(x1, y1); swap(x2, y2);
				
				fuck = lower_bound(ex.begin(), ex.end(), x1) - ex.begin();
				if (fuck != ex.size())
					fuck = ex[fuck];
				else
					fuck = 1000000007;
			
				fuck2 = lower_bound(ex.begin(), ex.end(), x1) - ex.begin() - 1;
				if (fuck2 < 0)
					fuck2 = 1000000007;
				else
					fuck2 = ex[fuck2];

				dist1 = abs(fuck - x1) + abs(fuck - x2)+ (abs(y2 - y1) + speed - 1) / speed;
				dist2 = abs(fuck2 - x1) + abs(fuck2 - x2) + (abs(y2 - y1) + speed - 1) / speed;
				ass = lower_bound(sx.begin(), sx.end(), x1) - sx.begin();
				
				if(ass == sx.size())
					ass = 1000000007;
				else
					ass = sx[ass];
				ass2 = lower_bound(sx.begin(), sx.end(), x1) - sx.begin() - 1;
				if (ass2 < 0)
					ass2 = 1000000007;
				else
					ass2 = sx[ass2];
				dist3 = abs(ass - x1) + abs(ass - x2) + abs(y2 - y1);
				dist4 = abs(ass2 - x1) + abs(ass2 - x2) + abs(y2 - y1);

				ans = min(dist1, dist2);
				ans = min(ans, dist3);
				ans = min(ans, dist4);
				cout << ans << endl;
			}

		return 0;
	}