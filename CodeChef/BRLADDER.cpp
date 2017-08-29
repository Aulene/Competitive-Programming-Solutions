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

int main()
	{
		lli t, a, b, x, temp;

		cin >> t;

		while(t--)
			{
				bool ans=0;

				cin >> a >> b;

				if(a>b)
					{
						temp=a;
						a=b;
						b=temp;
					}

				//cout << a << " " << b << endl;
				
				if(b==a+2)
					ans=1;

				if(b-a==1 && a%2==1)
					ans=1;

				if(ans)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
		return 0;
	}