#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mid (start + end) / 2
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int >

int board[1007][1007];
bool vis[1007][1007];

int check(int x, int y, int n) {
    if(x >= 1 && x <= n && y >= 1 && y <= n) return 1;
    return 0;
}

int bfs(int sx, int sy, int ex, int ey, int n)
{
    queue < pair <int, int> > q;
    q.p({sx, sy});

    while(!q.empty())
        {
            pi pz = q.front();
            q.pop();

            if(!check(pz.f, pz.s, n)) continue;
            if(vis[pz.f][pz.s]) continue;
            if(board[pz.f][pz.s]) continue;
            
            if(pz.f == ex && pz.s == ey) return 1;
            
            vis[pz.f][pz.s] = 1;

            // cout << pz.f << " " << pz.s << endl;
            
            int x, y, i = 1;

            x = pz.f + i, y = pz.s + i;
            if(check(x, y, n)) { 
                if(!vis[x][y]) q.p({x, y});;
            }

            x = pz.f + i, y = pz.s - i;
            if(check(x, y, n)) { 
                if(!vis[x][y]) q.p({x, y});;
            }

            x = pz.f - i, y = pz.s + i;
            if(check(x, y, n)) { 
                if(!vis[x][y]) q.p({x, y});;
            }

            x = pz.f - i, y = pz.s - i;
            if(check(x, y, n)) { 
                if(!vis[x][y]) q.p({x, y});;
            }

            x = pz.f - i, y = pz.s;
            if(check(x, y, n)) { 
                if(!vis[x][y]) q.p({x, y});;
            }

            x = pz.f + i, y = pz.s;
            if(check(x, y, n)) { 
                if(!vis[x][y]) q.p({x, y});;
            }

            x = pz.f, y = pz.s + i;
            if(check(x, y, n)) { 
                if(!vis[x][y]) q.p({x, y});;
            }

            x = pz.f, y = pz.s - i;
            if(check(x, y, n)) { 
                if(!vis[x][y]) q.p({x, y});;
            }
        }
    
    return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, q, u, v, i, j, x, y, ans;
        pi pz, b, c;

        cin >> n;
        cin >> pz.f >> pz.s; cin >> b.f >> b.s; cin >> c.f >> c.s;

        for(i = 1; i <= n; i++)
            board[i][pz.s] = 1, board[pz.f][i] = 1;
        
        for(i = 0; i <= n; i++) {
            int x, y;
            x = pz.f + i, y = pz.s + i;
            if(check(x, y, n)) { board[x][y] = 1; }
            x = pz.f + i, y = pz.s - i;
            if(check(x, y, n)) { board[x][y] = 1; }
            x = pz.f - i, y = pz.s + i;
            if(check(x, y, n)) { board[x][y] = 1; }
            x = pz.f - i, y = pz.s - i;
            if(check(x, y, n)) { board[x][y] = 1; }
        }

        // for(i = 1; i <= n; i++) {
        //     for(j = 1; j <= n; j++) cout << board[i][j] << " "; cout << endl;
        // }
        ans = bfs(b.f, b.s, c.f, c.s, n);
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;



		return 0;
	}