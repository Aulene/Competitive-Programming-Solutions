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

vector<lli> a;

int main()
	{
		int t, n, i;
		lli k, u, ans, x;
		vector<lli>::iterator it1, it2;

		cin >> t;

		while(t--)
			{
				ans=0;

				cin >> n >> k;

				for(i=0; i<n; i++)
					{
						cin >> u;
						a.pb(u);
					}

				sort(a.begin(), a.end());

				for(it1=a.begin(); it1!=a.end(); it1++)
					{
						x=*it1;
						x=k^x;
						cout << *it1 << " " << x << endl;
						it2=lower_bound(it1+1, a.end(), x);
						ans+=it2-it1;
					}

				cout << ans << endl;
				a.clear();
			}

		return 0;
	}