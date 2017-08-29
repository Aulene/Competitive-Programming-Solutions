#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair

lli a[100007];
lli prefix[100007];
lli ans[100007];

lli calc(int l, int r, int n)
{
	lli m = a[l], i;

	for(i = l+1; i < r; i++)
		m = max(m, a[i%n]);

	return m;
}

int main()
	{
		int n, k, p, i, j, x, y, f=0, len;
		char op;

		cin >> n >> k >> p;

		k = min(n, k);

		for(i=1; i<=n; i++)
			cin >> a[i];

		for(i=1; i<=k; i++)
			prefix[1] += a[i];

		for(i=2; i<=n; i++)
			prefix[i] = prefix[i-1] - a[i-1] + a[(i+k-1)%n];

		ans[1] = calc(1, n-k+2, n);

		for(i=2; i<=n; i++)
			{
				if(ans[i-1] == prefix[i-1])
					ans[i] = calc(i, i+n+1-k, n);
				else
					ans[i] = max(ans[i-1], prefix[(i+n-k)%n]);
			}

		while(p--)
			{
				cin >> op;

				if(op == '?')
					cout << ans[(f % n + n)%n] << endl;
				else
					f--;
			}
		return 0;
	}