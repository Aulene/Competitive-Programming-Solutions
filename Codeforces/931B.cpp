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

		int n, a, b, i, j, u, v, ans = 0, final = 0;
		bool ansx = 0;

		cin >> n >> a >> b;

		if(a > b) swap(a, b);

		u = n;
		while(n > 1)
			{
				n /= 2;
				final++;
			}
		n = u;

		for(int i = 1; i <= n; i++) vs.pb(i);

		while(ans >= 0)
			{
				ans++;

				// cout << ans << endl;

				// for(int i = 0; i < vs.size(); i++) cout << vs[i] << " "; cout << endl;

				vector <int> mx;

				for(int i = 0; i < vs.size(); i += 2)
					{
						if((vs[i] == a) && (vs[i + 1] == b))
							{
								// cout << "L" << endl;
								ansx = 1;
								break;
							}
						if(vs[i + 1] == a || vs[i + 1] == b)
							{
								mx.pb(vs[i + 1]);
							}
						else if(vs[i] == a || vs[i] == b)
							mx.pb(vs[i]);
						else
							mx.pb(vs[i]);
					}

				if(ansx) break;
				vs = mx;
			}

		if(ans == final)
			cout << "Final!" << endl;
		else
			cout << ans << endl;

		return 0;
	}