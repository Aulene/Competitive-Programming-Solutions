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

int dp[200007][37];
int fx[37];

stack < pair <char, pair <int, int> > > sx; // entered char, p(idxfrom, 1/0)

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, q, i, j, u, v, idx = 0, ans = 1;
		string s, s1 = "", op;
		char x;
		
		cin >> s;
		n = s.size();

		for(i = 0; i < 200007; i++)
			for(j = 0; j < 37; j++) dp[i][j] = -1;
		for(i = 0; i < 37; i++) fx[i] = -1;

		for(i = n - 2; i >= 0; i--) 
			{
				for(j = 0; j < 26; j++) 
					dp[i][j] = dp[i + 1][j];
				
				x = s[i + 1];
				dp[i][x - 'a'] = i + 1;
			}

		for(i = n - 1; i >= 0; i--) fx[s[i] - 'a'] = i;

		cin >> q;

		for(int T = 1; T <= q; T++)
			{
				cin >> op;

				// cout << "T = " << T << endl;

				if(op == "push") 
					{
						cin >> x;

						pair < char, pair <int, int> > pz, px;

						if(sx.empty())
							{
								if(fx[x - 'a'] != -1) {

									idx = fx[x - 'a'];
									pz = {x, {idx, 1}};
									
									// cout << "FX = " << idx << endl;
									
								}
								else {
									idx = -1;
									pz = {x, {idx, 0}};
								}

								sx.p(pz);
							}
						else
							{
								px = sx.top();

								if(idx != -1) {
									// cout << "PX = " << px.s.f << endl;

									idx = dp[px.s.f][x - 'a'];
									pz = {x, {idx, 1}};
								}
								else {
									idx = -1;
									pz = {x ,{idx, 0}};
								}

								sx.p(pz);
							}

						if(idx == -1) cout << "NO" << endl;
						else cout << "YES" << endl;
					
						// cout << "PUSH " << idx << endl;
					}
				else
					{
						sx.pop();

						int val = 1;

						if(!sx.empty())
							{
								val = sx.top().s.s;
								idx = sx.top().s.f;
							}

						if(!val) cout << "NO" << endl;
						else cout << "YES" << endl;

						// cout << "POP " << idx << endl;
					}
			}

		return 0;
	}