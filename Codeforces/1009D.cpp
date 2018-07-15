// Euler Totient from Winger's thingy on that post idfk where i kept it

#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

const int MAX = 1007;

vector < pair <int, int> > ans;
int phi[1007];
int n, m, i, j;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void tot()
{
	for (int i = 1; i < MAX; ++i) {
		  phi[i] += i;
		  for (int j = 2 * i; j < MAX; j += i) {
		    phi[j] -= phi[i];
		  }
		}

}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> n >> m;

		if(m < n - 1) {
			cout << "Impossible\n";
			return 0;
		}

		
		if(n < MAX)
			{
				tot();
				int sum = 0;

				for(int i = 2; i <= n; i++) sum += phi[i];

				// cout << sum << endl;

				if(sum < m) {
					cout << "Impossible\n";
					return 0;
				}
			}


		for(i = 2; i <= n; i++) ans.pb(mp(1, i));

		n = min(1000, n);

		for(i = 2; i <= n; i++){

			if(ans.size() == m) break;

			for(j = i + 1; j <= n; j++) 
			{
				if(gcd(i, j) == 1) {
					ans.pb(mp(i, j));
					if(ans.size() == m) break;
				}
				if(ans.size() == m) break;
			}
			
		}

		cout << "Possible\n";
		for(int i = 0; i < m; i++) cout << ans[i].f << " " << ans[i].s << endl;

		return 0;
	}