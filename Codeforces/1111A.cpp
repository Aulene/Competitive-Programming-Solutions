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

bool isVowel(char x) {
	if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return 1;
	return 0;
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
		
		string s1, s2;
		int n, m, i, j, u ,v;

		cin >> s1 >> s2;
		n = s1.size(), m = s2.size();

		if(n != m) {
			cout << "No" << endl;
			return 0;
		}
		int ans = 1;

		for(i = 0; i < n; i++) {
			if(s1[i] != s2[i]) {
				if(isVowel(s1[i]) && isVowel(s2[i])) {
					continue;
				}
				else if(!isVowel(s1[i]) && !isVowel(s2[i])) {
					continue;
				}
				ans = 0;
			}
		}

		if(ans) cout << "Yes\n";
		else cout << "No\n";
		return 0;
	}