/* ACM 2007 3n+1 - c.durr
 * 
 * la fameuse fonction x -> x/2 si x est pair et x->3x+1 sinon.
 * l'ordre de x est le plus petit nombre de fois qu'il faut
 * l'appliquer pour obtenir 1.  le but est d'afficher l'ordre maximal
 * de tous les entiers d'un intervalle donnee.
 * 
 * Pour cela on met dans un tableau l'ordre : tab[x] sera l'ordre de x
 * Ainsi il ne faut pas finir la sequence jusqu'au 1 necessairement.

 * La difficulte ici est que les deux entiers lus i,j peuvent ne pas
 * etre dans l'ordre. Donc il faut trouver l'ordre maximal de x pour x
 * entre min(i,j) et max(i,j) inclus.
 */

#include <iostream>

using namespace std;

typedef unsigned long ulong;

const ulong MAX = 1000001L;
ulong  tab[MAX];
	
inline ulong f(ulong x) {return (x%2==0) ? x>>1 : 3*x+1; }
	
	
ulong order_rec(ulong x) {
   if (x<MAX && tab[x]!=0) 
      return tab[x];
	
   if (x<MAX)
     return tab[x]=1+order_rec(f(x));
   else 
     return 1+order_rec(f(x));
}

	
int main() {
  ulong a,b, m;
  // init the table
  for (a=0; a<MAX; a++)
    tab[a] = 0;
  tab[1] = 1;
  while ((cin>>a>>b)) {
    m = 0; // ordre maximum
    for (ulong i=min(a,b); i<=max(a,b); i++) {
      ulong oi = order_rec(i);
      if (oi>m) m=oi;
    }
    cout << a << " " << b <<" " << m << endl;
  }
  return 0;
}
