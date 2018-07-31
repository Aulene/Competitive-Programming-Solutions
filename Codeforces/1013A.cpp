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

		int i, j, u, v, s1 = 0, s2 = 0;
		int n;

		cin >> n;

		for(i = 0; i < n; i++) cin >> u, s1 += u;
		for(i = 0; i < n; i++) cin >> u, s2 += u;

		if(s2 <= s1) cout << "Yes\n";
		else cout << "No\n";
		
		return 0;
	}