/* c.durr - jill-jênn vie - préparation ACM/ICPC/SWERC 2014
    Pascal triangle of death
    grands entiers, doivent être codée par tableau de caractères.
    derniere ligne n satisfait
       2^n > (n choose n/2) >= 10**60 =~= 2**200 
       pour être précis il a y 205 éléments dans la dernière ligne.
       Alors comme la grille est petite, pas la peine d'optimiser 
       la représentation des grands entiers.
    */
#include <iostream>

using namespace std;

// additionner deux nombres représentés par des chaînes
string add(string a, string b) {
    char buf[63] = {0};
    int i=61;
    int ret=0; // retenue
    int ia = a.size()-1;
    int ib = b.size()-1;
    while (ia>=0 || ib>=0 || ret>0) {
        if (ia>=0)
            ret += a[ia--]-'0';
        if (ib>=0)
            ret += b[ib--]-'0';
        buf[i--] = '0' + (ret%10);
        ret /= 10;
    }
    return string(&buf[i+1]);
}

int main() {
    string t[2][205] = {"1"};  // seules deux lignes à la fois sont importantes
    int n=1, p=0;                         // p=parité de n
    while (true) {
        for (int i=0; i<n-1; i++) {       // -- afficher
            cout << t[p][i] << " ";
        }
        cout << t[p][n-1] << endl;
        if (t[p][n/2].size()>60)          // -- test fin
            break;
        t[1-p][0] = t[1-p][n] = t[p][0];  // -- calculer prochaine ligne
        for (int i=1; i<n; i++)
            t[1-p][i] = add( t[p][i-1], t[p][i] );
        n++;
        p=1-p;
    }
    return 0;
}