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

int binsearch(int x, int y, int a, int b)
{
	int low = 0, high = 10000000000, mid, ans = 0;

	while(low <= high)
		{
			mid = (low + high) / 2;

			int x1 = x * mid, y1 = y * mid;

			// cout << x1 << " " << y1 << endl;

			if(x1 <= a && y1 <= b) {
				ans = mid;
				low = mid + 1;
			} 
			else high = mid - 1;
		}

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int a, b, x1, y1, x, y, i, j, u, v, ans = 0;

		cin >> a >> b >> x >> y;

		u = gcd(x, y);

		x1 = x, y1 = y;
		x /= u, y /= u;

		// for(i = 1;; i++) 
		// 	{
		// 		x1 = x * i, y1 = y * i;
				
		// 		cout << x1 << " " << y1 << endl;
				
		// 		if(x1 <= a && y1 <= b) ans++;
		// 		else break;
		// 	}

		// cout << x << " " << y << endl;

		ans = min(a / x, b / y);

		// ans = binsearch(x, y, a, b);
		
		cout << ans << endl;

		return 0;
	}