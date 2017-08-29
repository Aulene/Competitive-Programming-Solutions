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

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define s second

int n, k, s, edges, leaf, t, addNodes;

signed main() 
{
	cin >> n >> k;
	s = n - k - 1;
	edges = s / k;
	leaf = s - edges * k;

	if(edges == 0)
		{
	        if(leaf > 0)
		        {
		            if(leaf > 1)
			            cout << 4;
		            else
			            cout << 3;
		        }
	        else
		        cout << 2;

	        cout << endl;

			for(int i = k + 2; addNodes < n - 1; i++)
				{
					if(leaf > 0)
						{
							cout << 1 << " " << i << endl << i << " " << i - k << endl;
							addNodes += 2;
							leaf--;
						}
					else
						{
							cout << 1 << " " << i - k << endl;
							addNodes++;
						}
				}
		}
	else
		{
		    if(leaf > 0)
		    {
	            if(leaf > 1)
		            {
		                cout << 2 * (edges + 1) + 2;
		            }
	            else
		            {
		                cout << 2 * (edges + 1) + 1;
		            }
		    }
		    else
			    {
		            cout << 2 * (edges + 1);
			    }
		    cout << endl;

			int i = k + 2, test = 2;

			while(i <= n)
				{
					if(leaf > 0)
						t = edges + 1;
					else
						t = edges;

					cout << 1 << " " << i << endl;
					t--;
					
					while(t > 0)
						{
			                i++;
			                t--;
							cout << i - 1 << " " << i << endl;
						}

					cout << i << " " << test << endl;
					test++;
					i++;

					if(leaf > 0)
						leaf--;
				}
		}

	return 0;
}