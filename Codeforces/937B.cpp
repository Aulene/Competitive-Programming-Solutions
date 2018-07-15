#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

bool primes[100007];
int n, m;

int check(int x)
{
	for(int i = 1; i <= (int) sqrt(x); i++)
		{
			if(x % i==0)
				{
					int fp = i, sp = x / i;
					if(fp >= 2 && fp <= n) return 0;
					if(sp >= 2 && sp <= n) return 0;
				}
	    }
	return 1;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, ans = -1;

		cin >> n >> m;

		for(i = 0; i < 2007 && (m - i) > n; i++)
			{
				if(check(m - i))
					{
						ans = m - i;
						break;
					}
			}

		cout << ans << endl;
		return 0;
	}