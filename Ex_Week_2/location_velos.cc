#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de dÈbut de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * Compl√©ter le code √  partir d'ici
   *****************************************************/

    if (debut<0 or debut>24 or fin<0 or fin>24) {
        cout << "Les heures doivent Ítre comprises entre 0 et 24 !" << endl;
    } else if (debut == fin) {
        cout << "Bizarre, vous níavez pas louÈ votre vÈlo bien longtemps !" << endl;
    } else if (debut > fin) {
        cout << "Bizarre, le dÈbut de la location est aprËs la fin ..." << endl;
    } else {
        int qlow(0);
        int qhigh(0);

        if (debut<7){
            if(fin<=7){
                qlow+=fin-debut;
            } else {
                qlow+=7-debut;
            }
        }

        if (fin>17){
            if(debut<=17){
                qlow+=fin-17;
            } else {
                qlow+=fin-debut;
            }
        }

        qhigh = fin-debut-qlow;

        cout << "Vous avez louÈ votre vÈlo pendant" << endl;
        if(qlow)
            cout << qlow << " heure(s) au tarif horaire de " <<
                "1" << " franc(s)" << endl;
        if(qhigh)
            cout << qhigh << " heure(s) au tarif horaire de " <<
                "2" << " franc(s)" << endl;

        cout << "Le montant total ‡ payer est de "
             << qlow+2*qhigh << " franc(s)." << endl;
    }







  /*******************************************
   * Ne rien modifier apr√®s cette ligne.
   *******************************************/

  return 0;
}
