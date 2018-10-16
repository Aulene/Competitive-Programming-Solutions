#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

int a[10000007];
vi vs, vs2;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, k, l, i, j, u, v, ans = 0;

		cin >> n >> k >> l;

		for(i = 0; i < n; i++) cin >> a[i];

		u = l / 2;

		for(i = 0; i < n; i++) 
			if(a[i] < u) vs.pb(a[i]);
			else vs2.pb(a[i]);

		reverse(vs2.begin(), vs2.end());
		for(i = 0; i < vs2.size(); i++) vs2[i] = abs(vs2[i] - l);

		// for(i = 0; i < vs.size(); i++) cout << vs[i] << " "; cout << endl;
		// for(i = 0; i < vs2.size(); i++) cout << vs2[i] << " "; cout << endl;
		 
		for(i = vs.size() - 1; i >= 0;) {

			v = 0;

			for(j = i; j >= max(i - k, 0); j--) 
				v = max(v, vs[j]);
			
			// cout << v << endl;

			ans = ans + 2 * v;
			i -= k;
		}

		for(i = vs2.size() - 1; i >= 0;) {

			v = 0;

			for(j = i; j >= max(i - k, 0); j--) 
				v = max(v, vs2[j]);

			ans = ans + 2 * v;
			i -= k;
		}

		cout << ans << endl;

		return 0;
	}