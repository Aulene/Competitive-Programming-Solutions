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

priority_queue <int, vi, greater <int> > pq;
vector <pair <string, int> > ops;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v;
		string s;

		cin >> n;

		while(n--)
			{
				cin >> s;

				if(s == "insert") {
					cin >> u;
					pq.p(u);

					s += " ";
					ops.pb({s, u});
				}
				else if(s == "getMin") {

					cin >> u;

					if(!pq.empty()) {
							while(!pq.empty()) {
							v = pq.top();
							if(v < u) {
								ops.pb({"removeMin", 1});
								pq.pop();
							}
							else break;
						}
					}

					if(!pq.empty()) {
						if(pq.top() > u) {
							pq.p(u);
							ops.pb({"insert ", u});
						} 
					}
					else {
						pq.p(u);
						ops.pb({"insert ", u});
					}

					s += " ";
					ops.pb({s, u});
				}
				else {

					if(pq.empty()) {
						ops.pb({"insert ", 1});
					}
					else {
						pq.pop();
					}

					ops.pb({s, 1});
				}
			}	

		cout << ops.size() << endl;
		for(i = 0; i < ops.size(); i++) {
			if(ops[i].f == "removeMin") cout << ops[i].f << endl;
			else cout << ops[i].f << ops[i].s << endl;
		}
		return 0;
	}