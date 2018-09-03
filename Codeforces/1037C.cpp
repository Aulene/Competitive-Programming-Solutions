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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, i, j, u, v, ans = 0;
		char x;
		string s1, s2;

		cin >> n;

		cin >> s1 >> s2;

		for(i = 0; i < n; i++)
			{
				if(s1[i] == s2[i]) continue;

				if(i < n - 1)
					{
						if(s1[i + 1] == s2[i] && s1[i] == s2[i + 1]) {
							// cout << i << " op1" << endl; 
							char x = s1[i];
							s1[i] = s1[i + 1];
							s1[i + 1] = x;
							ans++;

							// cout << s1 << endl << s2 << endl;
							continue;
						}
					}

				if(s1[i] != s2[i])
					{
						// cout << i << " op2" << endl; 
						s1[i] = s2[i];
						ans++;
						// cout << s1 << endl << s2 << endl;
					}
			}

		// cout << s1 << endl << s2 << endl;

		cout << ans << endl;

		return 0;
	}