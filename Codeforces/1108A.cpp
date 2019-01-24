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
		
		int n, m, i, j, u, v, t, l1, l2, r1, r2;

		cin >> t;

		while(t--) {
			cin >> l1 >> r1 >> l2 >> r2;
			if(l1 == l2 && r1 == r2) cout << l1 << " " << l1 + 1 << endl;
			else {
				if(l1 != l2) cout << l1 << " " << l2 << endl;
				else if(l1 != r2) cout << l1 << " " << r2 << endl;
				else if(r1 != l2) cout << r1 << " " << l2 << endl;
				else if(r1 != r2) cout << r1 << " " << r2 << endl;
			}
		}	
		return 0;
	}