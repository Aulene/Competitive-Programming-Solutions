#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007];
vector <int> vs1, vs2;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, k, u, v, ans, ansv;

		cin >> t;

		for(int T = 1; T <= t; T++)
			{
				vs1.clear();
				vs2.clear();

				cin >> n;

				for(i = 0; i < n; i++) cin >> a[i];

				for(i = 0; i < n; i++) {
					
					if(i % 2 == 0) vs1.pb(a[i]);
					else vs2.pb(a[i]);
				}

				sort(vs1.begin(), vs1.end());
				sort(vs2.begin(), vs2.end());

				// for(i = 0; i < vs1.size(); i++) cout << vs1[i] << " "; cout << endl;
				// for(i = 0; i < vs2.size(); i++) cout << vs2[i] << " "; cout << endl;
					
				// u = 0, v = 1;
				// i = 0, j = 0;
				
				// while(u < vs1.size() - 1 || v < vs2.size() - 1)
				// 	{
				// 		if(u < v) {
				// 			if(!(vs1[i] <= vs2[j] && vs2[j] <= vs1[i + 1])) {
				// 				ans = 0;
				// 				ansv = v;
				// 			}
				// 			else u += 2, i++;
				// 		}
				// 		else {
				// 			if(!(vs2[j] <= vs1[i] && vs1[i] <= vs2[j + 1])) {
				// 				ans = 0;
				// 				ansv = u;
				// 			}	
				// 			else v += 2, j++;
				// 		}

				// 		if(!ans) break;
				// 	}

				ans = 1;
				j = 0, k = 0;

				for(i = 0; i < n - 1; i++)
					{
						if(i % 2 == 0) {

							if(vs2[k] < vs1[j]) {
								ans = 0;
								ansv = i;
							}
							j++;
						}
						else {
							if(vs1[j] < vs2[k]) {
								ans = 0;
								ansv = i;
							}
							k++;
						}

						if(!ans) break;
					}

				if(!ans) cout << "Case #" << T << ": " << ansv << endl;
				else cout << "Case #" << T << ": OK" << endl;
			}
		return 0;
	}