#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair <int, int> > vs;
vector < pair <int, pair <int, int> > > prefix;
vector <int> t;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, a, b, c, d, start, len, ans;
		int u, v, i, j;
		bool ansx = 0;
		pair < int, pair <int, int> > pz;

		cin >> n >> a >> b >> c >> d >> start >> len;

		int rating = start;

		t.pb(0);
		vs.pb(mp(0, 3));

		for(i = 0; i < n; i++)
			{
				cin >> u >> v;
				vs.pb(mp(u, v));
				t.pb(u);
			}

		t.pb(t[n] + 1);
		vs.pb(mp(t[n + 1], 3));
		prefix.pb(mp(0, mp(0, 0)));
	

		for(i = 1; i <= n; i++)
			{
				pz = prefix[i - 1];
				pz.f = vs[i].f;

				if(vs[i].s == 0) pz.s.f++;
				else pz.s.s++;

				prefix.pb(pz);
			}

		pz.f += 1;
		prefix.pb(pz);
		
		// for(i = 0; i < prefix.size(); i++)
		// 	cout << i << " " << prefix[i].f << " " << prefix[i].s.f << " " << prefix[i].s.s << endl;
		
		//0 check
			{
				u = lower_bound(t.begin(), t.end(), len) - t.begin();
				u--;

				int x = prefix[u].s.f, y = prefix[u].s.s;
				int x1 = prefix[n].s.f - prefix[u].s.f, y1 = prefix[n].s.s - prefix[u].s.s;
				
				int rate = y * c - x * d;
				int Rrate = rate + rating;


				// cout << "Index = " << i << " End Index = " << u << endl;
				// cout << "- in range = " << x << ", - out of range = " << x1 << endl;
				// cout << "+ in range = " << y << ", + out of range = " << y1 << endl;
				// cout << "Start Time = " << t[i] << " End Time = " << t[i] + len << endl;
				// cout << "Current Rating = " << rating << " End Rating = " << Rrate << endl;
				// cout << "Change = " << rate << endl;
				if(Rrate >= 0)
					{
						ansx = 1;
						ans = t[i];
					}
			}

		for(i = 1; i < t.size(); i++)
			{
				u = lower_bound(t.begin(), t.end(), t[i] + len) - t.begin();
				u--;

				int x = prefix[u].s.f - prefix[i - 1].s.f, y = prefix[u].s.s - prefix[i - 1].s.s;
				int x1 = prefix[n].s.f - prefix[u].s.f, y1 = prefix[n].s.s - prefix[u].s.s;
				
				// cout << prefix[n].s.s << " " << prefix[u].s.s << endl;
				// cout << y1 << " " << x1 << endl;

				int rate = y * c - x * d;
				int Rrate = rate + rating;

				// cout << "OPEN\n";
				// cout << "Index = " << i << " End Index = " << u << endl;
				// cout << "- in range = " << x << ", - out of range = " << x1 << endl;
				// cout << "+ in range = " << y << ", + out of range = " << y1 << endl;
				// cout << "Start Time = " << t[i] << " End Time = " << t[i] + len << endl;
				// cout << "Current Rating = " << rating << " End Rating = " << Rrate << endl;
				// cout << "Change = " << rate << endl;

				if(Rrate >= 0)
					{
						ansx = 1;
						ans = t[i];
						break;
					}
				else
					{
						if(vs[i].s == 0) rating -= b;
						else if(vs[i].s == 1) rating += a;
					}
				// cout << "CLOSE\n";
			}

		if(ansx) cout << ans << endl;
		else cout << -1 << endl;
		return 0;	
	}