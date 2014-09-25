/* Modex ACM c.durr (2008)

   Ordering Tasks
   http://icpcres.ecs.baylor.edu/onlinejudge/external/103/10305.html

*/

#include <iostream>

using namespace std;

const int MAX=100;
// nb sommets
int n;

//graphe oriente par liste d'adjacence
int G[MAX][MAX];


// d[u] = degree du sommet u
int d[MAX];

// topo[i] = i-eme sommet dans l'ordre topologique
int topo[MAX];

int t; // nb sommets qui n'ont pas fini leur traitement dfs

// marques de visite du dfs
bool deja[MAX];

void dfs(int i) {
  deja[i] = true;
  for (int k=0; k<d[i]; k++) {
    int j = G[i][k];
    if (!deja[j])
      dfs(j);
  }
  topo[--t] = i;
}

void dfs() {
  for (int i=0; i<n; i++)
    deja[i] = false;
  t = n;
  for (int i=0; i<n; i++)
    if (!deja[i])
      dfs(i);
}
  

int main() {
  int m;
  while (cin >> n >> m && n>0) {
    for (int i=0; i<n; i++)
      d[i] = 0;
     while (m--) {
      int i,j;
      cin >> i >> j;
      i--; j--;
      G[i][d[i]++] = j;
    }
    dfs();
    for (int k=0; k<n; k++)
      cout << topo[k]+1 << (k==n-1? '\n' : ' ');
  }
}
