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
#define zp mp(0LL, 0LL)

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
		char x;

		pi mf = zp, ms = zp;

		cin >> n;

		while(n--) {
			cin >> x >> u >> v;

			if(u > v) swap(u, v);

			if(x == '+'){
				if(u > mf.f || (u == mf.f && v > mf.s)) mf = mp(u, v);
				if(v > ms.s || (v == ms.s && u > ms.f)) ms = mp(u, v);
			}
			else {
				// cout << mf.f << " " << mf.s << endl;
				// cout << ms.f << " " << ms.s << endl;
				
				if(mf.f <= u && mf.s <= v && ms.f <= u && ms.s <= v) cout << "YES\n";
				else cout << "NO" << endl;
			}

		}	
		return 0;
	}