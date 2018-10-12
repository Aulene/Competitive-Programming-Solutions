#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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
#define N 270007
#define M 37

vector <string> vs;
vector <char> ansv;
string fx = "";

int trie[N][M];
int edx[N];
int isDist[N];
int mdist = 0, root = 1;

bool cmp(string a, string b)
{
	int u = 0, v = 0, i;
	for(i = 0; i < a.size(); i++)
		if(a[i] != fx[i]) break; u = i;
	for(i = 0; i < b.size(); i++)
		if(b[i] != fx[i]) break; v = i;
	// cout << a << " " << u << " " << b << " " << v << endl;
	if(u != v)
		return u < v;
	return a < b;
}

int comm(string a, string b)
{
	int i = 0;
	while(a[i] == b[i] && i < min(a.size(), b.size())) i++;
	return i;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Downloads/ioi2008tests/typ/typ9b.in");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v;
		string s;

		cin >> n;

		while(n--) { 
			cin >> s; vs.pb(s); 
			// insert(s);
			if(s.size() > fx.size()) fx = s;
		}

		sort(vs.begin(), vs.end(), cmp);

		// for(i = 0; i < vs.size(); i++) cout << vs[i] << endl;

		int prev = 0;

		for(i = 0; i < vs.size(); i++) {

			// for(j = prev; j < vs[i].size(); j++) cout << vs[i][j] << endl;
			for(j = prev; j < vs[i].size(); j++) ansv.pb(vs[i][j]);
			
			// cout << 'P' << endl;
			ansv.pb('P');
			
			if(i + 1 < vs.size()) {
				prev = comm(vs[i], vs[i + 1]);
				u = vs[i].size() - prev;
				// while(u--) cout << '-' << endl;
				while(u--) ansv.pb('-');
			}
		}

		cout << ansv.size() << endl;
		for(i = 0; i < ansv.size(); i++) cout << ansv[i] << endl;

		return 0;
	}