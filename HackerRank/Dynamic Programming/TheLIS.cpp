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
#define pb push_back
#define lb lower_bound

multiset<lli> s;
multiset<lli>::iterator it;

lli a[1000007];

int main()
	{
		int n, i;

		cin >> n;

		for(i=0; i<n; i++)
			cin >> a[i];

		for(i=0; i<n; i++)
			{
				s.insert(a[i]);

				it=s.lb(a[i]);
				it++;

				if(it!=s.end())
					s.erase(it);
			}

		cout << s.size() << endl;
		return 0;
	}