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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, k, u, ans = 0;
		cin >> n >> k;

		u = (int)log2l(n) + 1;
		ans = pow(2, u) - 1;

		if(k == 1) ans = n;

		cout << ans << endl;

		return 0;
	}