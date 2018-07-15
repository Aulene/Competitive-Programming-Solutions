#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int a, b, t1 = 1, t2 = 1, ans = 0;

		cin >> a >> b;

		if(a > b) swap(a, b);

		while(a < b)
			{
				if(t1 <= t2)
					{
						ans += t1;
						a++, t1++;
					}
				else
					{
						ans += t2;
						b--, t2++;
					}
 			}

 		cout << ans << endl;
 		
		return 0;
	}