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

stack<lli> a;

int main()
	{	
		lli n, i;
		lli u, q;

		cin >> n;

		while(n--)
			{
				cin >> q;

				if(q==1)
					{
						cin >> u;

						if(a.empty())
							a.push(u);
						else 
							a.push(max(a.top(), u));
					}
				else if(q==2)
					a.pop();
				else
					cout << a.top() << endl;
			}
		return 0;
	}