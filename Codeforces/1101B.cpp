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
		
		string s, sx = "";
		string chs = "[:|:]";

		int n, m, i, j, u, v;
		int fopen = -1, fclose = -1, colopen = -1, colclose = -1;

		cin >> s;
		n = s.size();

		for(i = 0; i < n; i++) {
			int add = 0;
			for(j = 0; j < 5; j++) 
				if(s[i] == chs[j]) add = 1;
			if(add) sx += s[i];
		}

		n = sx.size();

		// cout << sx << endl;

		for(i = 0; i < n; i++) 
			if(sx[i] == '[') {
				fopen = i;
				break;
			}

		for(i = fopen + 1; i < n; i++) 
			if(sx[i] == ':') {
				colopen = i;
				break;
			}

		for(i = n - 1; i > colopen; i--)
			if(sx[i] == ']') {
				fclose = i;
				break;
			}

		for(i = fclose - 1; i > colopen; i--)
			if(sx[i] == ':') {
				colclose = i;
				break;
			}

		int cnt = 0;
		for(i = colopen + 1; i < colclose; i++) {
			// cout << i << " " << sx[i] << endl;
			if(sx[i] == '|') cnt++;
		}
			

		if(colopen == -1 || colclose == -1 || fopen == -1 || fclose == -1) {
			cout << -1 << endl;
			return 0;
		}

		// cout << fopen << " " << colopen << " " << colclose << " " << fclose << " " << cnt << endl;

		cout << 4 + cnt << endl;

		
		return 0;
	}