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
#define zp mp(0, 0)

string s;
string pattern;
int symbol_val[305];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		string s;
		int n, m, i, j, u, v;

		cin >> s;
		for (char i = '0'; i <= '9'; i++)
			pattern.push_back(i);
		for (char i = 'A'; i <= 'Z'; i++)
			pattern.push_back(i);
		for (char i = 'a'; i <= 'z'; i++)
			pattern.push_back(i);
		pattern.push_back('-');
		pattern.push_back('_');
		for(i = 0; i < 64; i++)
			symbol_val[pattern[i]] = i;
		int ans = 1;

		for(i = 0; i < s.size(); i++) {
			u = symbol_val[s[i]];

			for(j = 0; j < 6; j++) {
				if((u & (1 << j)) == 0) {
					ans = (ans * 3) % mod;
				}
			}
		}

		cout << ans << endl;

		return 0;
	}