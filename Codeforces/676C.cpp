
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

		int n, m, i, j, u, v, ans = 0;
		string s;

		cin >> n >> m >> s;

		//changing As to Bs
		
		int l = 0, r = 0, a = 0, b = 0;

		while(r < n) {

			if(s[r] == 'a') a++;
			else b++;
			r++;

			while(b > m) {
				if(s[l] == 'a') a--;
				else b--;
				l++;
			}

			ans = max(ans, r - l);
			// cout << l << " " << r << " " << ans << endl;
		}

		l = 0, r = 0, a = 0, b = 0;

		while(r < n) {

			if(s[r] == 'b') a++;
			else b++;
			r++;

			while(b > m) {
				if(s[l] == 'b') a--;
				else b--;
				l++;
			}

			ans = max(ans, r - l);
			// cout << l << " " << r << " " << ans << endl;
		}

		cout << ans << endl;

		return 0;	
	}