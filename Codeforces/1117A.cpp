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
int a[N];

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
		
		int n, m, i, j, u, v, mval = 0, lval = 0;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		int curl = 1, curc = a[1];
		mval = a[1];
		lval = 1;

		for(i = 2; i <= n; i++) {
			if(a[i] == a[i - 1]) {
				curl++;
			} else {
				curl = 1;
			}

			if(a[i] > mval) {
				mval = a[i];
				lval = curl;
			}
			else if(a[i] == mval) lval = max(lval, curl);
		}

		cout << lval << endl;

		return 0;
	}