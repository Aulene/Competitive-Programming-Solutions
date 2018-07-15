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

		int n, i, j, u, v;
		string s, ans = "";

		cin >> n >> s;

		for(i = 0; i < n - 1; i++)
			{
				if((s[i] == 'U' && s[i + 1] == 'R') || (s[i] == 'R' && s[i + 1] == 'U')) ans += 'D';
				else ans+=s[i];
			}

		cout << ans.size() << endl;
		return 0;
	}