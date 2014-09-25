#include <iostream>
#include <tuple>
using namespace std;

const int inf = 40000;
const int log_inf = 17;

void suffix_tree(string s, int p[log_inf][inf], int &k) {
	int N = s.length();
	for(int i = 0 ; i < N ; i++)
		p[0][i] = s[i] - 'a';
	// copy(p[0], p[0] + N, ostream_iterator<int>(cout, " "));
	// cout << endl;
	tuple<int, int, int> v[inf];
	k = 0;
	for(int shift = 1 ; shift >> 1 < N ; shift <<= 1) {
		k++;
		for(int i = 0 ; i < N ; i++)
			v[i] = make_tuple(p[k - 1][i], (i + shift < N) ? p[k - 1][i + shift] : -1, i);
		sort(v, v + N);
		for(int i = 0 ; i < N ; i++)
			p[k][get<2>(v[i])] = (i > 0 && get<0>(v[i]) == get<0>(v[i - 1])
				&& get<1>(v[i]) == get<1>(v[i - 1])) ? p[k][get<2>(v[i - 1])] : i;
		// copy(p[k], p[k] + N, ostream_iterator<int>(cout, " "));
		// cout << endl;
	}
}

void lcp(int x, int y) {
	
}

int main() {
	string s;
	cin >> s;
	int k, p[log_inf][inf];
	suffix_tree(s, p, k);
	int w[inf];
	for(int i = 0 ; i < s.length() ; i++)
		w[p[k][i]] = i;
	for(int i = 0 ; i < s.length() ; i++)
		cout << w[i] << " ";
	cout << endl;
	for(int i = 0 ; i < s.length() ; i++)
		cout << s.substr(w[i]) << endl;
}
