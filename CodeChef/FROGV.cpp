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
lli v[100007];
lli k;

bool query(lli u, lli v)
{
	vector<lli>::iterator it, it2;

	it=lower_bound(a.begin(), a.end(), u);
	//cout << *it << endl;

	while(true)
		{
			it2=upper_bound(it+1, a.end(), *it+k);
			it2--;

			//cout << *it << " " << *it2 << endl;
	
			if(*it2>=v)
				return 1;

			if(it==it2)
				return 0;

			it=it2;
		}
}

int main()
	{
		lli n, q, i, x, y;
		vector<lli>::iterator it;
		bool ans;

		cin >> n >> k >> q;

		for(i=1; i<=n; i++)
			{
				cin >> v[i];
				a.pb(v[i]);
			}

		sort(a.begin(), a.end());

		while(q--)
			{
				cin >> x >> y;
				ans=query(v[x], v[y]);

				if(ans)
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}
		return 0;
	}