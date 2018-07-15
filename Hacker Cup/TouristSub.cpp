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
		ifstream fin ("tourist.txt");
		ofstream fout ("ans.txt");

		int t = 1, T, n, i, j, u, v, k, m;
		string s;

		fin >> T;	

		while(t <= T)
			{
				vs.clear(); vs1.clear();
				vs2.clear(); vs3.clear();

				fin >> n >> k >> v;

				for(i = 0; i < n; i++) 
					fin >> s, vs.pb(s);

				// cout << vs[i] << endl;
				
				for(i = 0; i < n; i++) vs2.pb(mp(i, 0));
					
				u = (v - 1 + n) % n;

				for(j = 0; j < u; j++)
					{	
						vs3 = vs2;

						// for(i = 0; i < vs2.size(); i++)
						// 	fout << vs[vs2[i].f] << " " << vs2[i].s << endl;
						// fout << endl << endl;

						vs2.clear();

						for(i = 0; i < k; i++)
							vs2.pb(mp(vs3[i].f, vs3[i].s + 1));

						for(i = k; i < vs3.size(); i++)
							vs2.pb(mp(vs3[i].f, vs3[i].s));

						sort(vs2.begin(), vs2.end(), cmp);
						
						// for(i = 0; i < vs2.size(); i++)
						// 	fout << vs[vs2[i].f] << " " << vs2[i].s << endl;
						// fout << endl << endl;
					}

				for(i = 0; i < k; i++) vs1.pb(vs2[i].f);
				sort(vs1.begin(), vs1.end());

				// for(i = 0; i < vs2.size(); i++)
				// 	fout << vs[vs2[i].f] << " " << vs2[i].s << endl;

				fout << "Case #" << t << ": ";
				for(i = 0; i < k; i++) fout << vs[vs1[i]] << " ";
				fout << endl;
				t++;
			}
		return 0;
	}