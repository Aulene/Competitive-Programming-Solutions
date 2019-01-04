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

const int N = 30007;
int a[1000007];
vi ab;

vi factors(int n) {
	vi fax;
	for(int i = 1; i <= sqrt(n); i++)
		if(n % i == 0) {
			if(i == sqrt(n)) fax.pb(i);
			else fax.pb(i), fax.pb(n / i);
		}
	return fax;
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
		
		int n, m, i, j, u, v;

		for(int i = 1; i < N; i++) {
			
			vi fx = factors(i);
			int sum = 0;
			for(auto it : fx) 
				if(it != i) sum += it;

			if(sum > i) ab.pb(i);
		}

		for(auto it : ab) cout << it << endl;

		for(i = 0; i < ab.size(); i++)
			for(j = i; j < ab.size(); j++) a[ab[i] + ab[j]] = 1;

		int ans = 0;
		for(i = 1; i < N; i++)
			if(!a[i]) ans += i;

		cout << ans << endl;

		
		return 0;
	}