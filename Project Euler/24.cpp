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
int fact[N];

void facts() {
	fact[0] = 1;
	for(int i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % mod;
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
			
		facts();
		// cout << 2 * fact[9] << endl;
		// cout << 6 * fact[8] << endl;

		vi vs;

		vs.pb(2 * fact[9]);
		vs.pb(6 * fact[8]);
		vs.pb(6 * fact[7]);
		vs.pb(2 * fact[6]);
		vs.pb(5 * fact[5]);
		vs.pb(1 * fact[4]);
		vs.pb(2 * fact[3]);
		vs.pb(1 * fact[2]);
		vs.pb(1 * fact[1]);
		
		int sum = 0;
		for(auto it : vs) sum += it;

		cout << sum << endl;
		return 0;
	}