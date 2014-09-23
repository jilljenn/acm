#include <iostream>
using namespace std;

int main(void) {
    string s;
    int l[1000001], n, k;
    cin >> s;
    while(s != ".") {
        n = s.size();
        for(int i = 0; i <= n; ++i)
            l[i] = 0;
        for(int i = 2; i <= n; ++i) {
            k = i - 1;
            while(s[l[k]] != s[i - 1] && k > 0)
                k = l[k];
            l[i] = (s[l[k]] == s[i - 1]) ? l[k] + 1 : 0; // l[i] : longueur du plus grand préfixe propre de s[0..i-1] qui en soit également suffixe
        }
        if(n % (n - l[n]) == 0)
            cout << n / (n - l[n]) << endl;
        else
            cout << 1 << endl;
        cin >> s;
    }
    return 0;
}
