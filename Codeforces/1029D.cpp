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

vi vs[17];
vi a;
int power[17], len[200007];

int ret(int n)
{
	int ans = 0;
	while(n) n /= 10, ans++;
	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, i, j, k, u, v, ans = 0;

		cin >> n >> k;

		power[0] = 1;
		for(i = 1; i < 11; i++) power[i] = (power[i - 1] * 10) % k;

		for(i = 0; i < n; i++)
			{
				cin >> u;
				a.pb(u);
				len[i] = ret(u);
				vs[len[i]].pb(u % k);
			}

		for(i = 1; i <= 10; i++) 
			sort(vs[i].begin(), vs[i].end());

		// for(i = 1; i < 10; i++)
		// 	{ for(j = 0; j < vs[i].size(); j++) cout << vs[i][j] << " "; cout << endl; }

		for(i = 0; i < n; i++)
			{
				for(j = 1; j < 11; j++)
					{
						u = ((a[i] % k) * power[j]) % k;
						v = (k - u) % k;
						auto y = upper_bound(vs[j].begin(), vs[j].end(), v);
						auto x = lower_bound(vs[j].begin(), vs[j].end(), v);
						ans += y - x;

						if(len[i] == j && (u + a[i] % k) % k == 0) ans--;
					}
			}

		cout << ans << endl;

		return 0;
	}