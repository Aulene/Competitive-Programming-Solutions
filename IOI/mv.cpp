#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define optimizar ios_base::sync_with_stdio(0); cin.tie(0)
#define lld long long int
#define IZQ (nodo * 2)
#define DER (nodo * 2 + 1)
#define MAXN 52
#define MAX_Q 500003
#define LOG_N 12
using namespace std;

int mov[4][2] = {
-1, 0, // N
0, -1, // W
0, 1, // E
1, 0, // S
};

struct nodo {
    bool n, s, e, w;
    int color;
};

int n, m;
nodo arr[MAXN][MAXN];

int cuantos[MAXN * MAXN];
int color;

int M;
int mayor, x, y;
char car;

void colorea(int i, int j) {
    if(arr[i][j].color) return;
    arr[i][j].color = color;
    cuantos[color]++;
    if(!arr[i][j].n) colorea(i - 1, j);
    if(!arr[i][j].s) colorea(i + 1, j);
    if(!arr[i][j].w) colorea(i, j - 1);
    if(!arr[i][j].e) colorea(i, j + 1);
}

int main() {
    optimizar;
    cin >> n >> m;
    swap(n, m);
    int aux;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> aux;
            if(aux & 1) arr[i][j].w = true;
            aux >>= 1;
            if(aux & 1) arr[i][j].n = true;
            aux >>= 1;
            if(aux & 1) arr[i][j].e = true;
            aux >>= 1;
            if(aux & 1) arr[i][j].s = true;
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(!arr[i][j].color) {
                color++;
                colorea(i, j);
                M = max(M, cuantos[color]);
            }

    cout << color << "\n";
    cout << M << "\n";
    for(int j = 1; j <= m; j++) {
        for(int i = n; i >= 1; i--) {
            for(int k = 0; k < 4; k++) {
                aux = arr[i + mov[k][0]][j + mov[k][1]].color;
                if(arr[i][j].color != aux) {
                    if(mayor < cuantos[arr[i][j].color] + cuantos[aux]) {
                        mayor = cuantos[arr[i][j].color] + cuantos[aux];
                        x = i, y = j;
                        switch(k) {
                            case 0: car = 'N'; break;
                            case 1: car = 'W'; break;
                            case 2: car = 'E'; break;
                            case 3: car = 'S'; break;
                        }
                    }
                }
            }
        }
    }
    cout << mayor << "\n";
    cout << x << " " << y << " " << car << "\n";
    return 0;
}