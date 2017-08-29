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
#define f first
#define s second

int n, k, s, o = 0, edges, f, t, ec;

signed main() 
{
	cin >> n >> k;
	s = n - k - 1;
	edges = s / k;
	f = s - edges * k;

	if(edges == 0)
		{
	        if(f > 0)
		        {
		            if(f > 1)
			            cout << 4;
		            else
			            cout << 3;
		        }
	        else
		        cout << 2;

	        cout << endl;

			for(int i = k + 2; ec < n - 1; i++)
				{
					if(f > 0)
						{
							cout << 1 << " " << i << endl << i << " " << i - k << endl;
							ec += 2;
							f--;
						}
					else
						{
							cout << 1 << " " << i - k << endl;
							ec++;
						}
				}
		}
	else
		{
		    if(f>0)
		    {
	            if(f>1)
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
					if(f>0)
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

					if(f > 0)
						f--;
				}
		}

	return 0;
}