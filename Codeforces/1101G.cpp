#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define INF 1000000007
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

const int N = 200007;
const int M = 37;

int a[N], basis[M];

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
	
		// FUCK MY SHIT UP FAM
		// FUCK THIS
				
		int n, m, i, j, u, v, ans = 0;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i], a[i] = a[i - 1] ^ a[i];

		if(a[n] == 0) {
			cout << -1 << endl;
			return 0;
		}

		for(i = 1; i <= n; i++) {

			for(j = M; j >= 0; j--) {

				if((a[i] & (1LL << j)) == 0) continue;

				if(basis[j]) a[i] ^= basis[j];
				else {
					ans++;
					basis[j] = a[i];
					break;
				}
			}
		}

		cout << ans << endl;

		return 0;
	}