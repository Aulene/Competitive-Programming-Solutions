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
		
		string s;
		int n, m, k, i, j, u = 0, v = 0, cx = 0, cz = 0;

		cin >> s >> m;
		n = s.size();
		
		for(i = s.size() - 1; i >= 0; i--) {
			if(s[i] != '0') cx++;
			else cz++;
		}

		for(i = s.size() - 1; i >= 0; i--) {
			
			if(v >= m) break;

			if(s[i] == '0') v++;
			else u++;
		}

		if(v < m) u = cx + cz - 1;

		cout << u << endl;
		return 0;
	}