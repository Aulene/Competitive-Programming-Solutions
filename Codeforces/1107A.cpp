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
		
		int t, n, m, i, j, u, v;
		string s;

		cin >> t;

		while(t--) {
			cin >> n >> s;

			string s1, s2;

			if(n == 2) {
				if(s[0] >= s[1]) {
					cout << "NO" << endl;
					continue;
				}
			}

			s1 = s[0];

			cout << "YES" << endl << 2 << endl;
			cout << s1 << " ";
			for(i = 1; i < n; i++) cout << s[i]; cout << endl;
		}
		return 0;
	}