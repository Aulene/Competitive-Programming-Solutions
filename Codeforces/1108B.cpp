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

const int N = 207;
const int M = 10007;
int a[N], occ[M], fk[M];
vi vs1, vs2;

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
		
		int n, m, i, j, u, v, x = 1, y = 1;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i];
	
		sort(a, a + n);

		for(i = 0; i < n - 1; i++) {
			
			if((a[n - 1] % a[i] == 0) && (a[n - 1] != a[i])) {
				if(fk[a[i]]) continue;
				else {
					occ[i] = 1;
					fk[a[i]] = 1;
				}
			} 
		}

		for(i = n - 2; i >= 0; i--)
			if(!occ[i]) {
				cout << a[n - 1] << " " << a[i] << endl;
				return 0;
			}

		cout << a[n - 1] << " " << a[n - 2] << endl;

		return 0;
	}