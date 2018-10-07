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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int i, j, k, u = 0, v, n, m = 0, ans = 0;

		cin >> n;

		string s;

		cin >> s;

		for(i = 0; i < n; i++)
			if(s[i] == '8') m++;
			else u++;

		while(true) {
			if(m - 1 >= 0) m--;
			else break;

			if(u >= 10) {
				u -= 10;
				ans++;
			}
			else if(u + m >= 10) {
				v = 10 - u;
				u = 0;
				m -= v;
				ans++;
			}
			else break;
		}

		cout << ans << endl;


		return 0;
	}