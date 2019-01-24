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
		
		string perm = "BGR", s, ansperm;
		int n, m, i, j, u, v;
		int cost, ans = LLONG_MAX;
		
		cin >> n >> s;

		do {

			cost = 0;

			for(i = 0; i < n; i++) {
				if(s[i] != perm[i % 3]) cost++;
			}

			if(ans > cost) {
				ans = cost;
				ansperm = perm;
			}

		} while(next_permutation(perm.begin(), perm.end()));

		cout << ans << endl;
		for(i = 0; i < n; i++)
			cout << ansperm[i % 3]; cout << endl;
		
		return 0;
	}