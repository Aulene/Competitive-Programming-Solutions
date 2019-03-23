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
#define msi multiset <int> 
#define si set <int>
#define zp mp(0, 0)

#define ld long double

map <char, set <int> > mx1, mx2;
vpi ansv;

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
		
		int n, m, i, j, u, v;
		char x, q = '?';
		string s1, s2;

		cin >> n >> s1 >> s2;

		for(i = 1; i <= n; i++)
			mx1[s1[i - 1]].insert(i);
		for(i = 1; i <= n; i++) 
			mx2[s2[i - 1]].insert(i);

		for(auto it : mx1) {

			x = it.f;

			if(x == q) continue;

			while(!mx1[x].empty() && !mx2[x].empty()) {
				ansv.pb({*mx1[x].begin(), *mx2[x].begin()});
				mx1[x].erase(mx1[x].begin());
				mx2[x].erase(mx2[x].begin());
			}

			while(!mx1[x].empty() && !mx2[q].empty()) {
				ansv.pb({*mx1[x].begin(), *mx2[q].begin()});
				mx1[x].erase(mx1[x].begin());
				mx2[q].erase(mx2[q].begin());
			}

			while(!mx1[q].empty() && !mx2[x].empty()) {
				ansv.pb({*mx1[q].begin(), *mx2[x].begin()});
				mx1[q].erase(mx1[q].begin());
				mx2[x].erase(mx2[x].begin());
			}
		}

		for(auto it : mx2) {

			x = it.f;

			if(x == q) continue;
			
			while(!mx1[x].empty() && !mx2[x].empty()) {
				ansv.pb({*mx1[x].begin(), *mx2[x].begin()});
				mx1[x].erase(mx1[x].begin());
				mx2[x].erase(mx2[x].begin());
			}

			while(!mx1[x].empty() && !mx2[q].empty()) {
				ansv.pb({*mx1[x].begin(), *mx2[q].begin()});
				mx1[x].erase(mx1[x].begin());
				mx2[q].erase(mx2[q].begin());
			}

			while(!mx1[q].empty() && !mx2[x].empty()) {
				ansv.pb({*mx1[q].begin(), *mx2[x].begin()});
				mx1[q].erase(mx1[q].begin());
				mx2[x].erase(mx2[x].begin());
			}
		}

		while(!mx1[q].empty() && !mx2[q].empty()) {
			ansv.pb({*mx1[q].begin(), *mx2[q].begin()});
			mx1[q].erase(mx1[q].begin());
			mx2[q].erase(mx2[q].begin());
		}

		cout << ansv.size() << endl;
		for(auto it : ansv) cout << it.f << " " << it.s << endl;

		return 0;
	}