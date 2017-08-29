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

using namespace std;

#define lli long long int
#define mod 1000000007
#define pb push_back

map<string, bool> visited;

int main()
	{
		string s, s1;
		int n, i, ans=0;

		cin >> s;
		n=s.size();

		s1=s;
		
		s1=s1[n-1]+s1.substr(0, n-1);

		while(s1!=s)
			{
				//cout << s1 << endl;

				if(!visited[s1])
					{
						ans++;
						visited[s1]=1;
					}
				s1=s1[n-1]+s1.substr(0, n-1);
			}

		cout << ans+1 << endl;

		return 0;
	}