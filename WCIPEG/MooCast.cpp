#include<iostream>
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
#include<fstream>

using namespace std;

#define lli long long int
#define mod 1000000007
#define pb push_back

vector<lli> a;

int main()
	{
		ifstream fin ("moocast.in");
		ofstream fout ("moocast.out");

		lli n, k, i, u, q, f, l;
		vector<lli>::iterator it1;
		vector<lli>::iterator it2;
		lli ans;

		fin >> n >> q;

		for(i=0; i<n; i++)
			{
				fin >> u;
				a.pb(u);
			}

		sort(a.begin(), a.end());

		while(q--)
			{
				fin >> f >> l;
				it1=lower_bound(a.begin(), a.end(), f);
				it2=upper_bound(a.begin(), a.end(), l);
				ans=it2-a.begin();
				ans-=it1-a.begin();

				fout << ans << endl;
			}
		return 0;
	}