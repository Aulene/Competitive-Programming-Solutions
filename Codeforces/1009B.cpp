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

		string s;
		int n, i, j, u, v, ;

		cin >> s;
		n = s.size();

		// for(i = 0; i < n; i++)
		// 	{
		// 		if(s[i] == '0') {
		// 			if(i && s[i - 1] == '1') {
		// 				s[i] = '1';
		// 				s[i - 1] = '0';
		// 			}
		// 		}
		// 		else if(s[i] == '2') {
		// 			if(i < n - 1 && s[i + 1] == '1') {
		// 				s[i] = '1';
		// 				s[i + 1] = '2';
		// 			}
		// 		}
		// 	}	

		u = n, v = -1;

		while(u--)
			{
				if(s[u] == '1') {
					if(v == -1) v = u;
				}

				if(s[u] == '2') {
					if(v != -1) {
						u = 
					}
				}

			}
		cout << s << endl;

		return 0;
	}