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

priority_queue <int, vector <int>, greater <int> > up;
priority_queue <int, vector <int>, less <int> > low;

void insert(int n)
{
	if(n >= up.top() || up.empty())
		up.p(n);
	else low.p(n);

	if(up.size() - low.size() == 2) {
		low.p(up.top());
		up.pop();
	}
	else if(low.size() - up.size() == 2){
		up.p(low.top());
		low.pop();
	}
}

int median()
{
	if(low.size() == up.size())
		return low.top();
	else if(up.size() >= low.size()) return up.top();
	return low.top();
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t, n, a, b, c, i, j, u, v, ans;

		cin >> t;

		while(t--)
			{
				while(!up.empty()) up.pop();
				while(!low.empty()) low.pop();
				up.p(INT_MAX);
				low.p(-1);
				ans = 1;

				cin >> a >> b >> c >> n;

				insert(1);

				for(i = 2; i <= n; i++)
					{
						u = median();
						v = (((a * u) % mod + (b * i) % mod) % mod + c) % mod;
						// cout << up.top() << " " << low.top() << endl;
						
						ans += v;
						insert(v);
					}

				cout << ans << endl;
			}	
		return 0;
	}