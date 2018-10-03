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

int trie[100007][37];
string s;

multiset <string> ms;

vector<string> solve(vector<string> names) 
{
	vector <string> ans;

	int n = 2;

	for(int j = 0; j < names.size(); j++) 
		{
			s = names[j];

			// cout << s << " " << ms.count(s) << endl;

			if(ms.count(s) != 0) {
				ms.insert(s);
				int lol = ms.count(s);
				string sx = s + " " + to_string(lol);
				ans.pb(sx);
				continue;
			}

			ms.insert(s);

			int idx = 1, fd = 0, fgg = 0;

			for(int i = 0; i < s.size(); i++)
				{
					if(trie[idx][s[i] - 'a'] != 0)
						{
							// trie[idx][s[i] - 'a'] = n;
							// n++;
						}
					else
						{
							trie[idx][s[i] - 'a'] = n;
							n++;
							if(!fgg) fgg = i + 1;
						}

					// cout << idx << " " << s[i] << " -> " << trie[idx][s[i] - 'a'] << endl; 

					idx = trie[idx][s[i] - 'a'];
				}

			ans.pb(s.substr(0, fgg));
		}

	return ans;
}


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, i, j, u, v;
		vector <string> sx;

		cin >> n;

		for(i = 0; i < n; i++) {
			cin >> s;
			sx.pb(s);
		}

		vector <string> ans = solve(sx);

		for(i = 0; i < ans.size(); i++) cout << ans[i] << endl;
		return 0;
	}