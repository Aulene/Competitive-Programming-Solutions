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

priority_queue <int, vector <int>, greater <int> > pq;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		ifstream cin ("input.txt");
		ofstream cout ("output.txt");


		int t, n, i, j, k, u, v, ans, day, today;

		cin >> t;

		for(int T = 1; T <= t; T++)
			{
				ans = 0;

				cin >> n >> k;

				for(i = 0; i < n; i++) cin >> u, pq.p(u);
				
				day = 1;

				while(!pq.empty())
					{
						today = 0;

						while(today < k && !pq.empty())
							{
								if(pq.top() >= day) {
									ans++;
									today++;
									pq.pop();
								}
								else pq.pop();
							}

						day++;
					}

				cout << "Case #" << T << ": " << ans << endl;
			}
		return 0;
	}