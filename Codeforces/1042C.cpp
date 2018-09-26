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

int a[200007];
vector < pair <int, int> > pos, neg, zeroes;

bool cmp(pair <int, int> a, pair <int, int> b) { return a.f < b.f; }

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, i, j, u = -1, negu = -1, posu = -1, v;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++)
			{
				if(a[i] > 0)
					pos.pb(mp(i, a[i]));
				else if(a[i] == 0) zeroes.pb(mp(i, a[i]));
				else neg.pb({i, a[i]});
			}

		sort(neg.begin(), neg.end(), cmp);

		// for(i = 0; i < neg.size(); i++) cout << neg[i].f << " " << neg[i].s << endl;
		// 	cout << endl;
		// cout << neg.size() << endl;

		if(zeroes.size())
			{
				for(i = 0; i < zeroes.size() - 1; i++)
					cout << "1 " << zeroes[i].f << " " << zeroes[i + 1].f << endl, n--;
				u = zeroes[zeroes.size() - 1].f;
			}

		if(n == 1) return 0;

		if(neg.size() % 2 == 1)
			{
				if(zeroes.size())
					{
						cout << "1 " << u << " " << neg[0].f << endl;
						n--;
						u = neg[0].f;
						neg.erase(neg.begin());
					}
				else
					{
						negu = neg[0].f;
						neg.erase(neg.begin());
					}				
			}
 		
 		if(zeroes.size())
			{
				if(negu != -1)
					{
						cout << "2 " << negu << endl;
						negu = -1;
					}
				else if(n > 1) cout << "2 " << u << endl, negu = -1;
			}

		if(negu != -1) cout << "2 " << negu << endl;

		if(pos.size())
			{
				for(i = 0; i < pos.size() - 1; i++) cout << "1 " << pos[i].f << " " << pos[i + 1].f << endl;
				posu = pos[pos.size() - 1].f;

			}

		if(neg.size())
			{
				for(i = 0; i < neg.size() - 1; i++) cout << "1 " << neg[i].f << " " << neg[i + 1].f << endl;
				
				if(posu != -1)
					cout << "1 " << posu << " " << neg[neg.size() - 1].f << endl;
			}


 		return 0;
	}