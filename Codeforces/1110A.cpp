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

const int N = 100007;

int a[N], b[N];

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
		
		int n = 0, bo, i, j, u, v, k;

		cin >> bo >> k;
		
		b[0] = 1;
		b[1] = bo;
		for(i = 2; i <= k; i++) b[i] = b[i - 1] * bo;

		for(i = k - 1; i >= 0; i--) cin >> a[i];

		for(i = 0; i < k; i++) {
			n = (n + a[i] * b[i]) % 2;
			// cout << n << " " << a[i] << " " << b[i] << " " << a[i] * b[i] << endl;
		}
			

		// cout << n << endl;

		if(n % 2 == 0) cout << "even" << endl;
		else cout << "odd" << endl;
		return 0;
	}