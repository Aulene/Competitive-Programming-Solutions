#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int low[100007], high[100007], close[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u = 0, v = 0;

		cin >> n;

		for(i = 0; i < n; i++) cin >> low[i];
		for(i = 0; i < n; i++) cin >> high[i];
		for(i = 0; i < n; i++) cin >> close[i];

		for(i = 1; i < n; i++)
			{
				if(low[i] > close[i - 1]) u++;
				if(high[i] < close[i - 1]) v++;
			}
		
		cout << u << " " << v << endl;
		
		return 0;
	}