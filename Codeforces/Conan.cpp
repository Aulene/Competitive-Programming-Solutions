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

unordered_map <int, int> mx;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> u, mx[u]++;

		u = 0;

		for(i = 1; i < 100007; i++)
			if(mx[i] % 2) {u++; break;}

		if(!u) cout << "Agasa";
		else cout << "Conan";

		return 0;
	}