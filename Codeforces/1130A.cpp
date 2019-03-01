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
#define ld long double

const int N = 107;

int a[N];
ld b[N];

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

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = -1000; i <= 1000; i++) {
			if(i == 0) continue;

			int d = i;
			int cnt = 0;

			for(j = 1; j <= n; j++) {
				ld val = (ld) a[j] / d;
				if(val > 0) cnt++;
			}

			if(cnt >= ceil((ld) n / 2)) {
				cout << i << endl;
				return 0;
			}
		}

		cout << 0 << endl;
		return 0;
	}