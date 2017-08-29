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

int n, k;
map<string, bool> visited;
vector<string> ans;

int recur(string s, int index, int ones)
{
	if(visited[s])
		return 0;

	if(index>=n && ones==k)
		{
			ans.pb(s);
			return 0;
		}

	visited[s]=1;

	string s1=s;

	s[index]='0';
	//cout << s << endl;
	recur(s, index+1, ones);
	
	s1[index]='1';
	//cout << s1 << endl;
	recur(s1, index+1, ones+1);
	
	return 0;
}

int main()
	{
		int t, i;
		vector<string>::iterator it;

		cin >> t;

		while(t--)
			{
				cin >> n >> k;
				
				string s(n, 'X');
				cout << "The bit patterns are " << endl;
				recur(s, 0, 0);

				sort(ans.begin(), ans.end(), greater<string>());
				for(it=ans.begin(); it!=ans.end(); it++)
					cout << *it << endl;
				cout << endl;

				visited.clear();
				ans.clear();
			}

		return 0;
	}