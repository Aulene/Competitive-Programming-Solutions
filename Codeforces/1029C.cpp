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
#define vp vector < pair <int, int> >
#define vi vector <int> 
#define vvi vector < vector <int> > 

multiset <int> st, sv;
vp vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v, x, y, ans = 0;

		cin >> n;
		
		for(i = 0; i < n; i++)
			{
				cin >> u >> v;
				vs.pb(mp(u, v));
				st.insert(u), sv.insert(v);
			}

		for(i = 0; i < n; i++)
			{
				u = vs[i].f, v = vs[i].s;

				auto itr = st.find(u);
				if(itr != st.end())
				    st.erase(itr);

				x = *st.rbegin();

				itr = sv.find(v);
				if(itr != sv.end())
				    sv.erase(itr);

				y = *sv.begin();

				if(y > x) ans = max(ans, y - x);

				st.insert(u), sv.insert(v);
			}

		cout << ans << endl;

		return 0;
	}
