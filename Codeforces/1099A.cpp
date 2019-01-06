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
		
		int i, j, w, h, u1, d1, u2, d2;
		cin >> w >> h;
		cin >> u1 >> d1;
		cin >> u2 >> d2;
		
		int S = w;

		for(i = h; i >= 0; i--) {
		    S = S + i;
		    if (i == d1) S = S-u1;
		    if (i == d2) S = S-u2;
		    if (S <= 0) S = 0;
		}
		
		cout << S << endl;	
		return 0;
	}