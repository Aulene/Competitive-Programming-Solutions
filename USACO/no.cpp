
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

struct st
{
	string state;
	string code;
};

map<string, vector<int> > occ1;
st a[200007];
bool visited[200007];

int main()
	{
		lli n, i, ans=0, u, j;
		string s1, s2, s;
		vector<int>::iterator it;

		cin >> n;

		for(i=0; i<n; i++)
			{
				cin >> a[i].state >> a[i].code;
				a[i].state=a[i].state.substr(0, 2);
			}

		for(i=0; i<n; i++)
			for(j=i+1; j<n; j++)
				{
					if(a[i].state==a[j].code && a[i].code==a[j].state)
						ans++;
				}
		cout << ans << endl;
		return 0;
	}