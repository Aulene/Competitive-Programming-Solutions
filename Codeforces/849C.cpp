#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
 
string solve(int &N, char x) 
{
    int left = 'z' - x + 1,  n = 1, L = 0;

    if (N <= left) 
        {
            string re = "";
            
            while(N) 
                {
                    N--;
                    re += x;
                    x++;
                }
            return re + re;
        }
   
    while(L < N) 
        {
            n++;
            L = n * (n - 1) / 2;
        }

    if(L > N) n--;

    L = n * (n - 1) / 2;
    N -= L;

    string ans(n, x);
    return ans;
}

string solve2(int k) 
{
    if (k == 0) 
        return "a";

    char x = 'a';

    string re = "";

    while (k > 0) 
        {
            re += solve(k, x);
            x++;
        }

    return re;
}

signed main() 
{ 
    int k;
    cin >> k;
    cout << solve2(k) << endl;
}
