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
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)
#define maxm 1e18

const int N = 100007;

int a[N];
vi vs;
map <int, int> mx; 

int subArraySum(int n, int sum) 
{ 
  	mx.clear();
  	int ans = 0;
  	int curr_sum = 0; 
  	
  	mx[0] = 1;

    for(int i = 1; i <= n; i++) {
        curr_sum = curr_sum + a[i];
        ans += mx[curr_sum - sum];
        mx[curr_sum]++; 
    } 
  	
  	return ans;
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		u = 1;

		if(m == -1) vs.pb(-1), vs.pb(1);
		else if(m == 1) vs.pb(u);
		else {
				while(u < maxm) {
				vs.pb(u);
				u *= m;
			}
		}
		
		for(auto it : vs)
			ans += subArraySum(n, it);

		cout << ans << endl;

		return 0;
	}