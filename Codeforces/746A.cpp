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

int main()
{
    int a, b, c;
    int a1, b1, c1, i;
    int ans=0;
    
    cin >> a >> b >> c;

    for(i=1;; i++)
        {
            a1=i;
            b1=2*i;
            c1=4*i;

            if(a>=a1 && b>=b1 && c>=c1)
                ans=a1+b1+c1;
            else
                break;
        } 
    
    cout << ans << endl;
    return 0;
}