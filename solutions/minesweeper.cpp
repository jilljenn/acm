#include <iostream>
using namespace std;

#define NB_DIRS 8

int main(void) {
    int n = 1, m = 1, ii, jj, idField = 1;
    int dirs[NB_DIRS][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}}; // Vecteur de distances
    char grid[100][101];
    int nbMines[100][100];
    cin >> n >> m;
    while(n != 0) {
        cin.ignore();
        for(int i = 0; i < n; ++i)
            cin >> grid[i];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                nbMines[i][j] = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == '*') {
                    for(int dir = 0; dir < NB_DIRS; ++dir) {
                        ii = i + dirs[dir][0];
                        jj = j + dirs[dir][1];
                        if(ii >= 0 && ii < n && jj >= 0 && jj < m)
                            nbMines[ii][jj]++;
                    }
                }
            }
        if(idField > 1)
            cout << endl;
        cout << "Field #" << idField << ":" << endl;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == '*')
                    cout << '*';
                else
                    cout << nbMines[i][j];
            cout << endl;
        }
        idField++;
        cin >> n >> m;
    }
    return 0;
}
