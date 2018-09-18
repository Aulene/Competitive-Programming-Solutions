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

int a[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, i, j, u = 0, v;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);

		for(i = 0; i < n - 1; i++) {
			// if(a[i + 1] - a[i] > 1) {
				u += a[i + 1] - a[i] - 1;
			// }
		}

		cout << u << endl;
		return 0;
	}