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
		int  i, j, u, v, ans = 0, use = 0;

		cin >> s;
		int n = s.size();

		for(i = 0; i < n; i++) {
			if(s[i] == 'V') {
				if(i + 1 < n && s[i + 1] == 'K') ans++;
				else {
					if(i + 1 < n && !use) use++, ans++, s[i + 1] = 'K';
					else continue;
				}
			}
			else if(i > 0 && s[i] == 'K') {
				if(s[i - 1] == 'K') {
					if(!use) use++, ans++;
					else continue;
				}
			}
		}	

		cout << ans << endl;
		return 0;
	}