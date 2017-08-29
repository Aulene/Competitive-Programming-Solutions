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

int prime[100007];
vector <int> primes;
map <int, int> X, Y;
set <int> primeSet;

void sieve()
{
    for(int i = 2; i <= 100007; i++)
        if(!prime[i])
            {
                primes.pb(i);
                for(int j = 1LL * i * i; j <= 100007; j += i)
                    prime[j] = i;
            }
}

int makeSet(int x, map <int, int> &X)
{
    for(int i = 0; 1LL * primes[i] * primes[i] <= x; i++)
        {
            while(x % primes[i] == 0)
                {
                    X[primes[i]]++;
                    primeSet.insert(primes[i]);
                    x /= primes[i];
                }
        
        }

    if(x > 1)
        {
            X[x]++;
            primeSet.insert(x);
        }

    return 0;
}

bool check(int a, int b)
{
    if(a == 0 || b == 0) 
        return 0;

    if((a + b) % 3) 
        return 0;

    if(((b - a) + (a + b) / 3) % 2) 
        return 0;

    int u = b - a + (a + b) / 3;
    int v = (a + b) / 3 - (b - a);

    if(u >= 0 && v >= 0)
        return 1;
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    int t, x, y, a, b;
    bool ans;
    set<int> :: iterator it;
   
    cin >> t;

    while(t--)
        {
            X.clear(), Y.clear(), primeSet.clear();
            ans = 1;

            cin >> x >> y;

            makeSet(x, X), makeSet(y, Y);

            for(it = primeSet.begin(); it != primeSet.end(); it++)
                {
                    a = X[*it];
                    b = Y[*it];

                    if(!check(a, b) && !check(b, a))
                        {
                            cout << "No" << endl;
                            ans = 0;
                            break;
                        }
                }

            if(ans) 
                cout << "Yes" << endl;
        }

    return 0;
}