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
		
		string s1, s2, s = "";
		int n, i, j, u, v, ansx = 1;

		cin >> s1 >> s2;
		n = s1.size();

		for(i = 0; i < n; i++) {
			if(s1[i] < s2[i]) {
				ansx = 0;
			}
			else if(s1[i] >= s2[i]) s += s2[i];
			else s += s1[i];
		}

		if(!ansx) cout << -1 << endl;
		else cout << s << endl;
		return 0;
	}