#include <iostream>
using namespace std;

int main()
{
  int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/
    for(int i(debut); i<=fin; ++i){
        int aux(i);
        int counter(0);
        do {
            if (aux%3==0){
                aux+=4;
            } else if (aux%4==0){
                aux/=2;
            } else {
                aux-=1;
            }
            counter+=1;
        } while(aux!=0);
        cout << i << " -> " << counter << endl;
    }
  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
