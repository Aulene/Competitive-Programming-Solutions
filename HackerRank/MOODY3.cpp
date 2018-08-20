#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define double long double
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> vs[100007];
vector <int> vs2;
int prefix[100007];
double s[100007], means[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, k, u, v;
		double sum, mean, lt, rt, rtime = 0, ans = LLONG_MAX;
		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> m;
				sum = 0;

				for(j = 0; j < m; j++) {
					cin >> u;
					vs[i].pb(u);
					vs2.pb(u);
					sum += u;
				}

				mean = (double) sum / m;
				s[i] = sum;
				means[i] = mean;

				// for(j = 0; j < m; j++) {
				// 	cout << abs((double) vs[i][j] - means[i]) << " ";
				// 	rtime += abs(vs[i][j] - means[i]);
				// } 
				// cout << endl;

				// cout << s[i] << " " << means[i] << " " << rtime << endl;
			}

		sort(vs2.begin(), vs2.end());
		for(i = 1; i <= vs2.size(); i++) prefix[i] = prefix[i - 1] + vs2[i - 1];

		// for(i = 0; i < vs2.size(); i++) cout << vs2[i] << " "; cout << endl;
		// for(i = 1; i <= vs2.size(); i++) cout << prefix[i] << " "; cout << endl;


		// for(i = 0; i < n; i++)
		// 	{
		// 		rtime = 0;

		// 		for(j = 0; j < n; j++)
		// 			for(k = 0; k < vs[j].size(); k++)
		// 				rtime += (double) abs((double) vs[j][k] - means[i]);

		// 		ans = min(ans, rtime);
		// 	}

		for(i = 0; i < n; i++)
			{
				rtime = 0;

				v = upper_bound(vs2.begin(), vs2.end(), means[i]) - vs2.begin();
				lt = (double) abs(prefix[v] - (v * means[i]));
				rt = (double) abs(prefix[vs2.size()] - prefix[v] - ((double) ((vs2.size() - v) * means[i])));
				rtime = lt + rt;

				// cout << endl;
				// cout << i << " " << means[i] << " " << v << " " << rtime << endl;
				// cout << lt << " " << rt << endl;

				ans = min(ans, rtime);
			}


		printf("%0.9Lf\n", ans);
		return 0;
	}