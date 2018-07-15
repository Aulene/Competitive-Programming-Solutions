#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007];
char b[100007];

bool check(int x, char c)
{
	for(int i = x - 4; i < x; i++)
		if(b[i] != c) return 0;
	return 1;
}

int mx(int x)
{
	int f = a[x];

	for(int i = x - 4; i < x; i++)
		f = max(a[i], f);
	return f;
}

int mn(int x)
{
	int f = a[x];

	for(int i = x - 4; i <= x; i++)
		f = min(a[i], f);
	return f;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, l =  -(1e9), r = -l;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i];
		for(i = 0; i < n; i++) cin >> b[i];

		for(i = 4; i < n; i++)
			if(b[i] == '1')
				{
					if(check(i, '0')) l = max(l, mx(i) + 1);
					// cout << i << " " << l << " " << mx(i) << endl;
				}
			else
				{
					if(check(i, '1')) r = min(r, mn(i) - 1);
					// cout << i << " " << mn(i) << endl;
				}

		cout << l << " " << r << endl;
		return 0;
	}