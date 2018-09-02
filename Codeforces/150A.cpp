#include <bits/stdc++.h>
#include <unordered_map>

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

unordered_map <int, int> mx, vis;
int ansv = 0;

int recur(int n, int lvl)
{
	if(vis[n]) return mx[n];

	vis[n] = 1;

	int ans = 0;
	for(int i = 2; i <= sqrt(n); i++)
		{
			if((n % i == 0) && (i != n)) 
				{
					if(lvl != 1) {
						ans = max(ans, 1 + recur(i, 2));
						ans = max(ans, 1 + recur(n / i, 2));
						continue;
					}

					int u = 1 + recur(i, 2);
					int v = 1 + recur(n / i, 2);

					if(u > ans) 
						{
							ans = u;
							ansv = i;
						}

					if(v > ans) 
						{
							ans = v;
							ansv = n / i;
						}
				}
		}

	return mx[n] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v, ans;

		cin >> n;
		ans = recur(n, 1);

		// cout << ans << endl << endl;

		if(ans % 2 == 0) cout << "1" << endl << ansv << endl;
		else cout << "2" << endl;

		return 0;
	}