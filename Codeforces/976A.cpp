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

		int n, i, j, o = 0, z = 0;
		string s, ans = "";

		cin >> n >> s;

		for(i = 0; i < n; i++)
			if(s[i] == '1') o++;
			else z++;

		if(o)
			{
				ans += '1';
				for(i = 0; i < z; i++) ans += '0';
			}
		else if(o == 0)
			{
				ans += '0';
			}

		cout << ans << endl;


		return 0;
	}