#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007], even[100007], odd[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i < n; i++) {
			if(i & 2) odd[i] = - abs(a[i] - a[i + 1]), even[i] = abs(a[i] - a[i + 1]);
			else odd[i] = abs(a[i] - a[i + 1]), even[i] = - abs(a[i] - a[i + 1]);
		}

		for(i = 1; i < n; i++) cout << odd[i] << " "; cout << endl;
		for(i = 1; i < n; i++) cout << even[i] << " "; cout << endl;
			
		return 0;
	}