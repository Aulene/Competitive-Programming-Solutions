#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

bool isv(char x)
{
	if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return 1;
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string s;
		int n, i, j, u, v;
		bool ansx = 1;

		cin >> s;
		n = s.size();

		if(!isv(s[n - 1])) {
			if(s[n - 1] != 'n') ansx = 0;
		}

		for(i = 0; i < n; i++)
			{
				if(!(s[i] == 'n' || isv(s[i]))) {
					if(!isv(s[i + 1])) ansx = 0;
				}
			}

		if(ansx) cout << "YES\n";
		else cout << "NO\n";
		
		return 0;
	}