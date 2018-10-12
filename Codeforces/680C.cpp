#include <bits/stdc++.h>

using namespace std;

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
#define N 48

bool prime[N];
vi vs;

void sieve()
{
	for(int i = 2; i < N; i++) prime[i] = 1;

	for(int i = 2; i < N; i++) {
		if(prime[i]) {
			vs.pb(i);
			for(int j = i * i; j < N; j += i) prime[j] = 0;
		}
	}
}


int main()
	{	
		sieve();

		int n, m, i, j, u, v;
		int prim = 0;
		string s;
		
		vs.pb(4);
		vs.pb(9);
		vs.pb(16);
		vs.pb(25);
		vs.pb(49);

		// cout << vs.size() << endl;
		// for(i = 0; i < vs.size(); i++) cout << vs[i] << " "; cout << endl;

		for(i = 0; i < vs.size(); i++) {
			printf("%d\n", vs[i]);
			cin >> s;
			if(s == "yes") prim++;
		}

		if(prim > 1) cout << "composite" << endl;
		else cout << "prime" << endl;
		return 0;
	}