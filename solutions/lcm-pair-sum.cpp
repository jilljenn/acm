#include <iostream>
using namespace std;

const long long LIMIT = 1000000007;

void extended_gcd(long long a, long long b, long long &lastx, long long &lasty){
	long long q;
   	long long x = 0;
	lastx=1;
    	long long y=1;
	lasty=0;
	while(b){
		q=a/b;
		long long tmp=a;
		a=b;
		b=tmp%b;

		tmp=x;
		x=lastx-q*x;
		lastx=tmp;

		tmp=y;
		y=lasty-q*y;
		lasty=tmp;
	}
}

long long inv(long long a, long long b){
	long long u, v;
	extended_gcd(a, b, u, v);
	return u;
}

long long powmod(long long a, long long k, long long n) {
	return (k == 0) ? 1 : (a * powmod(a, k - 1, n) % n);
}

int main() {
	long long T, C, p[15], a[15];
	// std:://cout << (inv(234763, 1000000007) * 234763ll) % 1000000007 << "\n";
	cin >> T;
	for(long long i = 1 ; i <= T ; i++) {
		cin >> C;
		long long N = 1;
		long long prod = 1;
		for(long long j = 0 ; j < C ; j++) {
			cin >> p[j];
			cin >> a[j];
			N = (N * powmod(p[j], a[j], LIMIT)) % LIMIT;
		}
		for(long long k = 0 ; k < C ; k++)
			prod = (prod * ((powmod(p[k], a[k], LIMIT) * (a[k] + 1)) % LIMIT + ((powmod(p[k], a[k], LIMIT) - 1) * (inv(p[k] - 1, LIMIT))) % LIMIT)) % LIMIT;
		cout << "Case " << i << ": " << ((prod + N) % LIMIT + LIMIT) % LIMIT << endl;
	}
}
