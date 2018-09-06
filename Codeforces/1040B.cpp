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

int turned[1007];
// int dp[1007][1007]
int n, k;

vi vs, ansv;

int recur(int num, int x)
{
	if(num > n) return INT_MAX;
	vs.pb(num);
	if(num >= n) return 1;

	// cout << num << " " << x << endl;
	
	return 1 + recur(num + 2 * k + 1, x + 1);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int i, j, u, v, maxturn, ans = INT_MAX;

		cin >> n >> k;

		u = n / 2;

		if(n - k <= 0) {
			cout << 1 << endl << 1 << endl;
			return 0;
		}

		if(2 * k + 1 >= n)
			{
				u = n / 2 + 1;
				cout << 1 << endl << u << endl;
				return 0;
			}

		for(i = 1; i <= 1007; i++) ansv.pb(i);

		for(i = 1; i <= k + 1; i++)
			{
				vs.clear();
				vs.pb(i);
				j = i + 2 * k + 1;
				
				while(1)
					{
						if(j > n)
							{
								vs.clear();
								break;
							}
						else
							{
								if(j >= n - k)
									{
										vs.pb(j);
										if(vs.size() < ansv.size())
											ansv = vs;
										break;
									}
								else
								{
									vs.pb(j);
									j = j + 2 * k + 1;
								}
							}
					}
			}
		

		cout << ansv.size() << endl;
		for(i = 0; i < ansv.size(); i++) cout << ansv[i] << " "; cout << endl;

		return 0;
	}