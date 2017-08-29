#include<iostream>
#include<cstdio>
#include<cstdlib>
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

int main()
{
    int n, r=1000000001, c=1, x;
    int i, j, minDiff=10000007;
    
    cin >> n;
    
    for(i=1; i<=n; i++)
        {
            if(n%i==0)
                {
                    if(minDiff>max(n/i, i)-min(n/i, i))
                        {
                            minDiff=max(n/i, i)-min(n/i, i);
                            r=max(n/i, i);
                            c=min(n/i, i);
                        }
                }
        }

    
    cout << c << " " << r << endl;
    return 0;
}