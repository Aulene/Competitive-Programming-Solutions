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

unordered_map <int, int> m, vis;
int a[100007], fact[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ans = 0, odd = 0, even = 0, one = 0;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i], m[a[i]]++;
		sort(a, a + n);

		for(i = 0; i < n; i++)
			if(a[i] == 1 || a[i] % 2 == 0) even++;

		ans += (even * (even - 1)) / 2;
		cout << ans << endl;

		return 0;
	}