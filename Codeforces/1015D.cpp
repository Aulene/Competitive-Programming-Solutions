#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> vs;
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, k, s, i, j, u, v, mdist, dir;

		cin >> n >> k >> s;

		u = 1;

		if(s < k) {
			cout << "NO" << endl;
			return 0;
		}

		while(s && k)
			{
				if(abs(u - 1) > abs(n - u)) 
					{
						mdist = abs(u - 1);
						dir = -1;
					}
				else 
					{
						mdist = abs(n - u);
						dir = 1;
					}

				if(s > k) 
					{
						v = min(s - k + 1, mdist);

						if(dir == -1) {
							u = u - v;
						}
						else {
							u = u + v;
						}

						s -= v;
						k--;

						vs.pb(u);
					}
				else if(s == k) 
					{
						if(dir == -1) {
							u = u - 1;
						}
						else {
							u = u + 1;
						}

						s--;
						k--;
						vs.pb(u);
					}

				// cout << s << " " << k << " " << u << endl;
			}

		if(!s && !k) {
			cout << "YES\n";
			for(i = 0; i < vs.size(); i++) cout << vs[i] << " "; cout << endl;
		}
		else cout << "NO" << endl;

		return 0;
	}