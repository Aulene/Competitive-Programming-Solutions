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
		
		int n, a, b, i, j, u = -1, v;

		cin >> n >> a >> b;

		for(int i = 0; i <= 10000000; i++) {
			if((n - a * i) % b == 0 && ((n - a * i) / b >= 0)) {
				u = i;
				v = (n - a * i) / b;
				break;
			}
		}	

		if(u == -1) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			cout << u << " " << v << endl;
		}
		return 0;
	}