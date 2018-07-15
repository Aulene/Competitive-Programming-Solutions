#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[7];

int cond(int b)
{
	if(a[0] >= b && a[1] >= b && a[2] >= b) return 0;
	return 1;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int x, b, i, j, u, v, ans = 0;

		cin >> x >> b;

		for(i = 0; i < 3; i++) a[i] = b;

		while(cond(x))
			{
				// for(i = 0; i < 3; i++) cout << a[i] << " "; cout << endl;

				u = a[2] + a[1] - 1;
				a[0] = u;
				sort(a, a + 3);
				ans++;
			}

		cout << ans << endl;
		return 0;
	}