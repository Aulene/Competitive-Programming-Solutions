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

int a[5007];
unordered_map <int, int> mx;
vector <int> vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u = INT_MAX, v, ans = 0, ansv;

		cin >> n;

		ansv = m = n;

		for(i = 1; i <= n; i++) cin >> a[i], vs.pb(a[i]), u = min(u, a[i]);

		sort(vs.begin(), vs.end());

		for(i = 1; i <= 5000; i++)
			{
				v = 0;
				// cout << i << endl;

				for(j = 1; j <= n; j++)
					{
						// cout << a[j] << " "; 

						if(a[j] >= i)
							{ 
								if(a[j] == i) m--;
								if(!v) v = 1, ans++; 
							}
						else 
							{
								ansv = min(ansv, ans + m);
								v = 0;
							}
					} 

				// cout << endl;
			}
		cout << ans << endl;
		
		ansv = min(ansv, ans + m);
		cout << ansv << endl;

		return 0;
	}