#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007];
vector <int> vs;
unordered_map <int, int> m1, m2;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, minx = 100007, maxx = -100007, sum = 0, lx, ans = 0;
		vector <int> :: iterator it1, it2;

		cin >> n;

		for(i = 0; i < n; i++)
			cin >> a[i], vs.pb(a[i]), m1[a[i]]++, sum += a[i];

		sort(a, a + n);
		sort(vs.begin(), vs.end());
		
		minx = a[0], maxx = a[n - 1];

		u = 0, v = n - 1;

		while(a[u] == minx && a[v] == maxx)
			{
				if(a[u] == minx && a[v] == maxx)
					vs[u]++, vs[v]--;
				u++, v--;
			}

		for(i = 0; i < vs.size(); i++) m2[vs[i]]++;

		for(i = minx; i <= maxx; i++) ans += min(m1[i], m2[i]);

		cout << ans << endl;
		for(i = 0; i < vs.size(); i++) cout << vs[i] << " "; cout << endl;

		return 0;
	}