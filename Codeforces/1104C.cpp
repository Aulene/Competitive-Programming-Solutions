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

int a[7][7], b[7][7], c[7][7];

void clr() {
	int i, j, k;

	for(i = 1; i <= 4; i++)
		for(j = 1; j <= 4; j++) c[i][j] = b[i][j] = a[i][j];

	for(i = 1; i <= 4; i++) {
		int occ = 1;
		for(j = 1; j <= 4; j++) occ = min(occ, b[i][j]);

		if(occ) {
			for(j = 1; j <= 4; j++) a[i][j] = 0;
		}
	}

	for(i = 1; i <= 4; i++) {
		int occ = 1;
		for(j = 1; j <= 4; j++) occ = min(occ, c[j][i]);

		if(occ) {
			for(j = 1; j <= 4; j++) a[j][i] = 0;
		}
	}
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
		
		string s;
		int n, m, i, j, u, v;

		cin >> s;
		n = s.size();

		int idx = 0;

		while(idx < n) {

			int f = 0;

			// cout << endl;
			// for(i = 1; i <= 4; i++)
			// 	{for(j = 1; j <= 4; j++) cout << a[i][j]; cout << endl;}

			if(s[idx] == '1') {

				for(i = 1; i <= 4; i++)
					{
						for(j = 1; j <= 3; j++) {
							if(a[i][j] == 0 && a[i][j + 1] == 0) {
								f = 1;
								break;
							}
						} if(f) break;
					}

				cout << i  << " " << j << endl; 
				a[i][j] = 1; a[i][j + 1] = 1;
			}
			else {

				for(i = 1; i <= 4; i++)
					{
						for(j = 1; j <= 3; j++) {
							if(a[j][i] == 0 && a[j + 1][i] == 0) {
								f = 1;
								break;
							}
						} if(f) break;
					}

				a[j][i] = 1; a[j + 1][i] = 1;
				cout << j << " " << i << endl;

			}

			// for(i = 1; i <= 4; i++)
			// 	{for(j = 1; j <= 4; j++) cout << a[i][j]; cout << endl;}

			clr();
			idx++;
		}

		return 0;
	}