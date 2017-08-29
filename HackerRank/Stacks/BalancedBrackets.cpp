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

stack<char> a;

int main()
	{
		int t, i, n;
		string s;

		cin >> t;

		while(t--)
			{
				cin >> s;
				n=s.size();

				for(i=0; i<n; i++)
					{
						if(s[i]=='}' || s[i]==']' || s[i]==')')
							{
								if(a.empty())
									{
										a.push(s[i]);
										break;
									}

								if((s[i]=='}' && a.top()=='{') || (s[i]==']' && a.top()=='[') || (s[i]==')' && a.top()=='('))
									a.pop();
							}
						else if(s[i]=='[' || s[i]=='{' || s[i]=='(')
							a.push(s[i]);
						else
							break;
					}

				if(!a.empty())
					cout << "NO" << endl;
				else
					cout << "YES" << endl;

				while(!a.empty())
					a.pop();
			}

		return 0;
	}