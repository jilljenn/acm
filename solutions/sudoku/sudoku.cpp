#include <iostream>

using namespace std;

int row(int i) { return i/9; }
int col(int i) { return i%9; }
int blk(int i) { return 3*(row(i)/3) + col(i)/3; }

bool conflict(int i, int j) {
    return i!=j &&( col(i)==col(j) 
                 || row(i)==row(j) 
                 || blk(i)==blk(j));
}

int M[81];

int N[81][8+6+6];


bool solve(int i) {
    if (i==81) return true;
    if (M[i]>0) return solve(i+1);
    bool deja[10] = {false};
    for (int k=0; k<8+6+6; k++)
        deja[M[ N[i][k] ]] = true;
    for (int v=1; v<=9; v++) 
        if (!deja[v]) {
           M[i]= v;
           if (solve(i+1)) return true;
        }
    M[i]=0;
    return false;
}

int main() {
    for (int i=0; i<81; i++) {
        int k = 0;
        for (int j=0; j<81; j++) {
            if (conflict(i,j))
                N[i][k++] = j;
        }
    }
    int t;
    string s;
    cin >> t;
    while (t-->0) {
        for (int r=0; r<9; r++) {
            cin >> s;
            for (int c=0; c<9; c++)
                M[9*r+c] = s[c] - '0';
        }
        solve(0);
        for (int r=0; r<9; r++) {
            for (int c=0; c<9; c++)
                cout << M[9*r+c];
            cout << endl;
        }
    }
}