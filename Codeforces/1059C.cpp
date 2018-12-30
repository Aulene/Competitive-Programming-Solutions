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
		
		int n, m, i, j, u, v;

		cin >> n;

		if(n % 2 == 0) {
			for(i = 1; i <= n / 2; i++) cout << 1 << " ";
			for(i = 1; i < n / 2; i++) cout << 2 << " "; cout << n << endl;
		}
		else {

			// if(n == 3) { cout << "1 1 3" << endl; return 0; }

			for(i = 1; i <= n / 2 + 1; i++) cout << 1 << " ";
			for(i = 1; i < n / 2; i++) cout << 2 << " "; 
			if(n != 1) cout << n << endl;
		}
		return 0;
	}