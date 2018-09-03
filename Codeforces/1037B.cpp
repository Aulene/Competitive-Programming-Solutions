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

priority_queue <int, vector <int>, greater <int> > up;
priority_queue <int, vector <int>, less <int> > low;
int a[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		up.p(INT_MAX);
		low.p(-1);

		for(i = 0; i < n; i++) {
			cin >> a[i];
			// insert(a[i]);
		}

		sort(a, a + n);

		// for(i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

		u = n / 2;

		// cout << u << endl;

		if(a[u] > m)
			{
				while(u >= 0)
					{
						if(a[u] <= m) break;
						ans += abs(a[u] - m);
						u--;
					}
			}
		else if(a[u] < m)
			{
				while(u < n)
					{
						if(a[u] >= m) break;
						ans += abs(a[u] - m);
						u++;
					}
			}

		cout << ans << endl;
		return 0;
	}