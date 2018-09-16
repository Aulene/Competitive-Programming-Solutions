#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define hp pow(1000000000, 2)
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

vector <int> vs, ansv;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int x, d, i, j, u = 2, v, l, m;

		cin >> x >> d;

		for(i = 1; u <= hp; i++) {
			vs.pb(u - 1);
			u *= 2;
		}

		// for(i = 0; i < vs.size(); i++) cout << vs[i] << " "; cout << endl;

		int num = 1;

		while(x)
			{
				l = upper_bound(vs.begin(), vs.end(), x) - vs.begin();
				l--;

				m = l + 1;
				x -= vs[l];

				for(i = 0; i < m; i++) ansv.pb(num);

				// cout << x << " " << num << " " << m << endl;
				// cout << l << endl;

				num += d;
			}

		cout << ansv.size() << endl;
		for(i = 0; i < ansv.size(); i++) cout << ansv[i] << " "; cout << endl;
			
		return 0;
	}