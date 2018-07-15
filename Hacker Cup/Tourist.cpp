#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <string> vs;
vector <int> vs1;
vector < pair <int, int> > vs2, vs3;

bool cmp(pair <int, int> a, pair <int, int> b)
{
	if(a.s != b.s) return a.s < b.s;
	return a.f < b.f;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t = 1, T, n, i, j, u, v, k, m;
		string s;

		cin >> T;	

		while(t <= T)
			{
				vs.clear(); vs1.clear();
				vs2.clear(); vs3.clear();

				cin >> n >> k >> v;

				for(i = 0; i < n; i++) 
					cin >> s, vs.pb(s);

				for(i = 0; i < n; i++) vs2.pb(mp(i, 0));
				
				u = (v - 1 + n) % n;

				for(j = 0; j < u; j++)
					{	
						vs3 = vs2;

						// for(i = 0; i < vs2.size(); i++)
						// 	cout << vs[vs2[i].f] << " " << vs2[i].s << endl;
						// cout << endl << endl;

						vs2.clear();

						for(i = 0; i < k; i++)
							vs2.pb(mp(vs3[i].f, vs3[i].s + 1));

						for(i = k; i < vs3.size(); i++)
							vs2.pb(mp(vs3[i].f, vs3[i].s));

						sort(vs2.begin(), vs2.end(), cmp);
						
						// for(i = 0; i < vs2.size(); i++)
						// 	cout << vs[vs2[i].f] << " " << vs2[i].s << endl;
						// cout << endl << endl;
					}

				for(i = 0; i < k; i++) vs1.pb(vs2[i].f);
				sort(vs1.begin(), vs1.end());

				// for(i = 0; i < vs2.size(); i++)
				// 	cout << vs[vs2[i].f] << " " << vs2[i].s << endl;

				cout << "Case #" << t << ": ";
				for(i = 0; i < k; i++) cout << vs[vs1[i]] << " ";
				cout << endl;
				t++;
			}
		return 0;
	}