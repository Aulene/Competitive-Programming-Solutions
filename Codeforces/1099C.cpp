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
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int>
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		string s;
		int n, m, i, j, u, v, snow = 0, candy = 0;
		int ansx = 1;
		string ans = "";

		cin >> s >> m;

		n = s.size();

		// cout << n << endl;

		for(i = 0; i < n; i++)
			if(s[i] == '*') snow++;
			else if(s[i] == '?') candy++;

		int F = n - (snow + candy);

		if(m > F) {
			if(snow == 0) {
				cout << "Impossible\n";
				return 0;
			}

			int diff = m - (n - (snow + candy));
			diff++;

			for(i = 0; i < n; i++) {
				if(s[i] == '?' || s[i] == '*') continue;

				if(diff > 0) {
					if(s[i + 1] == '*') {
						while(diff > 0) {
							ans += s[i];
							diff--;
						}
					}
					else ans += s[i];
				}
				else ans += s[i];
			}
		}
		else if(m < n) {
			if(n - (2 * (snow + candy)) > m) {
				cout << "Impossible\n";
				return 0;
			}

			int diff = n - m - (snow + candy);

			// cout << "diff = " << diff << endl;

			for(i = 0; i < n; i++) {
				if(s[i] == '?' || s[i] == '*') continue;

				if(diff > 0) {
					if(s[i + 1] == '?' || s[i + 1] == '*') {
						diff--;
						continue;
					}
					else ans += s[i];
				}
				else ans += s[i];

				// cout << i << " " << ans << " " << diff << endl;
			}
		}
		else {
			for(i = 0; i < n; i++)
				if(s[i] != '?' && s[i] != '*') ans += s[i];
		}

		cout << ans << endl;

		return 0;
	}