#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[10007];
vector <int> vs;

int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		srand(time(NULL));

		int t, n, i, j, u, v;
		int ansx, ansy;
		double rip, val;

		cin >> t;

		while(t--)
			{
				rip = INT_MAX;
				vs.clear();
				for(i = 0; i < 10007; i++) a[i] = 0;

				cin >> n;

				for(i = 0; i < n; i++) {
					cin >> u;
					a[u]++;
				}

				for(i = 1; i <= 10000; i++)
					if(a[i] >= 4) vs.pb(i), vs.pb(i);
					else if(a[i] >= 2) vs.pb(i);

				for(i = 0; i < vs.size() - 1; i++) {
					u = vs[i], v = vs[i + 1];

					val = (double) ((double) (2 * u + 2 * v) * (2 * u + 2 * v)}) / (u * v);

					if(rip > val) {
						rip = val;
						ansx = u, ansy = v;
					}
				}

				cout << ansx << " " << ansx << " " << ansy << " " << ansy << endl;
			}
		return 0;
	}