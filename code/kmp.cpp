#include <iostream>
using namespace std;

void kmp(string s, int *l) {
	l[1] = 0;
	for(int i = 2 ; i <= s.length() ; i++) {
		int k = i - 1;
		while(s[l[k]] != s[i - 1] && k > 0)
			k = l[k];
		l[i] = (s[l[k]] == s[i - 1]) ? l[k] + 1 : 0;
	}
}

int main() {
	string s;
	cin >> s;
	int l[100];
	kmp(s, l);
	copy(l, l + s.length() + 1, ostream_iterator<int>(cout, " "));
	cout << endl;
}
