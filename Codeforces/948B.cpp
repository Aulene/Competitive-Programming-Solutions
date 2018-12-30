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

const int N = 1000007;

bool prime[N];
int fx[N];

vi vs;

void sieve()
{
	for(int i = 2; i < N; i++) 
		prime[i] = 1, fx[i] = i;

	for(int i = 2; i < N; i++) {
		if(prime[i]) {
			vs.pb(i);
			for(int j = i * i; j < N; j += i) prime[j] = 0, fx[j] = i;
		}
	}
}

vi facts(int n) {

	set <int> sx;
	vi ansv;

	while(n != 1) {
		if(!sx.count(fx[n])) ansv.pb(fx[n]);
		sx.insert(fx[n]);
		n /= fx[n];
	}

	return ansv;
}

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
			
		sieve();

		int n, m, i, j, u, v;

		cin >> n;

		vi pn = facts(n);
		vi pos1;

		for(auto it : pn) {
			int c = it;
			
		}

		for(auto it : pn) cout << it << " "; cout << endl;

		return 0;
	}