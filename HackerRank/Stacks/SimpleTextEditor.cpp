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

stack<string> a;

int main()
	{
		int n, i, q, k;
		string s, s1;

		cin >> n;

		a.push(s);
		
		while(n--)
			{
				cin >> q;

				if(q==1)
					{
						cin >> s1;
						s=a.top();
						s+=s1;
						a.push(s);
					}
				else if(q==2)
					{
						cin >> k;

						s=a.top();
						q=s.size();
						
						s1=s.substr(0, q-k);
						
						//cout << s1 << endl;
						
						a.push(s1);
					}
				else if(q==3)
					{
						cin >> k;
						s=a.top();
						cout << s[k-1] << endl;
					}
				else
					a.pop();
			}

		return 0;
	}