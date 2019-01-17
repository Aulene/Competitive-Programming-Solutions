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

int a[200007], pre[200007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v, sum, ans = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];

		i = 1, j = 1, sum = 0;

		while(i <= n) {
			if(sum <= m) {
				sum += a[i];
				i++;
			}
			else if(sum > m) {
				sum -= a[j];
				j++;
			}

			if(sum <= m) ans += i - j;
			cout << sum << " " << i << " " << j - 1 << " " << ans << endl;
		}

		cout << ans << endl;
		return 0;
	}