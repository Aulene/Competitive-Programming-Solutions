#include <bits/stdc++.h>
#include <unordered_map>

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
#define vpi vector < pair <int, int> > 
#define mid (start + end) / 2
#define pi pair <int, int>

const int N = 100007;

vpi vs;
set <int> sx;
map <string, int> mx;
map <int, string> lx;

int lk[N], sz[N];

int find(int x) { while(x != lk[x]) x = lk[x]; return x; }

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    lk[b] = a;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
        int n, m, i, j, u = 1, v, w, h;
        string s1, s2;

		cin >> n;

        for(i = 0; i < n; i++) {
            cin >> s1 >> s2;
            if(!mx[s1]) {
                mx[s1] = u++;
                lx[mx[s1]] = s1;
            }

            if(!mx[s2]) {
                mx[s2] = u++;
                lx[mx[s2]] = s2;
            }

            sx.erase(mx[s1]);
            sx.insert(mx[s2]);
            vs.pb({mx[s1], mx[s2]});
        }

        for(i = 1; i < N; i++) lk[i] = i;
        for(i = 1; i < N; i++) sz[i] = 1;
        
        for(auto it : vs) {
            u = it.f, v = it.s;
            // cout << u << " " << v << endl;
            unite(u, v);
        }

        cout << sx.size() << endl;
        for(auto it : sx) cout << lx[find(it)] << " " << lx[it] << endl;

		return 0;
	}