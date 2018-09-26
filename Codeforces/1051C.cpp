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

int a[107];
set <int> m1, m2;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v;
		bool ansx = 1;
		string ans = "";

		cin >> n;

		for(i = 1; i <= n; i++)
			cin >> a[i];

		for(i = 1; i <= n; i++)
			{
				if(m1.size() <= m2.size())
					{
						if(!m1.count(a[i])) m1.insert(a[i]), ans += "A";
						else if(!m2.count(a[i])) m2.insert(a[i]), ans += "B";
						else ansx = 0;
					}
				else 
					{
						if(!m2.count(a[i])) m2.insert(a[i]), ans += "B";
						else if(!m1.count(a[i])) m1.insert(a[i]), ans += "A";
						else ansx = 0;
					}
			}

		if(!ansx || (m1.size() != m2.size())) cout << "NO" << endl;
		else cout << "YES" << endl << ans << endl;
		return 0;
	}