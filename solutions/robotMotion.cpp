/* Modex ACM c.durr (2008)
   
   Robot Motion
*/

#include <iostream>

using namespace std;

char G[10][10];
int rows, cols;

void solve(int i, int j) {
  int s[10][10] = {0}; // l'heure de passage
  int t = 1; // l'heure courante
  // tant qu'on n'est pas sorti
  while (0<=i && i<rows && 0<=j && j<cols) {
    if (s[i][j]) {
      cout << s[i][j]-1 << " step(s) before a loop of " 
	   << t-s[i][j] << " step(s)" << endl;
      return;
    }
    // marquer le passage, et augmenter l'horloge
    s[i][j] = t++;
    // avancer
    switch (G[i][j]) {
    case 'E':
      j++; break;
    case 'W':
      j--; break;
    case 'S':
      i--; break;
    case 'N':
      i++; break;
    }
  }
  cout << t-1 << " step(s) to exit" << endl;
}


int main() {
  int start;
  while (cin >> rows >> cols >> start && rows>0) {
    for (int i=rows-1; i>=0; i--)
      for (int j=0; j<cols; j++) 
	cin >> G[i][j];
    solve(rows-1, start-1);
  }
}
