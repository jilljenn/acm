/* c.durr - jill-jênn vie - préparation ACM/ICPC/SWERC 2014
    find the twin
    trier les listes puis avec un parcours détecter la première paire.
    complexité O(kn log n), k=max long chaînes, n=nb chaînes
    astuce: utiliser une function solve, pour terminer la recherche dés
    réponse trouvée.
    */
#include <iostream>

using namespace std;

string solve(string tab [], int n) {
    for (int i=0; i<n-1; i++) 
        if (tab[i]==tab[i+1]) 
            return tab[i];
    return "None";
}

int main() {
    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        int n;
        cin >> n;
        string tab[1000];
        for (int i=0; i<n; i++)
            cin >> tab[i];
        sort(tab, tab+n);
        cout << "Case "<<t<<"# " << solve(tab, n)<<endl;
    }
    return 0;
}