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

vi ans1, ans2;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, i, j, u, v, sum, cur = 0;
		bool ansv = 0;

		cin >> n;

		if(n == 1 || n == 2) { cout << "No" << endl; return 0; }

		sum = n * (n + 1) / 2;

		for(i = 1; i <= n - 1; i++)
			{
				cur += i;
				sum -= i;

				if(gcd(cur, sum) > 1)
					{
						ansv = 1;
						for(j = 1; j <= i; j++) ans1.pb(j);
						for(j = i + 1; j <= n; j++) ans2.pb(j);
						break;
					}
			}
		
		if(ansv)
			{
				cout << "Yes" << endl;
				cout << ans1.size() << " ";
				for(i = 0; i < ans1.size(); i++) cout << ans1[i] << " "; cout << endl;
				cout << ans2.size() << " ";
				for(i = 0; i < ans2.size(); i++) cout << ans2[i] << " "; cout << endl;	 
			}
		else cout << "No" << endl;
		return 0;
	}