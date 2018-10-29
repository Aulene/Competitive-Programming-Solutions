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
#define zp mp(0, 0)

vector < vector <int> > vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, k, j, u, v;

		string s;
		bool ansx = 1;

		cin >> s >> k;

		n = s.size();

		string s1 = s;

		sort(s1.begin(), s1.end());

		// for(i = 0; i < n; i++) {

		// 	bool select = 0;
		// 	int x;

		// 	for(j = i + 1; j < n; j++) {
				
		// 		cout << j << " " << s[j] << endl;

		// 		if(s[i] > s[j]) {
		// 			if(!select || (select && s[x] > s[j])) select = 1, x = j;
		// 		}
		// 	}

		// 	cout << s << endl;

		// 	cout << "fuck " << i << " " << x << endl;

		// 	if(abs(x - i) < k) {
		// 		swap(s[x], s[n - 1]);
		// 		x = n - 1;
		// 	}

		// 	if(abs(x - i) < k) ansx = 0;
		// 	else { swap(s[x], s[i]); }
		// }

		// cout << s << endl;
		// cout << s1 << endl;

		 {

			int x = n / 2 - 1, y = x + 1;

			// cout << x << " " << y << endl;

			while(x >= 0 && y < n - 1) {
				if(s[x] != s1[x] && abs(n - 1 - x) < k) {
					ansx = 0;
					break;
				}
				else x--;
				if(s[y] != s1[y] && y < k) {
					ansx = 0;
					break;
				}
				else y++;
					
			}
		}

		// if(s != s1) ansx = 0; 

		if(ansx) cout << "Yes\n";
		else cout << "No\n";
		return 0;
	}