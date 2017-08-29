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
#define p push

struct answer
{
	lli el;
	lli ans;	
};

lli a[100007];
stack<lli> ind;
lli ans[100007];
vector<lli> prefix;
answer ok[100007];

int computeSubarrayAnswers(int n)
{
	lli i, u, v;

	for(i=0; i<n; i++)
		{
			if(ind.empty())
				{
					ind.p(i);
					continue;
				}

			if(a[ind.top()]<=a[i])
				{
					while(!ind.empty() && a[ind.top()]<=a[i])
						{
							u=ind.top();
							ind.pop();

							if(!ind.empty() && a[ind.top()]<a[i])
								{
									v=ind.top();
									ans[v]+=ans[u];
								}	
						}

					ans[i]+=ans[u];
				}

			ind.p(i);
		}

	while(!ind.empty())
		{
			u=ind.top();
			ind.pop();

			if(!ind.empty())
				{
					v=ind.top();
					ans[v]+=ans[u];
				}
		}

	return 0;
}

bool compare(answer x, answer y)
{
	if(x.el > y.el)
		return true;
	return false;
}

int main()
	{
		ifstream fin ("inp.txt");
        ofstream fout ("ans.txt");

		lli t, n, m;
		lli q;
		lli i, u, v, j;
		vector<lli>::iterator it;

		fin >> t;

		while(t--)
			{
				for(i=0; i<100007; i++)
					ans[i]=1;

				fin >> n >> q;

				for(i=0; i<n; i++)
					{
						fin >> a[i];
						ok[i].el=a[i];
					}

				computeSubarrayAnswers(n);

				for(i=0; i<n; i++)
					ok[i].ans=ans[i];

				sort(ok, ok+n, compare);

				j=ok[0].ans;
				prefix.pb(j);
				for(i=1; i<n; i++)
					{
						j+=ok[i].ans;
						prefix.pb(j);
					}

				while(q--)
					{
						fin >> m;
						it=lower_bound(prefix.begin(), prefix.end(), m);
						j=it-prefix.begin();
						fout << ok[j].el << endl;
					}

				prefix.clear();
			}	

		return 0;
	}