#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair

vector <lli> a, b, c;
stack <lli> s;

int main()
	{
		lli n, i, j, x;
		lli ans;

		vector <lli>::iterator it;

		cin >> n;

		for(i=0; i<n; i++)
			{
				cin >> x;
				a.pb(x);
			}

		for(i=0; i<n-1; i++)
			{
				cin >> x;
				b.pb(x);
			}

		for(i=0; i<n-2; i++)
			{
				cin >> x;
				c.pb(x);
			}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());

		for(i=0; i<n; i++)
			s.p(a[i]);

		for(i=n-1; i>=0; i--)
			{
				if(b[i]!=s.top())
					ans=s.top();
				s.pop();
			}

		cout << ans << endl;

		for(i=0; i<n-1; i++)
			s.p(b[i]);

		for(i=n-2; i>=0; i--)
			{
				if(c[i]!=s.top())
					ans=s.top();
				s.pop();
			}

		cout << ans << endl;
		return 0;
	}