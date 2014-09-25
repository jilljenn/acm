/* c.durr - jill-jênn vie - préparation ACM/ICPC/SWERC 2014
    Power Strings
    UVA 10298
    http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1239

    L'entrée est grande, il faut utiliser les chaînes en C à place de la classe string.
    */
#include <iostream>
#include <cstring>

using namespace std;

const int M = 1000001;

int main() {
    char s[M], t[M+M];
    while (true) {
        cin >> s;
        if (strcmp(s,".")==0)
            break;
        int n = strlen(s);
        strcpy(t,s);
        strcpy(t+n,s);
        int i = strstr(t+1, s)-t ;
        cout << n/i << endl;
    }
    return 0;
}