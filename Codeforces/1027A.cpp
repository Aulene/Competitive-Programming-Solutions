#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

void inserter(char x, vector <int> &s)
{
	int y;
	y = (int) x - 1;
	if(y >= 'a' && y <= 'z') s.pb(y);
	y = (int) x + 1;
	if(y >= 'a' && y <= 'z') s.pb(y);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v, ans;
		string s;

		cin >> t;

		while(t--)
			{
				ans = 1;

				cin >> n >> s;

				i = 0, j = n - 1;

				while(i < j)
					{
						vector <int> x, y, z;

						inserter(s[i], x);
						inserter(s[j], y);
						set_intersection(x.begin(), x.end(), y.begin(), y.end(), back_inserter(z));
						
						if(!z.size()) ans = 0;

						i++, j--;
					}

				if(ans) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		return 0;
	}
