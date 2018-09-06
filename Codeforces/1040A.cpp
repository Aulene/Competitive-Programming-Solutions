#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

int ax[27];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, a, b, ans = 0, i, j, u, v;
		bool ansv = 1;

		cin >> n >> a >> b;

		for(i = 1; i <= n; i++) cin >> ax[i];
		i = 1, j = n;

		while(i <= j)
			{
				u = ax[i], v = ax[j];

				if(u == 2 && v == 2) {
					ans += min(a, b);
				}
				else if((u == 1 && v == 2) || (u == 2 && v == 1)) {
					ans += b;
				}
				else if ((u == 0 && v == 2) || (u == 2 && v == 0)) {
					ans += a;
				}
				else if((u == 0 && v == 1) || (u == 1 && v == 0)) ansv = 0;

				i++, j--;
			}

		if(!ansv) ans = -1;
		cout << ans << endl;

		return 0;
	}