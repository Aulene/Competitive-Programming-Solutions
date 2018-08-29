#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

vi ans;
int a[1000007];
int vis[1000007];

multiset <int> mx;

int EXTERMINATE(int idx, int sum, int mask)
{
	if(idx >= ans.size()) 
		{
			if(vis[mask]) return 0;

			vis[mask] = 1;

			auto itr = mx.find(sum);
			if(itr != mx.end())
			    mx.erase(itr);
			return 0;
		}

	EXTERMINATE(idx + 1, sum + ans[idx], mask | (1 << idx));
	for(int i = idx + 1; i <= ans.size(); i++) 
		EXTERMINATE(i, sum, mask);
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t, n, m, i, j, u, v;

		cin >> t;

		while(t--)
			{
				memset(vis, 0, sizeof(vis));
				mx.clear();
				ans.clear();

				cin >> n;
				m = pow(2, n);
				for(i = 1; i <= m; i++) cin >> a[i], mx.insert(a[i]);

				while(true)
					{
						EXTERMINATE(0, 0, 0);
						if(mx.empty()) break;
						ans.pb(*mx.begin());
					}

				for(i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
			}
		return 0;
	}