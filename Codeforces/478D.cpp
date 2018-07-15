#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int even[200007], odd[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int ans = 0, n, m, i, j, u, v;

		cin >> n >> m;

		for(i = 1; i < 200007; i++) {
			if(i % 2 == 0) {
				even[i] = i + even[i - 1];
				odd[i] = odd[i - 1];
			}
			else {
				even[i] = even[i - 1];
				odd[i] = i + odd[i - 1];
			}
		}


		return 0;
	}