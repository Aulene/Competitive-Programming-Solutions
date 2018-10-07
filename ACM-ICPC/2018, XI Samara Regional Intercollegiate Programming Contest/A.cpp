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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v;

		cin >> n >> m;

		if(n == 1 || (n == m)) {
			cout << -1 << endl;
			return 0;
		}

		if(n % m != 0) {
			cout << -1 << endl;
			return 0;
		}
		else {
			u = ((n / m) - 1) * m;
			v = m;
			cout << u << " " << v << endl;
		}

		return 0;
	}