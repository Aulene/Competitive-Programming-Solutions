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

int a[N], inc[N], d[N];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
        int n, m, i, j, u, v, w, h;

        cin >> n >> m;

        for(i = 1; i <= n; i++) cin >> a[i];
        
        inc[1] = -1;
        d[n] = n + 1;

        for(i = 2; i <= n; i++)
            if(a[i] > a[i - 1]) inc[i] = i;
            else inc[i] = inc[i - 1];

        for(i = n - 1; i >= 1; i--) 
            if(a[i + 1] < a[i]) d[i] = i + 1;
            else d[i] = d[i + 1];

        // for(i = 1; i <= n; i++) cout << inc[i] << " "; cout << endl;
        // for(i = 1; i <= n; i++) cout << d[i] << " "; cout << endl;

        while(m--) {
            cin >> u >> v;
            if(d[u] < inc[v]) cout << "No\n";
            else cout << "Yes\n"; 
        }
		return 0;
	}