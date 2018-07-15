#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string s;
		int n, i, j, u = 0, v = 0;

		cin >> s;
		n = s.size();


		for(int i = 0; i < n; i++)
			if(s[i] == 'o') u++;
			else v++;

		// cout << u << " " << v << endl;

		if(u) {
			if(v % u == 0) cout << "YES";
			else cout << "NO\n";
			}
		else cout << "YES";

		return 0;
	}