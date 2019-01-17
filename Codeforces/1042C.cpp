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

vpi pos, neg, zer;

bool cmp(pi a, pi b) {
	return a.s < b.s;
}

const int N = 200007;
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
		
		int n, m, i, j, u = 0, v = 0;

		cin >> n;
		for(i = 1; i <= n; i++) {
			cin >> a[i];
			if(a[i] < 0) neg.pb({i, a[i]});
			else if(a[i] > 0) pos.pb({i, a[i]});
			else zer.pb({i, 0});
		}

		m = neg.size();

		if(m <= 1 && pos.size() == 0) {
			for(i = 0; i < zer.size() - 1; i++) 
				cout << "2 " << zer[i].f << endl;
		}
		else {
			for(i = 0; i < zer.size(); i++) 
				cout << "2 " << zer[i].f << endl;
		}

		sort(neg.begin(), neg.end(), cmp);

		if(neg.size() > 0) {
			if(((int)(neg.size() % 2)) == 1) {
				cout << "2 " << neg[neg.size() - 1].f << endl;
				for(i = 0; i < ((int)(neg.size() - 2)); i++) 
					cout << "1 " << neg[i].f << " " << neg[i + 1].f << endl;
			}
			else {
				for(i = 0; i < ((int)(neg.size() - 1)); i++) 
					cout << "1 " << neg[i].f << " " << neg[i + 1].f << endl;
			}
		}

		if(pos.size() > 0) {
			for(i = 0; i < ((int)(pos.size() - 1)); i++) 
				cout << "1 " << pos[i].f << " " << pos[i + 1].f << endl;
		}

		if(m >= 2 && pos.size() > 0) {
			if(m % 2 == 1) {
				cout << "1 " << neg[m - 2].f << " " << pos[pos.size() - 1].f << endl;
			}
			else {
				cout << "1 " << neg[m - 1].f << " " << pos[pos.size() - 1].f << endl;
			}
		}
		return 0;
	}