#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[107];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++)
			for(j = i + 1; j <= n; j++)
				if(a[i] >= a[j])
					{
						cout << i << " " << j << endl;
						swap(a[i], a[j]);
					}

		// for(i = 1; i <= n; i++) cout << a[i] << " ";
		return 0;
	}