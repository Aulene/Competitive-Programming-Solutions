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

#define MAX_PRIME 1001
#define MAX_CNT 1000001
#define PRIME_CNT 168

using namespace std;

vector< bool > prime_bool_arr( MAX_CNT, true );
vector< int > prime_arr;
map< int, int > inv;

void sieve(  )
{
    int i, j;

    for( i = 2 ; i < MAX_CNT; i++)
    {
        if( prime_bool_arr[ i ] )
        {
            for(j = 2; j <= MAX_CNT/i; j++)
            {
                prime_bool_arr[ i*j ] = false;
            }
        }
    }
    int cnt = 1;
    for( i = 2; i <= MAX_PRIME; i++)
    {
        if( prime_bool_arr[i] )
        {
            prime_arr.push_back( i );
            inv[ i ] = cnt;
            cnt++;
        }
    }
}

int main()
{
    ios::sync_with_stdio( false );
    cout.tie(0);
    cin.tie(0);

    int n, q;

    cin>>n;
    
    vector<int> V(n);
    vector< vector<int> > res( n, vector<int>( PRIME_CNT, 0 ) );
    vector< vector<int> > sum_vec( n+1, vector<int>( PRIME_CNT+1, 0 ) );
    
    int i, j;

    for(i=0;i<n;i++)
        cin>>V[i];

    sieve();

    for(i=0;i<n;i++)
        {
            for(j=0;j<4;j++)
                {
                	int val = V[i];
                    cout<<"d"<<val;

                    if( val % prime_arr[j] == 0 )
                        {
                            int x = val/prime_arr[j];
                            
                            if( prime_bool_arr[x] && x > prime_arr[j] )
                                {
                                	cout<<"b "<<x<<" "<<i<<" "<<j<<endl;
                                	res[i][x]++;
                                }
                        }
                    while( val % prime_arr[j] == 0 )
                        {
                        	cout<<"a "<<val<<" "<<i<<" "<<j<<endl;
                            res[i][j]++;
                            val = val/prime_arr[j];
                        }

                }
        }
	
	
	
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=PRIME_CNT;j++)
                {
                    sum_vec[i][j] = sum_vec[i-1][j] + sum_vec[i][j-1] + res[i-1][j-1] - sum_vec[i-1][j-1];
                }
        }
    
    cin>>q;
    int l, r, a, b;
    for(i=0;i<q;i++)
    {
        cin>>l>>r>>a>>b;
        int modif_a = inv[a];
        int modif_b = inv[b];
        cout<<sum_vec[r][modif_b] + sum_vec[l-1][modif_a-1] - sum_vec[r][modif_a-1] - sum_vec[l-1][modif_b]<<endl;
    }

    return 0;
}
