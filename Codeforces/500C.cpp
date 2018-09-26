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

int a[1007], w[1007];
bool instack[1007];
stack <int> st, st2;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, k, u, v, ans = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> w[i];

		for(i = 1; i <= m; i++) cin >> a[i];
		
		st.p(a[m]);
		instack[a[m]] = 1;

		for(i = m - 1; i >= 1; i--)
			{
				if(!instack[a[i]])
					{
						st.p(a[i]);
						instack[a[i]] = 1;
					}
				else
					{
						while(st.top() != a[i])
							{
								// cout << st.top() << " ";
								st2.p(st.top());
								st.pop();
							}

						// cout << st.top() << endl;
						st.pop();

						while(!st2.empty())
							{
								st.p(st2.top());
								st2.pop();
							}
						st.p(a[i]);
					}
			}

		for(i = 1; i <= m; i++)
			{
				u = 0;

				while(st.top() != a[i])
					{
						st2.p(st.top());
						u += w[st.top()];
						st.pop();
					}
				st.pop();

				while(!st2.empty())
					{
						st.p(st2.top());
						st2.pop();
					}

				st.p(a[i]);
				
				ans += u;
			}

		cout << ans << endl;
		return 0;
	}