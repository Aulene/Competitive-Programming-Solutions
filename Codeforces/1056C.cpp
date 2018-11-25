#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vpi vector < pair <int, int> >
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

const int N = 20007;

int a[N], c[N];
int mx[N];

bool cmp(pi a, pi b) {
	return a.s > b.s;
}

bool cmp2(pi x, pi y) {
	if(a[x.f] != a[y.f]) return a[x.f] > a[y.f];  
	return a[x.s] < a[y.s];
}

signed main()
	{
		// ios_base::sync_with_stdio(false);
		// cin.tie(NULL);
		// cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		vpi vs, vs2;

		int n, m, i, j, u, v, t;

		cin >> n >> m;

		for(i = 1; i <= 2 * n; i++) {
			cin >> a[i];
			vs2.pb({i, a[i]});
		}

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			if(a[u] < a[v]) swap(u, v);
			vs.pb({u, v});
			mx[u] = v, mx[v] = u;
		}

		// cout << vs.size() << endl;

		sort(vs.begin(), vs.end(), cmp2);
		sort(vs2.begin(), vs2.end(), cmp);
		reverse(vs2.begin(), vs2.end());

		// cout << endl;
		// for(auto it : vs) cout << it.f << " " << it.s << endl; cout << endl;
		// for(auto it : vs2) cout << it.f << " " << it.s << endl; cout << endl;

		int idx = vs2.size() - 1;
		int lst = vs.size() - 1;
		int num = 2 * n;

		// cout << lst << " " << idx << " " << num << endl;
		
		cin >> t;

		if(t == 1) {

			while(lst >= 0) {
				// cout << "ugh " << lst << endl;

				pi pz = vs[lst];
				int x = pz.f, v = pz.s;

				if(c[x]) {
					lst--;
					continue;
				}
				else {
					cout << x << endl;
					fflush(stdout);
					c[x] = 1;
					
					num--;
					lst--;

					if(num) {
						cin >> u;
						c[u] = 1;
						num--;
					} else break;
				}
			}

			while(idx >= 0) {
				int x = vs2[idx].f;

				if(!c[x]) {
					cout << x << endl;
					c[x] = 1;
					num--;

					if(num) {
						cin >> u;
						c[u] = 1;
						num--;
						if(!num) break;
					} else break;
				}

				if(!num) break;

				idx--;
			}
		}
		else {
			while(num) {
				cin >> u;
				num--;
				c[u] = 1;

				// cout << u << " " << lst << endl;

				if(!num) break;
					
				if(mx[u] != 0) {
					cout << mx[u] << endl;
					fflush(stdout);

					c[mx[u]] = 1;
					num--;
				}
				else if(lst >= 0) {
					// cout << "ugh " << lst << endl;
						
					while(lst >= 0) {

						// cout << "ugh " << lst << endl;

						pi pz = vs[lst];
						int x = pz.f, v = pz.s;

						if(c[x]) {
							lst--;
							continue;
						}
						else {
							cout << x << endl;
							fflush(stdout);
							c[x] = 1;
							
							num--;
							lst--;

							if(num) {
								cin >> u;
								c[u] = 1;
								num--;
							} else break;
						}
					}

					while(idx >= 0) {
						int x = vs2[idx].f;

						if(!c[x]) {
							cout << x << endl;
							fflush(stdout);
							c[x] = 1;
							num--;

							if(num) {
								cin >> u;
								c[u] = 1;
								num--;
							} else break;
						}

						if(!num) break;

						idx--;
					}
				}
				else {
					while(idx >= 0) {
						int x = vs2[idx].f;

						if(!c[x]) {
							cout << x << endl;
							fflush(stdout);
							c[x] = 1;
							num--;

							if(num) {
								cin >> u;
								c[u] = 1;
								num--;
							} else break;
						}

						if(!num) break;

						idx--;
					}
				}
			}
		}




		return 0;
	}