#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p emplace_front
#define pb push_back
#define mp make_pair
#define f first
#define s second

/*
	10
	424238336 649760493 681692778 714636916 719885387 804289384 846930887 957747794 596516650 189641422
 L  1			2		3			4		5			6			7 		8			1		1
 R  
 */
int a[100007], l[100007], r[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ans = 0;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++) {
			l[i] = 1;
			if(a[i] > a[i - 1])
				l[i] = max(l[i], 1 + l[i - 1]);
		}

		r[n] = 1;

		for(i = n - 1; i >= 1; i--) {
			if(a[i] < a[i + 1]) 
				r[i] = max(r[i + 1] + 1, 1LL);
			else r[i] = 1;
			ans = max(ans, r[i]);
		}

		// for(i = 1; i <= n; i++) cout << l[i] << " "; cout << endl;
		// for(i = 1; i <= n; i++) cout << r[i] << " "; cout << endl;
			
		for(i = 2; i <= n - 1; i++)
			{
				if(a[i + 1] - a[i - 1] > 1) 
					{
						ans = max(ans, l[i - 1] + 1 + r[i + 1]);
						// cout << i << " " << l[i - 1] + 1 + r[i + 1] << endl;
					}
				ans = max(ans, 1 + l[i - 1]);
				ans = max(ans, 1 + r[i + 1]);
			}

		ans = max(ans, r[2] + 1);
		ans = max(ans, l[n - 1] + 1);

		cout << ans << endl;

		return 0;
	}