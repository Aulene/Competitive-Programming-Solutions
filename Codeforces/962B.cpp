#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

string s;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, r, c, u, v, ans = 0;
		string s;

		cin >> n >> r >> c >> s;
		s = '.' + s;

		for(i = 1; i <= n; i++) 
			if(s[i] == '.')
				{
					if(s[i - 1] == '*' || s[i - 1] == '.') {
						if(r >= c && r) {
							s[i] = 'A';
							ans++;
							r--;
						}
						else if(c) {
							s[i] = 'B';
							ans++;
							c--;
						}
					}
					else {

						if(s[i - 1] == 'A') {
							if(c) {
								s[i] = 'B';
								ans++;
								c--;
							}
						}
						else {
							if(r) {
								s[i] = 'A';
								ans++;
								r--;
							}
						}
					}
				}

		// cout << s << endl;

		cout << ans << endl;

		return 0;
	}